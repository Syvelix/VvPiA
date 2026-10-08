#include <iostream>
using std::cout, std::cin, std::endl, std::stoi;
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

//Можно ли привести string к int
static bool is_int(string value)
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

bool isEven(int n)
{
    return n % 2 == 0;
}

int main()
{
    bool temp = false;
    string input{""};

    while (not temp)
    {
        cout << "Введите число\t";
        getline(cin, input);
        temp = is_int(input);
    }

    isEven(stoi(input)) ? cout << format("{} - чётное", input) : cout << format("{} - нечётное", input);
    cout << "\n\n";

    return 0;
}