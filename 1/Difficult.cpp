//Стоимость обеда + чаевые

//Использование директивы препроцессора iostream
#include <iostream>
//Использование модуля, содержащего setprecision и fixed
#include <iomanip>

//Юзинги
using std::cin, std::cout, std::fixed, std::setprecision, std::endl, std::string;

//Повторяющееся сообщение об ошибке вынесено в отдельную переменную
const string FAIL_MESSAGE = "Введённое значение не является корректным числом.\n";

//Функция очистки буфера ввода и вывода
void cleanup()
{
    cin.ignore();
    cout.flush();
}

//Расчёт чаевых
double tip(double cost, int percent)
{
    return cost * percent / 100;
}

//Точка входа
int main()
{
    //Изначальная цена обеда
    double lunch_cost;
    //Как правило процент чавеых - целое число. Этого правила я придержусь и здесь.
    int tip_percent;

    //Запрос изначальной стоимости обеда, обработка ошибок
    cout << "Введите стоимость обеда\t";
    cin >> lunch_cost;
    if (cin.fail())
    {
        cout << FAIL_MESSAGE;
        return 1;
    }
    if (lunch_cost == 0)
    {
        cout << "Бесплатно не кормим\n";
        return 2;
    }
    else if (lunch_cost < 0)
    {
        cout << "В долг не кормим\n";
        return 2;
    }
    cleanup();

    //Запрос процента чаевых, обработка ошибок
    cout << "На какой процент от стоимости оставить чаевые? (Целое число)\t";
    cin >> tip_percent;
    if (cin.fail())
    {
        cout << FAIL_MESSAGE;
        return 1;
    }
    if (tip_percent < 0)
    {
        tip_percent *= -1;
        cout << "Скидки не будет, ваш ответ переведён в положительный\n";
    }
    else if (tip_percent == 0)
    {
        cout << "Жадина.\n";
    }
    cleanup();
    
    //Расчёт конечной суммы. Нет смысла явно приводить результат функции tip к double через static_cast<double>, тк функция tip по умолчанию возвращает double
    double cost_n_tip = lunch_cost + tip(lunch_cost, tip_percent);
    //Вывод результата с точностью 2 знака после запятой. Потеря точности минимальна, нет смысла расчитывать сумму меньше копейки
    cout << "Стоимость обеда с учётом чаевых равна " << fixed << setprecision(2) << cost_n_tip << "\n";
    return 0;
}