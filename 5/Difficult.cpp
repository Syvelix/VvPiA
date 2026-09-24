//Вариант 13

//Вычисление числа π через ряд Лейбница: π/4 = 1 - 1/3 + 1/5- 1/7 + ... с заданной точностью.

#include <iostream>
#include <string>
#include <format>
#include <iomanip>
#include <cmath>

using std::cout, std::fixed, std::fabs, std::setprecision, std::format, std::invalid_argument, std::getline, std::cin, std::endl, std::stold, std::string;

const string WRONG_ARGUMENT = "Неверное значение";

//Сообщение об ошибке + false в ретёрне
bool falseout(auto input)
{
    cout << format("{} : {}", WRONG_ARGUMENT, input) << endl;
    return false;
}

//Проверка на возможность перевода в long double
bool is_long_double(string input)
{
    size_t pos;
    try
    {
        stold(input, &pos);
    }
    catch(const invalid_argument& e)
    {
        return falseout(input);
    }

    if (pos != input.size())
    {
        return falseout(input);
    }
    
    return true;
}

//Вынес безопасное получение double в отдельную функцию
long double safedouble(string message = "Введите дробное число")
{
    string input;
    bool temp = false;
    while (not temp)
    {
        cout << format("{}\t", message);
        getline(cin, input);
        temp = is_long_double(input);
    }
    return stold(input);
}

//Рекуррентная формула для ряда Лейбница
long double recursi(long double curr, int n)
{
    return -curr * (2*n + 1) / (2*n + 3);
}

//Основной цикл
//long double для более высокой точности
long double loopcycle(long double eps)
{
    long double sum = 1;
    long double curr = 1;
    int n = 0;
    while (fabs(curr) > eps)
    {
        //Использовал format вместо setw, тк во втором нет смысла, просто код длинее
        cout << format("n = {}    |    x = {}\n", n, curr);
        
        curr = recursi(curr, n);
        sum += curr;
        n++;
    }
    cout << format("\nЧисло итераций - {}\n", n);
    return sum;
}

int main()
{
    long double eps{0};

    eps = safedouble("Введите точность для вычисления суммы ряда Лейбница (eps > 0)");
    if (eps <= 0)
    {
        cout << "T_T\n";
        return 1;
    }

    long double pi = loopcycle(eps) * 4;


    cout << fixed << setprecision(16);
    cout << "При eps = " <<  eps << ", ";
    cout << fixed << setprecision(80);
    cout << "pi = "  << pi << endl << endl;

    return 0;
}