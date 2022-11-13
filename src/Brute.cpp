#include "Brute.h"
#include <iostream>
#include <cmath>
#include <algorithm>

void Brute::Update()
{
    //size_t len = GetListSize();
    UpdateProgresion();
    size_t len = m_progresion.m_sz;

    for (size_t i = 0; i < len; )
    {
        char cur = m_password[i];
        if (i == len - 1)
        {
            if (m_password.size() < len)
            {
                m_password.push_back(m_first);
            }
            else
            {
                auto it = std::find(m_list.begin(), m_list.end(), cur);
                m_password[i] = m_list[it - m_list.begin() + 1];
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
                auto it = std::find(m_list.begin(), m_list.end(), cur);
                m_password[i] = m_list[it - m_list.begin() + 1];
                break;
            }
        }

    }
}

size_t Brute::GetListSize() const
{
    return m_list.size();
}

void Brute::UpdateProgresion()
{
    if (m_index < m_progresion.m_Sum)
    {
        return;
    }
    m_progresion.m_cur *= m_progresion.m_n;
    m_progresion.m_Sum += m_progresion.m_cur;
    ++m_progresion.m_sz;
}

void Brute::SetFirstAndLast()
{
    m_first = m_list[0];
    m_last = m_list[m_list.size() - 1];
}

void Brute::SetProgresion()
{
    m_progresion.m_n = m_list.size();
    m_progresion.m_cur = 1;
    m_progresion.m_sz = 0;
    m_progresion.m_Sum = 0;
}

void Brute::SetList(char from, char to)
{
    for (char ch = from; ch <= to; ++ch)
    {
        this->m_list.push_back(ch);
    }
    SetFirstAndLast();
    SetProgresion();
}

void Brute::SetList(std::string const& list)
{
    for (auto const& ch : list)
    {
        this->m_list.push_back(ch);
    }
    SetFirstAndLast();
    SetProgresion();
}

void Brute::SetMaxLenOfPassword(size_t len)
{
    size_t cur = 1;
    size_t n = GetListSize();
    for (size_t i = 0; i < len; i++)
    {
        cur *= n;
        m_amount += cur;
    }
}

std::string& Brute::GetPasswords()
{
    Update();
    ++this->m_index;
    return this->m_password;
}

size_t Brute::GetAmount() const
{
    return m_amount;
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

Brute::~Brute()
{
    //dtor
}
