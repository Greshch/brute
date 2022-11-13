#include <iostream>
#include "Brute.h"
/*
* Пример: добавим все числа от 0 до 9 и выведем все пароли размером от 1 символа до 3-х включительно
*/
using namespace std;

int main()
{
    Brute force;
    force.SetList('0', '1');
    //force.SetList('a', 'z');
    //force.SetList('A', 'Z');
    //force.SetList("!@#$%^&*()-_+={}[]?");
    force.SetMaxLenOfPassword(2);
    int const len = force.GetAmount();
    std::vector<std::string> buffer;
    bool next = true;
    while (next)
    {
        next = force.GetPasswordBatch(buffer, 4);
        buffer.clear();
    }

    return 0;
}
