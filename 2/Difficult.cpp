//Максимум и минимумл из трёх чисел

#include <iostream>
#include <cmath>
#include <format>

using std::cout, std::cin, std::max, std::min, std::endl, std::string, std::format;

const string FAIL_MESSAGE = "\nНеверный ввод\n";


void clear()
{
    cin.clear();
    cin.ignore();
    cout << endl;
}

//Функция запроса double
double get_double()
{
    double dbl;
    cout << "Введите первое число (double)\t";
    cin >> dbl;

    //Использование тернарника по заданию
    return cin.fail() ? (clear(), get_double()) : dbl;
}

//Функция запроса float
float get_float()
{
    float flt;
    cout << "Введите второе число (float)\t";
    cin >> flt;

    //Использование тернарника по заданию
    return cin.fail() ? (clear(), get_float()) : flt;
}

//Функция запроса int
int get_int()
{
    double dbl;
    cout << "Введите третье число (int)\t";
    cin >> dbl;

    //Использование тернарника по заданию
    return cin.fail() ? (clear(), get_int()) : dbl;
}

int main()
{
    //Три разных типа выбраны для наглядности
    double num_d;
    float num_f;
    int num_i;

    //Запрос чисел
    num_d = get_double();
    num_f = get_float();
    num_i = get_int();
    
    //num_i = INT32_MAX;
    //cout << "Целое число максимально\n";
    //cout << format("Приведение INT32_MAX к double: {} --> {}\n\n", num_i, static_cast<double>(num_i));

    //num_i = INT32_MIN;
    //cout << "Целое число минимально\n";
    //cout << format("Приведение INT32_MIN к double: {} --> {}\n\n", num_i, static_cast<double>(num_i));

    //Вывод максимума и минимума через соответствующие функции
    cout << format("\nМаксимальное из введённых чисел: {}\n", max({num_d, static_cast<double>(num_f), static_cast<double>(num_i)})) << endl;
    cout << format("Минимальное из введённых чисел: {}\n\n", min({num_d, static_cast<double>(num_f), static_cast<double>(num_i)})) << endl;

    //Демонстрация потери точности
    cout << format("Демонстрация потери точности через приведение float к int: {} --> {}\n\n", num_f, static_cast<int>(num_f));

    //Демонстрация усечения. Использовать когда нужно просто отбросить дробную часть
    cout << format("Усечение double: {} --> {}\n\n", num_d, static_cast<int>(num_d));
    //Демонстрация округления. Использовать при расчётах где допустимо округление в большую сторону
    //Явное приведение нужно тк round сам по себе возвращает не int
    cout << format("Округление double: {} --> {}\n\n", num_d, static_cast<int>((round(num_d))));

    return 1;
}