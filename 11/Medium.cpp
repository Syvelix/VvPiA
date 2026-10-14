//Вариант 13
#include <iostream>
using std::cout;
#include <format>
using std::format;
#include <string>
using std::string;

void copyArray(int* src, int* dest, int size);

string pretty_arr(const int* ptr, const int size)
{
    string arrstr{"{"};
    for (int i = 0; i < size; i++)
    {
        arrstr += format("{}, ", *(ptr + i));
    }
    arrstr.replace(arrstr.size() - 2, 2, "");
    arrstr += "}";
    return arrstr;
}

int main()
{
    int size = 5;
    int arr1[size] = {1, 0, 232, 322, 111};
    int arr2[size] = {12, 212, 21, 3133, 212};

    pretty_arr(arr1, size);

    cout << format("Массив 1: {}\n", pretty_arr(arr1, sizeof(arr1) / sizeof(arr1[0])));
    cout << format("Массив 2: {}\n", pretty_arr(arr2, sizeof(arr2) / sizeof(arr2[0])));

    cout << "Копирование первого массива во второй\n\n";
    copyArray(arr1, arr2, 5);
    
    cout << format("Массив 1: {}\n", pretty_arr(arr1, sizeof(arr1) / sizeof(arr1[0])));
    cout << format("Массив 2: {}\n", pretty_arr(arr2, sizeof(arr2) / sizeof(arr2[0])));

    return 0;   
}

void copyArray(int* src, int* dest, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(dest + i) = *(src + i);
    }
}