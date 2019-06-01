#ifndef CLIENT_SOCKET
#define CLIENT_SOCKET

#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

class ClientSocket : public boost::enable_shared_from_this<ClientSocket>
{
public:
    ClientSocket(boost::asio::io_service& io);
    virtual ~ClientSocket();

    int8_t Connect(const char* address, uint16_t port);

private:
    void _HandleConnect(const boost::system::error_code& e);
    void _HandleRead(const boost::system::error_code& e);

private:
    boost::asio::io_service&            _io_service;
    boost::asio::ip::tcp::socket        _socket;
    boost::asio::ip::tcp::endpoint      _remote;
    char                                _buf[1024];
};

typedef boost::shared_ptr<ClientSocket> ClientSocketPtr;

#endif // CLIENT_SOCKET