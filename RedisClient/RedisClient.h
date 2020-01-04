#ifndef REDIS_CLIENT_H
#define REDIS_CLIENT_H

#include <string>
#include <list>
#include <map>
#include <acl_cpp/lib_acl.hpp>

enum RedisResult
{
    REDIS_RESULT_UNKNOW,
    REDIS_RESULT_SUCCESS,
    REDIS_RESULT_FAIL
};

class RedisClient
{
public:
    RedisClient();
    virtual ~RedisClient();
    
    void Close();
    bool Connect(const std::string& host, const std::string& password, int conn_timeout = 10, int rw_timeout = 10);
    bool Connect(const std::list<std::string>& hosts, const std::string& password, int conn_timeout = 10, int rw_timeout = 10);

    inline RedisResult GetResultType() { return m_result; }
    inline const std::string& GetErrorMsg() { return m_errMsg; }
    
    bool Ping();
    
    int Del(const std::string& key);
    std::string Get(const std::string& key);
    bool Set(const std::string& key, const std::string& value);

private:
    bool _IsValid();
    void _GetErrorMsg();
    void _HandleSuccess();

private:
    acl::redis_client_cluster* m_redisClient;
    acl::redis* m_cmd;
    RedisResult m_result;
    std::string m_errMsg;
};

#endif // REDIS_CLIENT_H