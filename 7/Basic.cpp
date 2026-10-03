#include <iostream>
using std::cin, std::cout, std::getline, std::stoi, std::endl;
#include <format>
using std::format;
#include <string>
using std::string;
#include <exception>
using std::out_of_range, std::invalid_argument;

const string WRONG_ARGUMENT = "Неверное значение";

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

const int ROWS = 3;
const int COLUMS = 5;

int main()
{
    int matrix[ROWS][COLUMS];

    cout << format("Введите целые значения для матрицы {}x{}\n\n", ROWS, COLUMS);

    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLUMS; c++)
        {
            bool temp = false;
            string input = "";

            while (not temp)
            {
                cout << format("Значение {}:{}\t", r+1, c+1);
                getline(cin ,input);
                temp = is_int(input);
            }

            matrix[r][c] = stoi(input);
        }
    }

    int sum = 0;

    for (int c = 0; c < COLUMS; c++)
    {
        sum += matrix[2][c];
    }

    cout << format("Сумма элементов второй строки: {}", sum) << endl << endl;
}
