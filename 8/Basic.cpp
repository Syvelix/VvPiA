#include <iostream>
using std::cin, std::cout;
#include <format>
using std::format;
#include <string>
using std::string, std::getline;

int main()
{
    string first{""};
    string second{""};

    cout << "Введите первую строку\t";
    getline(cin, first);
    cout << "Введите вторую строку\t";
    getline(cin, second);

    cout << format("Склеенная строка: {}\n\n", first+second);

    return 0;
}