#include <iostream>
using std::cout, std::cin, std::endl, std::stoul;
#include <format>
using std::format;
#include <string>
using std::string;
#include <random>
using std::random_device, std::mt19937, std::uniform_int_distribution;
#include <vector>
using std::vector;

//Массив в строку
string pretty_arr(int*& arr, int size)
{
    string arrstr{"{"};
    for (int i = 0; i < size; i++)
    {
        arrstr += format("{}, ", arr[i]);
    }
    arrstr.replace(arrstr.size() - 2, 2, "");
    arrstr += "}";
    return arrstr;
}

//Переразмер массива
void resize_arr(int*& arr, unsigned olds, unsigned news)
{
    news = (olds > news ? olds : news);
    int* new_arr = new int[news];
    
    for (int i = 0; i < news; i++)
    {
        new_arr[i] = arr[i];
    }

    delete[] arr;
    arr = new_arr;
}

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution dis;

    int getsize{dis(gen) % 10};
    const int SIZE{getsize == 0 ? 1 : getsize};
    cout << format("Изначальный размер массива: {}\n", SIZE);
    
    int size{SIZE};
    int* arr = new int[size];

    for (int i = 0; i < SIZE * 8; i++)
    {
        if (i >= size)
        {
            resize_arr(arr, size, size * 2);
            cout << format("\nМассив расширен: {} -> {}\n", size, size * 2);
            size *= 2;
        }
        arr[i] = dis(gen);
        cout << format("В массив добавлен элемент, новый массив: {}\n\n", pretty_arr(arr, size));
    }

    return 0;
}