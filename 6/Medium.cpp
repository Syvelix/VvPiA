#include <iostream>
using std::cin, std::cout, std::endl, std::getline, std::stoi;
#include <string>
using std::string;
#include <format>
using std::format;
#include <exception>
using std::invalid_argument, std::out_of_range;
#include <algorithm>
using std::sort, std::min_element, std::max_element;

#include <numeric>
using std::accumulate;

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

//Получение строки из массива произвольного типа
string pretty_arr(auto array[], int size)
{
    string str_arr{"{"};

    for (int i = 0; i < size; i++)
    {
        (i == 0) ? str_arr += format(" {}", array[i]) : str_arr += format(", {}", array[i]);
    }
    str_arr += " }";
    return str_arr;
}

int main()
{
    int numbers[SIZE];

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>dis(1,100);

    for (int i = 0; i < SIZE; i++)
    {
        numbers[i] = dis(gen);
    }
    cout << format("Массив: {}\n\n", pretty_arr(numbers, SIZE));
    
    sort(numbers, numbers + SIZE);

    cout << format("Сумма чисел в массиве: {}\n", accumulate(begin(numbers), end(numbers), 0));

    cout << format("Среднее арифмитическое массива: {}\n", accumulate(begin(numbers), end(numbers), 0) / sizeof(numbers));

    int maxel = *max_element(begin(numbers), end(numbers));
    int minel = *min_element(begin(numbers), end(numbers));

    cout << format("Минимальное значение: {},\tМаксимальное значение: {}\n", minel, maxel);

    cout << format("Второй максимум от массива: {}\n\n", numbers[SIZE - 2]);

    return 0;
}
