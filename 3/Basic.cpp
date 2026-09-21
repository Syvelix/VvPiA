//Вариант 13

#include <iostream>
#include <format>

using std::cout, std::getline, std::format, std::cin, std::endl, std::string, std::invalid_argument, std::stod;

const string ERROR_MSG = "\nНеверный аргумент";

//Красивый вывод false
bool falseout(string value)
{
    cout << format("{}: {}", ERROR_MSG, value) << endl;
    return false;
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

int main()
{
    string input;
    double num;
    bool temp = false;

    while (not temp)
    {
        cout << "Введите число\t";
        getline(cin, input);
        temp = is_double(input);
    }
    num = stod(input);

    if (num == 0)
    {
        cout << "Ноль\n";
        return 0;
    }
    cout << "Не ноль\n";
    return 0;
}