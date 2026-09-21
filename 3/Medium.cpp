//Вариант 13

#include <iostream>
#include <format>
#include <string>

using std::cout, std::to_string, std::getline, std::format, std::cin, std::endl, std::string, std::invalid_argument, std::stoul;

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

//Названия и описания дней
string day_info(unsigned num)
{
    if (num == 1)
    {
        return "Понедельник. Рабочий день.";
    }
    else if (num == 2)
    {
        return "Вторник. Рабочий день.";
    }
    else if (num == 3)
    {
        return "Среда. Рабочий день.";
    }
    else if (num == 4)
    {
        return "Четверг. Рабочий день.";
    }
    else if (num == 5)
    {
        return "Пятница. Рабочий день.";
    }
    else if (num == 6)
    {
        return "Суббота. Выходной день.";
    }
    else if (num == 7)
    {
        return "Воскресенье. Выходной день";
    }
    return "Если вы это видите, то значит я что-то сделал не так";
}

int main()
{
    string input;
    double num;
    bool temp = false;

    while (not temp)
    {
        cout << "Введите номер дня недели\t";
        getline(cin, input);
        temp = is_unsigned(input);
        if (temp)
        {
            temp = is_in_range(stoul(input), 1, 7);
        }
    }
    num = stoul(input);

    cout << day_info(num) << endl;

}