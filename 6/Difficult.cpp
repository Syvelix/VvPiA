#include <iostream>
using std::cin, std::cout, std::endl, std::getline, std::stoi;
#include <string>
using std::string;
#include <format>
using std::format;
#include <exception>
using std::invalid_argument, std::out_of_range;
#include <algorithm>
using std::sort, std::count;

//Использовал вектора чтобы применить count вместо циклов
#include <vector>
using std::vector;

using std::find, std::begin, std::end;

#include <random>
using std::random_device, std::mt19937, std::uniform_int_distribution;

const string WRONG_ARGUMENT = "Неверное значение";

const int SIZE = 30;

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

//Получение строки из вектора интов
string pretty_arr(vector<int> arr, int size)
{
    string str_arr{"{"};

    for (int i = 0; i < size; i++)
    {
        (i == 0) ? str_arr += format(" {}", arr[i]) : str_arr += format(", {}", arr[i]);
    }
    str_arr += " }";
    return str_arr;
}

//Красивая табличка из вектора интов
string includes_table(vector<int> numbers, int start = 1, int end = SIZE)
{
    string result{format("Количество вхождений чисел от {} до {}:\n", start, end)};
    
    for (int i = start; i < end; i++)
    {
        result += format("{}: {} раз(а)\n", i, count(numbers.begin(), numbers.end(), i));
    }

    return result;
}

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>dis(1,10);

    vector<int> numbers(SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        numbers[i] = dis(gen);
    }


    cout << format("Массив: {}\n", pretty_arr(numbers, SIZE));

    cout << includes_table(numbers, 1, 10);

    return 0;
}