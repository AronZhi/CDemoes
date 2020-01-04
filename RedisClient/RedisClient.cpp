#include "RedisClient.h"

RedisClient::RedisClient()
    : m_redisClient(NULL), m_cmd(NULL), m_result(REDIS_RESULT_UNKNOW), m_errMsg("")
{

}

RedisClient::~RedisClient()
{
    Close();
}

void RedisClient::Close()
{
    if (m_cmd)
    {
        delete m_cmd;
        m_cmd = NULL;
    }

    if (m_redisClient)
    {
        delete m_redisClient;
        m_redisClient = NULL;
    }    
}

bool RedisClient::Connect(const std::string& host, const std::string& password, int conn_timeout, int rw_timeout)
{
    if (host.empty())
    {
        return false;
    }

    std::list<std::string> hosts;
    hosts.push_back(host);
    return Connect(hosts, password, conn_timeout, rw_timeout);
}

bool RedisClient::Connect(const std::list<std::string>& hosts, const std::string& password, int conn_timeout, int rw_timeout)
{
    if (hosts.empty())
    {
        return false;
    }

    if (m_redisClient || m_cmd)
    {
        Close();
    }

    acl::acl_cpp_init();
    
#ifdef REDIS_LOG
	acl::log::stdout_open(true);
#endif

    std::string addresslist;
    int cout = hosts.size();
    int i = 1;
    for (const auto& host : hosts)
    {
        addresslist = host;
        
        if (i != cout)
        {
            addresslist += ";";
        }
    }

    m_redisClient = new acl::redis_client_cluster();
	
    m_redisClient->set_retry_inter(1);
	m_redisClient->set_redirect_max(10);
	m_redisClient->set_redirect_sleep(500);
    m_redisClient->init("127.0.0.1:6379", addresslist.c_str(), 0, conn_timeout, rw_timeout);
    if (!password.empty())
    {
        m_redisClient->set_password("default", password.c_str());
    }

    m_cmd = new acl::redis();
    m_cmd->set_cluster(m_redisClient, 500);

    return true;
}

bool RedisClient::_IsValid()
{
    if (NULL == m_cmd)
    {
        m_result = REDIS_RESULT_FAIL;
        m_errMsg = "not init";
        return false;
    }

    return true;
}

void RedisClient::_GetErrorMsg()
{
    m_result = REDIS_RESULT_UNKNOW;
    m_errMsg = "";

    const acl::redis_result* ret = m_cmd->get_result();
    if (ret->get_type() == acl::REDIS_RESULT_ERROR)
    {
        m_result = REDIS_RESULT_FAIL;
        m_errMsg = ret->get_error();
    }
}

void RedisClient::_HandleSuccess()
{
    m_result = REDIS_RESULT_SUCCESS;
}

bool RedisClient::Ping()
{
    if (!_IsValid())
    {
        return false;
    }

    m_cmd->clear();
    bool ret = m_cmd->ping();
    if (ret)
    {
        _HandleSuccess();
    }
    else
    {
        _GetErrorMsg();
    }
    
    return ret;
}

std::string RedisClient::Get(const std::string& key)
{
    if (!_IsValid())
    {
        return "";
    }

    m_cmd->clear();
    const acl::redis_result* ret = m_cmd->get(key.c_str());
    if (ret->get_type() == acl::REDIS_RESULT_STRING)
    {
        acl::string value;
        ret->to_string(value);
        _HandleSuccess();
        return value.c_str();
    }
    else
    {
        _GetErrorMsg();
        return "";
    }
}

bool RedisClient::Set(const std::string& key, const std::string& value)
{
    if (!_IsValid())
    {
        return false;
    }

    m_cmd->clear();
    if (m_cmd->set(key.c_str(), value.c_str()))
    {
        _HandleSuccess();
        return true;
    }
    else
    {
        _GetErrorMsg();
        return false;
    }   
}

int RedisClient::Del(const std::string& key)
{
    if (!_IsValid())
    {
        return false;
    }

    m_cmd->clear();
    int ret = m_cmd->del_one(key.c_str());
    if (0 == ret)
    {
        _GetErrorMsg();
    }
    else
    {
        _HandleSuccess();
    }
    
    return ret;
}