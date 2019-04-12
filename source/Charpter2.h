#ifndef CHARPTER_2
#define CHARPTER_2

#include <initializer_list>
#include <vector>
#include <iostream>

class Charpter2
{
    public:
    Charpter2(std::initializer_list<int> list);

    void print();

    private:
    std::vector<int>  m_data;
};

#endif // CHARPTER_2