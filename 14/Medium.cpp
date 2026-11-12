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
    int day;

    public:
        Date()
        {
            cout << "Объект Date создан с параметром по умолчанию\n";
            day = 1;
        }
        Date(int day)
        {
            if (day > 31 or day <= 0)
            {
                cout << format("{} не является корректным числом месяца, устанавливаю значение по умолчанию\n", day);
                this->day = 1;
                return;
            }

            this->day = day;
            cout << format("Объект Date создан с параметром {}\n", day);
        }
        Date(const Date& other)
        {
            this->day = other.day;
            cout << format("Объект Date скопирован с параметром {}\n", day);
        }
        ~Date()
        {
            cout << "Объект уничтожен\n";
        }

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
    Date date(152);
    date.print();
    cout << endl;

    Date date2(15);
    date2.print();
    cout << endl;

    Date date2cp(date2);
    date2cp.print();
    cout << endl;
    
    return 0;
}