#pragma once

#include <iostream>
#include "Stuff.hpp"

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
        temp = false;

        while (not temp)
        {
            cout << "Место свободно? (0 - занято, 1 - свободно)\t";
            getline(cin, temp_str);
            temp = Validator::is_bool(temp_str);
        }
        state = Tools::string_to_bool(temp_str);

        return Seat(row, number, state);
    }

        unsigned row;
        unsigned number;
        bool state;

        Seat(unsigned s_row, unsigned s_number, bool s_state)
        {
            row = s_row;
            number = s_number;
            state = s_state;
        }
};