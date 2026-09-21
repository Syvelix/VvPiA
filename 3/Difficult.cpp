//Вариант 13

#include <iostream>
#include <cmath>
#include <format>
#include <string>

using std::cout, std::to_string, std::getline, std::format, std::cin, std::endl, std::string, std::invalid_argument, std::stoul, std::stod;

//Для округления копеек
using std::round;

const string ERROR_MSG = "\nНеверный аргумент";

//Красивый вывод false
bool falseout(string value)
{
    cout << format("{}: {}", ERROR_MSG, value) << endl;
    return false;
}

//Можно ли привести string к unsigned
bool is_unsigned(string value)
{

    if (value[0] == '-')
    {
        return falseout(value);
    }

    size_t pos;
        try
            {
                stoul(value, &pos);
            }
            catch (const invalid_argument& e)
            {
                return falseout(value);
            }

            if (pos != value.size())
            {
                return falseout(value);
            }
            
            return true;
};

//Проверка входит ли число в диапозон (только для unsigned)
bool is_in_range(unsigned value, unsigned min, unsigned max)
{
    if (value >= min and value <= max)
    {
        return true;
    }
    return falseout(to_string(value));
}

//Можно ли привести string к double
bool is_double(string value)
{

    size_t pos;
        try
            {
                stod(value, &pos);
            }
            catch (const invalid_argument& e)
            {
                return falseout(value);
            }

            if (pos != value.size())
            {
                return falseout(value);
            }
            
            return true;
};

//Расчёт цены доставки
double summ(double dist, double weight, bool dilivery_type)
{
    //Формула из задания
    double result = 50 + 10 * dist + 20 * weight;
    return (dilivery_type == 0) ? result : result * 1.5;
    
}

int main()
{
    string input;
    double dist;
    double weight;
    bool dilivery_type;
    bool temp = false;

    while (not temp)
    {
        cout << "Введите расстояние доставки в км\t";
        getline(cin, input);
        temp = is_double(input);
        if (temp)
        {
            temp = is_in_range(stod(input), 1, INT32_MAX);
        }
    }
    dist = stod(input);

    temp = false;
    
    while (not temp)
    {
        cout << "Введите вес посылки в кг\t";
        getline(cin, input);
        temp = is_double(input);
        if (temp)
        {
            temp = is_in_range(stod(input), 1, INT32_MAX);
        }
    }
    weight = stod(input);

    temp = false;

    while (not temp)
    {
        cout << "Введите тип доставки.\n0. Обычная\n1. Быстрая\t";
        getline(cin, input);
        temp = is_unsigned(input);
        if (temp)
        {
            temp = is_in_range(stoul(input), 0, 1);
        }
    }
    dilivery_type = stoul(input);

    cout << format("Стоимость доставки - {}р\n", round(summ(dist, weight, dilivery_type)));

}