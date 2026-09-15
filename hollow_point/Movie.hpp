#pragma once

#include <iostream>
//Файл с проверочным классом
#include "Validator.hpp"

using valid::Validator;

using std::string, std::getline, std::cin, std::cout, std::endl, std::stoul;

class Movie
{
    public:
        string name;
        string genre;
        string producer;
        unsigned duration;
        unsigned age_rate;

        //Статический класс для получения ввода
        static Movie movie()
        {
            //Переменные для возврата
            string name;
            string genre;
            string producer;
            unsigned duration;
            unsigned age_rate;

            //Служебные переменные
            bool temp{false};
            string temp_str;

            cout << "Введите название фильма\t";
            getline(cin, name);

            cout << "Введите жанр\t";
            getline(cin, genre);

            cout << "Введите имя режиссёра\t";
            getline(cin, producer);

            while (not temp)
            {
                cout << "Введите длительность фильма в минутах\t";
                getline(cin, temp_str);
                temp = Validator::is_unsigned(temp_str);
            }
            duration = stoul(temp_str);
        
            temp = false;

            while (not temp)
            {
                cout << "Введите возрастное ограничение (число лет)\t";
                getline(cin, temp_str);
                temp = Validator::is_unsigned(temp_str);
            }
            age_rate = stoul(temp_str);
        
            return Movie(name, genre, producer, duration, age_rate);
        }

        Movie(string m_name, string m_genre, string m_producer, unsigned m_duration, unsigned m_age_rate)
        {
            name = m_name;
            genre = m_genre;
            producer = m_producer;
            duration = m_duration;
            age_rate = m_age_rate;
        }
};