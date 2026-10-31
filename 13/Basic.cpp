//Вариант 13

#include <iostream>
using std::cout, std::cin, std::endl, std::stoi;
#include <string>
using std::string, std::getline;
#include <format>
using std::format;
#include <exception>
using std::invalid_argument, std::out_of_range;

const string ERROR_MSG = "\nНеверный аргумент";

bool falseout(string value)
{
    cout << format("{}: {}", ERROR_MSG, value) << endl;
    return false;
}

bool is_int(string value)
{

    size_t pos;
    try
    {
        stoi(value, &pos);
    }
    catch (const invalid_argument& e)
    {
        return falseout(value);
    }
    catch(const out_of_range& e)
    {
        return falseout(value);
    }

    if (pos != value.size())
    {
        return falseout(value);
    }
            
    return true;
}

class Date
{
    int day = 1;

    public:
        void set(int newday = 0)
        {
            day = (newday == 0 ? day : newday);
        }
        void print()
        {
            cout << format("Дата: {}\n\n", day);
        }
        void nextDay()
        {
            day += 1;
        }
};

int main()
{
    Date date;

    cout << "Изначальная дата\n";
    date.print();

    bool temp = false;
    string input;
    while (not temp)
    {
        cout << "Введите новую дату\t";
        getline(cin, input);
        temp = is_int(input);
    }
    int newdate = stoi(input);

    date.set(newdate);
    date.print();

    date.nextDay();
    cout << "Дата после nextDay\n";
    date.print();

    return 0;
}