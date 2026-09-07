#include <iostream>
#include <format>
using std::cout, std::cin, std::cerr, std::flush, std::string, std::format;

string endl2()
{
    cout << flush;
    return "\n\n";
}

int main() 
{
    int number;
    int buffer;
    cout << "Hello, World!\n" << "I'm finally here!\n";
    cout << "Can you hear me?\nAre we connected? Can you please enter any number?\n\n";
    cin >> number;
    if (cin.fail())
    {
        cout << "This does not seem to be a number..." << "\tStill, I appretiate you trying.";
    }
    else
    {
        cout << format("So you've picked {}\n", number) << endl2();
        cin >> buffer;
        switch(number % 2 == 0)
        {
            case true:
                cout << "It is even.";
                break;
            default:
                cout << "It is odd.";
                break;
        }
    }
    cout << flush << "\n";
    cout << "How intresting." << endl2();
    return 0;
}