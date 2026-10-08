#include <iostream>
using std::cout, std::cin, std::endl, std::stod;
#include <exception>
using std::out_of_range, std::invalid_argument;
#include <format>
using std::format;
#include <string>
using std::string, std::getline;

const string ERROR_MSG = "\nНеверный аргумент";

static bool falseout(string value)
{
    cout << format("{}: {}", ERROR_MSG, value) << endl;
    return false;
}

//Можно ли привести string к double
static bool is_double(string value)
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
    catch(const out_of_range& e)
    {
        return falseout(value);
    }

    if (pos != value.size())
    {
        return falseout(value);
    }
            
    return true;
};


double quadratic(double a, double b, double c, double x)
{
    return a*x*x + b*x + c;
}

//Можно ли привести string к double
static bool is_double(string value)
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
    catch(const out_of_range& e)
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
    bool temp = false;
    string input;

    while (not temp)
    {
        cout << "Введите число a\t";
        getline(cin, input);
        temp = is_double(input);
    }
    int a = stod(input);
    temp = false;

    while (not temp)
    {
        cout << "Введите число b\t";
        getline(cin, input);
        temp = is_double(input);
    }
    int b = stod(input);
    temp = false;

    while (not temp)
    {
        cout << "Введите число c\t";
        getline(cin, input);
        temp = is_double(input);
    }
    int c = stod(input);
    temp = false;

    while (not temp)
    {
        cout << "Введите число x\t";
        getline(cin, input);
        temp = is_double(input);
    }
    int x = stod(input);

    cout << format("Результат: {}\n\n", quadratic(a,b,c,x));

    return 0;
}