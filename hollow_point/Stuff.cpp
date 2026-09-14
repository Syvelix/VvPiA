#pragma once

#include <iostream>

using std::string, std::stoul, std::invalid_argument;

class Validator
{
    public:
        static bool is_unsigned(string value)
        {
            size_t pos;
            try
            {
                stoul(value, &pos);
            }
            catch (const invalid_argument& e)
            {
                return false;
            }

            if (pos != value.size())
            {
                return false;
            } 

            return true;
        }

};