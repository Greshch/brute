#include "Brute.h"
#include <iostream>
#include <cmath>
#include <algorithm>

void Brute::Increment()
{
    /*
    char first = m_list[0];
    char elapse = m_list[m_list.size() - 1];
    */
    size_t len = GetSize();

    for (size_t i = 0; i < len; )
    {
        if (i == len - 1)
        {
            if (m_password.size() < len)
            {
                m_password.push_back(m_first);
            }
            else
            {
                char cur = m_password[i];
                auto it = std::find(m_list.begin(), m_list.end(), cur);
                cur = m_list[it - m_list.begin() + 1];
                m_password[i] = cur;
            }
            break;
        }
        else
        {
            if (m_password[i] == m_last)
            {
                m_password[i] = m_first;
                ++i;
            }
            else
            {
                char cur = m_password[i];
                auto it = std::find(m_list.begin(), m_list.end(), cur);
                cur = m_list[it - m_list.begin() + 1];
                m_password[i] = cur;
                break;
            }
        }

    }
}

size_t Brute::GetSize() const
{
    size_t n = m_list.size();
    size_t cur = 1;
    size_t sz = 1;
    size_t Sum = 0;
    for (; ;++sz)
    {
        cur *= n;
        Sum += cur;
        if (m_index < Sum)
        {
            return sz;
        }
    }
    return sz;
}

void Brute::SetFirstAndLast()
{
    m_first = m_list[0];
    m_last = m_list[m_list.size() - 1];
}

void Brute::SetList(char from, char to)
{
    for (char ch = from; ch <= to; ++ch)
    {
        this->m_list.push_back(ch);
    }
    SetFirstAndLast();
}

void Brute::SetList(std::string const& list)
{
    for (auto const& ch : list)
    {
        this->m_list.push_back(ch);
    }
    SetFirstAndLast();
}

std::string& Brute::GetPassword()
{
    Increment();
    ++this->m_index;
    return this->m_password;
}

size_t Brute::GetLength() const
{
    return m_list.size();
}

Brute::Brute() : Brute(Brute::s_length)
{
    //ctor
}

Brute::Brute(size_t buffer)
{
    this->m_password.reserve(buffer);
    this->m_list.reserve(buffer * 5);
}

void Brute::Reset()
{
    m_password.clear();
    m_list.clear();
    m_index = 0;
}

Brute::~Brute()
{
    //dtor
}
