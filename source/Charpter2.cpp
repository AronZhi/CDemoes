#include "Charpter2.h"

Charpter2::Charpter2(std::initializer_list<int> list)
{
    for (auto element : list)
    {
        m_data.push_back(element);
    }
}

void Charpter2::print()
{
    for (auto element : m_data)
    {
        std::cout << element << ',';
    }
    std::cout << std::endl;
}