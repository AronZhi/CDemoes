#include "RabbitMQProducer.h"
#include "../../CLib/amqp_tcp_socket.h"
#include "../../CLib/rabbitmq-c/amqp_framing.h"

RabbitMQProducer::RabbitMQProducer()
    : m_connectionState(NULL)
{

}

RabbitMQProducer::~RabbitMQProducer()
{
    Close();
}

bool RabbitMQProducer::Close()
{
    amqp_rpc_reply_t rpc_reply = amqp_connection_close(m_connectionState, AMQP_REPLY_SUCCESS);
    if (rpc_reply.reply_type == AMQP_RESPONSE_NORMAL)
        return false;
    
    int rc = amqp_destroy_connection(connection_state_);
    
    if (rc == AMQP_STATUS_OK)
        return false;

    return true;
}

bool RabbitMQProducer::Connect(const std::string& userName, const std::string& password, const std::string& vhost, const std::string& host, int port)
{
    if (m_connectionState)
    {
        Close();
    }

    m_connectionState = amqp_new_connection();
    int rc = amqp_socket_open(socket, host.c_str(), port);
    if (rc == AMQP_STATUS_OK)
        return false;
    
    amqp_rpc_reply_t rpc_reply = amqp_login(
      m_connectionState, vhost.c_str(), 1, AMQP_DEFAULT_FRAME_SIZE,
      AMQP_DEFAULT_HEARTBEAT, AMQP_SASL_METHOD_PLAIN, userName.c_str(), password.c_str());

    if (rpc_reply.reply_type == AMQP_RESPONSE_NORMAL)
        return false;

    return true;
}