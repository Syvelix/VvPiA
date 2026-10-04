#include <iostream>
using std::cin, std::cout, std::endl, std::stoul;
#include <format>
using std::format;
#include <string>
using std::u16string, std::string, std::getline;
#include <exception>
using std::out_of_range, std::invalid_argument;

const string abc{"abcdefghijklmnopqrstuvwxyz"};
const string ABC{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

const string ERROR_MSG = "\nНеверный аргумент";

static bool falseout(string value)
{
    cout << format("{}: {}", ERROR_MSG, value) << endl;
    return false;
}

string to_ceasar(string input, unsigned step)
{
    string ceasered{""};

    for (char& l : input)
    {
        if (abc.find(l) != abc.npos)
        {
            ceasered += abc[(abc.find(l) + step) % abc.size()];
        }
        else if (ABC.find(l) != ABC.npos)
        {
            ceasered += ABC[(ABC.find(l) + step) % ABC.size()];
        }
        else
        {
            ceasered += l;
        }
    }
    return ceasered;
}

//Можно ли привести string к unsigned
static bool is_unsigned(string value)
{
    if (value[0] == '-' || value == "0")
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

int main()
{
    string line{""};
    string step{""};

    cout << "Введите строку для шифрования (только латынь, остальное будет проигнорированно!)\t";
    getline(cin, line);

    bool temp = false;
    while (not temp)
    {
        cout << "Введите положительный шаг\t";
        getline(cin, step);
        temp = is_unsigned(step);
    }

    cout << format("Зашифрованная строка:\n{}\n\n", to_ceasar(line, stoul(step)));

    return 0;
}