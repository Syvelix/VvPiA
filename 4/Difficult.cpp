//Вариант 13

#include <iostream>
#include <iomanip>
#include <format>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using std::cout, std::fixed, std::setprecision, std::find, std::stod, std::vector, std::to_string, std::invalid_argument, std::getline, std::endl, std::format, std::cin, std::string, std::stoul, std::pow;

const string ERROR_MSG = "\nНеверный аргумент";

const string MENU_MSG = "1. - Аннуитетный платёж\n2. - Дифференцированный платёж\n3. - Досрочное погашение\t";

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

//Аннуитетный платёж
double annual(unsigned summ, double percent, unsigned period)
{
    string input;

    //Перевод годового процента в месячный
    percent = percent / 100 / 12;

    //Формула ан. платежа
    return summ * percent / (1 - pow(1 + percent, - static_cast<double>(period)));
}

//Дифф. платёж
double different(unsigned summ, double percent, unsigned period)
{
    unsigned month;
    bool temp = false;
    string input;

    while (not temp)
    {
        cout << "Введите на каком месяце происходит платёж\t";
        getline(cin, input);
        temp = is_unsigned(input);
        if (temp)
        {
            temp = stoul(input) > 0;
        }
    }
    month = stoul(input);

    //Перевод годовой ставки в месячную
    percent = percent / (100 * 12);

    //Формула дифф. платежа за месяц month
    return (summ / period) + (summ - (month - 1) * summ / period) * percent;
} 

double get_result(char type)
{
    vector<char> available{'1', '2', '3'};
    //Проверка существования пункта меню. Фактически заменяет default в switch. Вынесено сюда, чтобы при неверном вводе программа завершалась сразу, а не запрашивала данные о кредите.
    if (find(available.begin(), available.end(), type) == available.end())
    {
        return -999;
    };

    unsigned summ;
    unsigned period;
    double percent;
    bool temp = false;
    string input;

    while (not temp)
    {
        cout << "Введите положительную сумму кредита\t";
        getline(cin, input);
        temp = is_unsigned(input);

        if (temp)
        {
            temp = stoul(input) > 0;
        }
    }
    summ = stoul(input);
    temp = false;

    while (not temp)
    {
        cout << "Введите положительную годовую ставку (допускаются дроби)\t";
        getline(cin, input);
        temp = is_double(input);
        if (temp)
        {
            temp = (stod(input) > 0);
        }
    }
    percent = stod(input);
    temp = false;

    while (not temp)
    {
        cout << "Введите положительный срок кредита в месяцах\t";
        getline(cin, input);
        temp = is_unsigned(input);
        if (temp)
        {
            temp = (stoul(input) > 0);
        }
    }
    period = stoul(input);


    switch (type)
    {
        case '1':
            return annual(summ, percent, period);
        case '2':
            return different(summ, percent, period);
        case '3':
            cout << "Сумма для досрочного погашения равна остатку по кредиту\n";
            return summ;
    }
}

int main()
{
    string input;
    bool temp;

    while (true)
    {
        cout << "Выберите операцию\n" << MENU_MSG;
        getline(cin, input);
        if (input.size() == 1)
        {
            break;
        }
        cout << "Неверный ввод\n";
    }
    double result = get_result(input[0]);

    if (result == -999)
    {
        cout << format("Нет такого пункта: {}\n", input[0]);
        return 1;
    }
    cout << fixed << setprecision(2);
    
    cout << "Cумма платежа: " <<  round(result*100) / 100 << "р";
    cout << "\n";
    
    return 0;
}