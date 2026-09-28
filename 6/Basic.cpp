#include <iostream>
using std::cin, std::cout, std::endl, std::getline, std::stoi;
#include <string>
using std::string;
#include <format>
using std::format;
#include <exception>
using std::invalid_argument, std::out_of_range;
using std::find, std::begin, std::end;

const string WRONG_ARGUMENT = "Неверное значение";

const int SIZE = 5;

//Сообщение об ошибке + false в ретёрне
bool falseout(auto input)
{
    cout << format("{} : {}", WRONG_ARGUMENT, input) << endl;
    return false;
}

//Можно ли привести string к int
bool is_int(string value)
{
    size_t pos;

    try
    {
        stoi(value, &pos);
    }
    catch(const invalid_argument& e)
    {
        return falseout(value);
    }
    catch (const out_of_range& e)
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
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        bool temp = false;
        string value;
        while (not temp)
        {
            cout << format("Введите значение №{}\t", i+1);
            getline(cin, value);
            temp = is_int(value);
            
            //Проверка на ноль
            if (value == "0")
            {
                string proceed;
                string testarr [4] = {"Y", "y", "N", "n"};
                while (find(begin(testarr), end(testarr), proceed) == end(testarr))
                {
                    cout << "Внимание: введён ноль. Произведение чисел в массиве будет равно нулю. Продолжить? (Y/N)\t";
                    getline(cin, proceed);
                }
                temp = (proceed == "Y" || proceed == "y");
            }
        }
        arr[i] = stoi(value);
    }

    int mul = 1;
    for (int i = 0; i < SIZE; i++)
    {
        mul *= arr[i];
    }

    cout << format("Произведение от списка элементов: {}", mul) << endl << endl;
    return 0;
}