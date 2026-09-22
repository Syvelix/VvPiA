//Вариант 13

#include <iostream>
#include <format>
#include <string>

using std::cout, std::to_string, std::getline, std::format, std::cin, std::string;

void menu(char choice)
{
    switch (choice)
    {
    case '1':
        cout << "Запуск";
        break;
    case '2':
        cout << "Настройки";
        break;
    case '3':
        cout << "Справка";
        break;
    case '0':
        cout << "Выход";
        break;
    default:
        cout << format("Нет такого пункта: {}", choice);
        break;
    }
    cout << "\n";
}

int main()
{
    string input;
    bool temp;

    while (true)
    {
        cout << "Введите цифру от нуля до трёх, чтобы получить описание пункта меню программы\t";
        getline(cin, input);
        if (input.size() == 1)
        {
            break;
        }
        cout << "Неверный ввод\n";
    }
    menu(input[0]);
    return 0;
}