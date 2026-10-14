//Вариант 13
#include <iostream>
using std::cout;
#include <format>
using std::format;

void square(int* ptr);

int main()
{
    int num = 10;

    cout << format("Изначальное число: {}\n", num);

    square(&num);

    cout << format("Число в квадрате: {}\n\n", num);

    return 0;
}

void square(int* ptr)
{
    *ptr *= *ptr;
}