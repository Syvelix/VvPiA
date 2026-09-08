//Гипотенуза через катеты

//Использование базовой директивы препроцессора
#include <iostream>
//Использование модуля, содержащего setprecision
#include <iomanip>
//Использование модуля, содержащего pow
#include <cmath>
//Обращение к некоторым именам из стандартного пространства имён std
using std::cout, std::cin, std::setprecision, std::string, std::pow;

//Повторяющееся сообщение об ошибке вынесено в отдельную переменную
const string FAIL_MESSAGE = "Введённое значение не является числом.";

//Функция расчёта длины гипотенузы
double hypotenuse(double a, double b)
{
    return pow(a*a + b*b, 0.5);
}

//Функция очистки буфера ошибок и вывода
void cleanup()
{
    cin.clear();
    cin.ignore();
    cout.flush();
}

//Точка входа
int main()
{
    //Катеты a и b
    double side_a;
    double side_b;

    //Получение длины катета a, проверка ошибок
    cout << "Введите длину катета a\t";
    cin >> side_a;
    if (cin.fail())
    {
        cout << FAIL_MESSAGE;
        return 1;
    }
    //Очистка
    cleanup();

    //Получение длины катета b, проверка ошибок
    cout << "Введите длину катета b\t";
    cin >> side_b;
    if (cin.fail())
    {
        cout << FAIL_MESSAGE;
        return 1;
    }
    //Очистка
    cleanup();

    //Расчёт длины гипотенузы
    double result = hypotenuse(side_a, side_b);

    //Вывод длины на экран, завершение программы
    cout  << "Длина гипотенузы равна " << setprecision(2) << result;
    return 0;
}

