#include <iostream>
#include "RedisClient.h"

int main()
{
    RedisClient redis;
    redis.Connect("127.0.0.1:6379", "");
    if (redis.Ping())
    {
        std::cout << "Connect success" << std::endl;
    }
    else
    {
        std::cout << "Connect fail" << std::endl;
        redis.Close();
        return 0;
    }
    if (redis.Set("test", "666"))
    {
        std::string value = redis.Get("test");
        std::cout << value << std::endl;
        redis.Del("test");
    }
    redis.Close();
    return 0;
}