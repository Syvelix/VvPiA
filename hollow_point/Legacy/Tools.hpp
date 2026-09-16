#pragma once

#include <iostream>
#include <string>
#include <format>
#include <list>
#include <algorithm>
#include <variant>
using std::variant;

#include "Movie.hpp"
#include "Booking.hpp"

using seletor_returns = variant<Movie>;

using std::string, std::list, std::endl, std::format, std::stoul, std::stoi, std::invalid_argument, std::cout, std::to_string;


namespace toolpack
{


class Tools
{
    public:
        
        //Конвертация string в bool (небезопасно, использовать в паре с Validator::is_bool)
        static bool string_to_bool(string value)
        {
            int value_i = stoi(value);
            return static_cast<bool>(value_i);
        }

        static auto vector_selector(vector<seletor_returns>)
        {

        }

};}