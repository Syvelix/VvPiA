#pragma once

#include "Validator.hpp"
using valid::Validator;

#include <iostream>

using std::string, std::cout, std::cin, std::getline;

class Seat
{
    public:

    //Статический класс для получения ввода
    static Seat seat()
    {
        //Переменные для возврата
        unsigned row;
        unsigned number;
        //Состояние места, 1 - свободно, 0 - занято
        bool state;

        //Служебные переменные
        bool temp = false;
        string temp_str;

        while (not temp)
        {
            cout << "Введите номер ряда\t";
            getline(cin, temp_str);
            temp = Validator::is_unsigned(temp_str);
        }
        row = stoul(temp_str);
        temp = false;

        while (not temp)
        {
            cout << "Введите номер места в ряду\t";
            getline(cin, temp_str);
            temp = Validator::is_unsigned(temp_str);
        }
        number = stoul(temp_str);

        return Seat(row, number);
    }
        unsigned row;
        unsigned number;
        bool state;

        Seat(unsigned s_row, unsigned s_number)
        {
            row = s_row;
            number = s_number;
            //По умолчанию место свободно
            state = 1;
        }
};