//Вариант 13

#include <iostream>
#include <format>
#include <string>

using std::cout, std::to_string, std::getline, std::format, std::cin, std::string;

void result(char number)
{
    switch (number)
    {
        case '1':
            cout << "+";
            break;
        case '2':
            cout << "-";
            break;
        case '3':
            cout << "*";
            break;
        case '4':
            cout << "/";
            break;
        default:
            cout << format("Неизвестный аргумент: {}", number);
            break;
    }
    cout << "\n";
}

int main()
{
    string input;

    while (true)
    {
        cout << "Введите цифру от одного до четырёх, чтобы получить знак арифметической операции\t";
        getline(cin, input);
        if (input.size() == 1)
        {
            break;
        }
        cout << "Неверный ввод\n";
    }
    result(input[0]);
    return 0;
}