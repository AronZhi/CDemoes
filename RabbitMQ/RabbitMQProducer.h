#ifndef RABBITMQ_PRODUCER
#define RABBITMQ_PRODUCER

#include <string>
#include "../../CLib/rabbitmq-c/amqp.h"

class RabbitMQProducer
{
public:
    RabbitMQProducer();
    ~RabbitMQProducer();
    bool Close();
    bool Connect(const std::string& userName, const std::string& password, const std::string& vhost, const std::string& host, int port);

private:
    amqp_connection_state_t m_connectionState; /* 这是一个指针 */
}

#endif // RABBITMQ_PRODUCER