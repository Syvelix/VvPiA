#include <iostream>
#include <format>
#include <filesystem>

using std::cout, std::cin, std::endl, std::format;

int main()
{

    char grade;

    switch (grade) 
    { 
    case 'A': 
        cout << "Отлично"; 
        break; 
    case 'B': 
        cout << "Хорошо"; 
        break; 
    case 'C': 
        cout << "Удовлетворительно"; 
        break; 
    default: 
        cout << "Неудовлетворительно"; 
        break; 
    }

    cout << endl;
    return 0;
}
