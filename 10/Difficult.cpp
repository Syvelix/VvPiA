//Вариант 13
#include <iostream>
using std::cout, std::cin, std::getline, std::endl, std::stod;
#include <algorithm>
using std::find, std::find, std::begin, std::end;
#include <string>
using std::string;
#include <format>
using std::format;
#include <exception>
using std::out_of_range, std::invalid_argument;
#include <vector>
using std::vector;

const string ERROR_MSG = "\nНеверное выражение";

bool falseout(string value)
{
    cout << format("{}: {}", ERROR_MSG, value) << endl;
    return false;
}

bool is_calcable(string& input)
{
    const string good_symbols = " 0123456789/*+-()";

    for (char& sym : input)
    {
        if (find(begin(good_symbols), end(good_symbols), sym) == end(good_symbols))
        {
            cout << sym;
            return falseout(input);
        }
    }
    
    const string opers = "+-*/";
    for (int i = 0; i < input.size() - 1; i++)
    {
        if (opers.find(input[i]) != opers.npos && opers.find(input[i+1]) != opers.npos)
        {
            return falseout(input);
        }
    }
    return true;
}

void calculate(string input, double& result, string& status)
{
    while (find(begin(input), end(input), ' ') != end(input))
    {
        input.replace(input.find_first_of(' '), 1, "");
    }
    
    string tempstr{""};
    

    for (char& sym : input)
    {

    }
}

int main()
{
    string input{""};
    bool temp = false;

    while (not temp)
    {
        cout << "Введите математическое выражение\t";
        getline(cin, input);
        string& inputlink = input;
        temp = is_calcable(inputlink);
    }
    
}