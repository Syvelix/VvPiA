#pragma once

#include <iostream>
#include <string>
#include <format>
#include <list>
using std::string, std::list, std::endl, std::format, std::stoul, std::stoi, std::invalid_argument, std::cout, std::to_string;

const string ERROR_MSG = "Неверный аргумент";

namespace valid
{


class Validator
{
    static bool falseout(string value)
    {
        cout << format("{}: {}", ERROR_MSG, value) << endl;
        return false;
    }

    public:
        //Можно ли привести string к unsigned
        static bool is_unsigned(string value)
        {
            size_t pos;
            try
            {
                stoul(value, &pos);
            }
            catch (const invalid_argument& e)
            {
                return falseout(value);
            }

            if (pos != value.size())
            {
                return falseout(value);
            } 

            if (value[0] == '-')
            {
                return falseout(value);
            }
            return true;
        }
        
        //Можно ли привести string к bool
        static bool is_bool(string value)
        {
            list<string> example = {"1", "0"};
            if (std::ranges::find(example, value) != example.end())
            {
                return true;
            }
            return falseout(value);
        }

        //Входит ли число в диапазон [min, max]
        static bool is_in_range(unsigned value, unsigned min, unsigned max)
        {
            if (value >= min and value <= max)
            {
                return true;
            }
            return falseout(to_string(value));
        }
};}