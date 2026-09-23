//Вариант 13

#include <iostream>
#include <string>
#include <format>
#include <iomanip>
#include <cmath>

using std::cout, std::reverse, std::setw, std::to_string, std::setprecision, std::pow, std::format, std::invalid_argument, std::getline, std::cin, std::endl, std::stod, std::stoi, std::string;

const string WRONG_ARGUMENT = "Неверное значение";

//Сообщение об ошибке + false в ретёрне
bool falseout(auto input)
{
    cout << format("{} : {}", WRONG_ARGUMENT, input) << endl;
    return false;
}

//Проверка на возможность перевода в double
bool is_double(string input)
{
    size_t pos;
    try
    {
        stod(input, &pos);
    }
    catch(const invalid_argument& e)
    {
        return falseout(input);
    }

    if (pos != input.size())
    {
        return falseout(input);
    }
    
    return true;
}

//Проверка аргументов цикла for
bool is_invalid_for(double start, double finish, double step)
{
    if (step == 0)
    {
        cout << "Задан нулевой шаг\n";
        return true;
    }
    else if (step > 0)
    {
        if (start > finish)
        {
            cout << format("Начало отсчёта не может быть больше его конца при положительном шаге ({} > {})\n", start, finish);
            return true;
        }
    }
    else
    {
        if (start < finish)
        {
            cout << format("Начало отсчёта не может быть меньше его конца при отрицательном шаге ({} < {})\n", start, finish);
            return true;
        }
    }
    return false;
}

//Цикл для... цикла
double loopcycle(double curr, double maxx)
{
    double result = curr / static_cast<double>((pow(curr, 2) + 1));

    //Делаю так, чтобы число curr отображало ровно 15 цифр
    //Хотел через setpersicion, но он обрезает нули
    //А для красивой таблицы нужен постоянный отступ
    //Пришлось писать кастыль
    string formatted_curr = to_string(curr).substr(0, 15);
    formatted_curr.find('.') != formatted_curr.npos ? formatted_curr : formatted_curr += ".";
    while (formatted_curr.length() != 15) {formatted_curr += "0";};

    cout << format("x = {}\t|\ty = {}", formatted_curr, result) << endl;

    return (result > maxx) ? result : maxx;
}

int main()
{
    double start, finish, step;

    string input;
    bool temp = false;

    while (not temp)
    {
        cout << "Введите точку начала отсчёта (включительно)\t";
        getline(cin, input);
        temp = is_double(input);
    }
    start = stod(input);
    temp = false;

    while (not temp)
    {
        cout << "Введите точку конца отсчёта (включительно)\t";
        getline(cin, input);
        temp = is_double(input);
    }
    finish = stod(input);
    temp = false;

    while (not temp)
    {
        cout << "Введите шаг\t";
        getline(cin, input);
        temp = is_double(input);
    }
    step = stod(input);

    if (is_invalid_for(start, finish, step)) {return 1;};

    double maxx = 0;
    if (step > 0)
    {
        for (double curr = start; curr <= finish; curr += step)
        {
            maxx = loopcycle(curr, maxx);
        }
    }
    else
    {
       for (double curr = start; curr >= finish; curr += step)
        {
            maxx = loopcycle(curr, maxx);
        } 
    }

    cout << format("Точка максимума функции на промежутке [{};{}] равна {}\n", start, finish, maxx);
    return 0;
}