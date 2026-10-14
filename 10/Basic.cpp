//Вариант 13
#include <iostream>
using std::cout, std::endl;
#include <format>
using std::format;

void swap(int& a, int& b)
{
    auto temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a{10};
    int b{129};

    int& alink = a;
    int& blink = b;

    cout << format("a = {}, b = {}\n", a, b);

    swap(alink, blink);

    cout << format("a = {}, b = {}\n", a, b);

    return 0;
}