#include <iostream>
#include "Brute.h"
/*
* Пример: добавим все числа от 0 до 9 и выведем все пароли размером от 1 символа до 3-х включительно
*/
using namespace std;

int main()
{
    Brute force;
    //force.SetList('0', '9');
    force.SetList('a', 'z');
    //force.SetList('A', 'Z');
    //force.SetList("!@#$%^&*()-_+={}[]?");
    force.SetMaxLenOfPassword(2);
    int const len = force.GetAmount();
    for (unsigned long long i = 0; i < len; ++i)
    {
        std::cout << i + 1 << "\t" << force.GetPasswords() << std::endl;
    }

    return 0;
}
