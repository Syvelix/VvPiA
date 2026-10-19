#include <iostream>
using std::cout, std::cin, std::endl, std::stoi;
#include <format>
using std::format;
#include <string>
using std::string, std::getline;
#include <random>
using std::random_device, std::mt19937, std::uniform_int_distribution;
#include <vector>
using std::vector;
#include <exception>
using std::out_of_range, std::invalid_argument;

const string ERROR_MSG = "\nНеверный аргумент";

static bool falseout(string value)
{
    cout << format("{}: {}", ERROR_MSG, value) << endl;
    return false;
}

//Вектор в строку
template<typename T> string pretty_vec(vector<T> vec)
{
    string vecstr{"{"};
    for (int i = 0; i < vec.size(); i++)
    {
        vecstr += format("{}, ", vec[i]);
    }
    vecstr.replace(vecstr.size() - 2, 2, "");
    vecstr += "}";
    return vecstr;
}

//Вектор случайных интов заданной длины
template<typename T> void randgen(vector<T>& randvec, unsigned size = 15, int divider = 10000)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution dis;

    for (int i = 0; i < size; i++)
    {
        randvec.push_back(dis(gen) % divider);
    }
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

int main()
{
    vector<int> randvec;
    randgen(randvec);

    cout << format("Вектор с числами: {}\n", pretty_vec(randvec));

    string input{""};
    bool temp = false;

    while (not temp)
    {
        cout << "Введите наименьшее подходящее значение\t";
        getline(cin, input);
        temp = is_int(input);
    }
    int min_allowed = stoi(input);

    int c{0};
    for (int i = 0; i < randvec.size(); i++)
    {
        if (randvec.at(i) > min_allowed)
        {
            c++;
        }
    }

    cout << format("Количество элементов, больше {}, равно {}\n\n", min_allowed, c);

    return 0;
}