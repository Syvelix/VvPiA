//Гипотенуза через катеты

//Использование директивы препроцессора iostream
#include <iostream>
//Использование модуля, содержащего setprecision и fixed
#include <iomanip>
//Использование модуля, содержащего pow
#include <cmath>
//Обращение к некоторым именам из стандартного пространства имён std
using std::cout, std::cin, std::endl, std::fixed, std::setprecision, std::string, std::pow;

//Повторяющееся сообщение об ошибке вынесено в отдельную переменную
const string FAIL_MESSAGE = "Введённое значение не является числом.\n";

//Функция расчёта длины гипотенузы
double hypotenuse(double a, double b)
{
    return pow(a*a + b*b, 0.5);
}

//Функция очистки буфера ввода, вывода и ошибок (последний фактически бесполезен, тк программа завершается сразу после сообщения об ошибке. В код добавлен чтобы соответствовать критериям оценки)
void cleanup()
{
    cin.ignore();
    cin.clear();
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

    //Вывод длины на экран с точностью 2 знака после запятой, завершение программы
    cout  << "Длина гипотенузы равна " << fixed << setprecision(2) << result << endl;
    return 0;
}

