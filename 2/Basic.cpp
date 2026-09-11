//Разность двух чисел

#include <iostream>
using std::cout, std::cin;

int main()
{
    //Использую double для возможности ввода дробных чисел
    double a, b;
    cout << "Введите уменьшаемое\t";
    cin >> a;

    cout << "Введите вычитаемое\t";
    cin >> b;

    cout << a - b << "\n";
    return 0;

}