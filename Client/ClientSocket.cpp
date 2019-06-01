#include "ClientSocket.h"

#include <iostream>
#include <boost/bind.hpp>

ClientSocket::ClientSocket(boost::asio::io_service& io)
    :_io_service(io), _socket(io)
{

}

ClientSocket::~ClientSocket()
{

}

int8_t ClientSocket::Connect(const char* address, uint16_t port)
{
    if (port <= 0)
        return -1;
    
    char strPort[65] = {0};
    sprintf(strPort, "%u", port);
    boost::asio::ip::tcp::resolver::query queryEndpoints(address,strPort);

    boost::asio::ip::tcp::resolver resolver(_io_service);
    boost::system::error_code ec;
    boost::asio::ip::tcp::resolver::iterator it = resolver.resolve(queryEndpoints, ec);
    if (!ec)
        _remote = *it;

    _socket.async_connect(_remote, boost::bind(&ClientSocket::_HandleConnect, 
        shared_from_this(), boost::asio::placeholders::error));

    return 0;
}

void ClientSocket::_HandleConnect(const boost::system::error_code& e)
{
    if (e)
    {
        _socket.close();
        return;
    }

    memset(_buf, sizeof(_buf), 0);
    boost::asio::async_read(_socket, boost::asio::buffer(_buf), 
        boost::bind(&ClientSocket::_HandleRead, shared_from_this(), boost::asio::placeholders::error));
}

void ClientSocket::_HandleRead(const boost::system::error_code& e)
{
    std::cout << _buf << std::endl;

    memset(_buf, sizeof(_buf), 0);
    boost::asio::async_read(_socket, boost::asio::buffer(_buf), 
        boost::bind(&ClientSocket::_HandleRead, shared_from_this(), boost::asio::placeholders::error));
}