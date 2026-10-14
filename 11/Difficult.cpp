//Вариант 13
#include <iostream>
using std::cout, std::endl;
#include <format>
using std::format;

int main()
{
    int a{37654};
    int* ptr1 = &a;
    int* ptr2 = ptr1;

    cout << "Значение переменной a: " << a << endl;
    cout << "Значение указателя на a: " << ptr1 << endl;
    cout << "Значение указателя на указатель: " << ptr2 << endl;

    return 0;
}