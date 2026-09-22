#include <iostream>
#include <format>
#include <filesystem>

using std::cout, std::cin, std::endl, std::format;

int main()
{
    unsigned i;
    cin >> i;

    switch(static_cast<int>(i))
    {
        case 1:
            cout << "Понедельник";
        case 2:
            cout << "Вторник";
        case 3:
            cout << "Среда";
        case 4:
            cout << "Четверг";
        default:
            cout << "Не день";
    }

    cout << endl;
    return 0;
}
