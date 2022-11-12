#include <iostream>
#include "Brute.h"
/*
* Пример: добавим все числа от 0 до 9 и выведем все пароли размером от 1 символа до 3-х включительно
*/
using namespace std;

int main()
{
    Brute force;
    force.SetList('0', '9');
    //force.SetList('a', 'z');
    //force.SetList('A', 'Z');
    //force.SetList("!@#$%^&*()-_+={}[]?");
    const size_t len = force.GetLength();
    for (unsigned long long i = 0; i < len + len * len  + len * len * len + len * len * len * len; ++i)
    {
        std::cout << i + 1 << "\t" << force.GetPassword() << std::endl;
    }
    force.Reset();

    return 0;
}
