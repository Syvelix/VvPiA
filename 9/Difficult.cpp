#include <iostream>
using std::cout, std::cin, std::endl, std::stod;
#include <exception>
using std::out_of_range, std::invalid_argument;
#include <format>
using std::format;
#include <string>
using std::string, std::getline;

const string ERROR_MSG = "\nНеверный аргумент";

static bool falseout(string value)
{
    cout << format("{}: {}", ERROR_MSG, value) << endl;
    return false;
}

//Можно ли привести string к double
static bool is_double(string value)
{

    size_t pos;
    try
    {
        stod(value, &pos);
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
};

void complex_calc(double xReal, double xShadow, double yReal, double yShadow, char oper)
{
    double resReal{0};
    double resShadow{0};
    switch (oper)
    {
    case '+':
        resReal = xReal + yReal;
        resShadow = xShadow + yShadow;
        break;
    case '-':
        resReal = xReal - yReal;
        resShadow = xShadow - yShadow;
        break;
    case '*':
        resReal = xReal * yReal - xShadow * yShadow;
        resShadow = xReal * yShadow + yReal * xShadow;
        break;
    case '/':
        resReal = (xReal * yReal + xShadow * yShadow) / (yReal * yReal + yShadow * yShadow);
        resShadow = (xShadow * yReal - xReal * yShadow) / (yReal * yReal + yShadow * yShadow);
    break;
    }

    cout << format("Результат: {} + {}i\n\n", resReal, resShadow);
}

int main()
{
    bool temp = false;
    string input{""};

    while (not temp)
    {
        cout << "Введите действительную часть первого числа\t";
        getline(cin, input);
        temp = is_double(input);
    }
    double xReal = stod(input);
    temp = false;

    while (not temp)
    {
        cout << "Введите мнимую часть первого числа\t";
        getline(cin, input);
        temp = is_double(input);
    }
    double xShadow = stod(input);
    temp = false;

    char oper{' '};
    while (not temp)
    {
        cout << "Введите операцию (+,-,*,/). Будет считан первый символ строки\t";
        cin >> oper;

        switch (oper)
        {
        case '-':
        case '*':
        case '/':
        case '+':
            temp = true;
            cin.ignore();
            break;
        
        default:
            temp = falseout(string{oper});
            cin.ignore();
            break;
        }
    }
    temp = false;
    
    
    while (not temp)
    {
        cout << "Введите действительную часть второго числа\t";
        getline(cin, input);
        temp = is_double(input);
    }
    double yReal = stod(input);
    temp = false;

    while (not temp)
    {
        cout << "Введите мнимую часть второго числа\t";
        getline(cin, input);
        if (yReal == 0 && input == "0")
        {
            cout << "Знаменатель не может быть равен 0\n";
            continue;
        }
        temp = is_double(input);
    }
    double yShadow = stod(input);
    temp = false;

    complex_calc(xReal, xShadow, yReal, yShadow, oper);

    return 0;
}