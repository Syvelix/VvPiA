#include <iostream>
//Файл со статическими методами
#include "Stuff.cpp"

using std::string, std::cin, std::cout, std::endl, std::stoul;

class Movie
{
    public:
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
            cin >> name;

            cout << "Введите жанр\t";
            cin >> genre;

            cout << "Введите имя режиссёра\t";
            cin >> producer;

            while (not temp)
            {
                cout << "Введите длительность фильма в минутах\t";
                cin >> temp_str;
                temp = Validator::is_unsigned(temp_str);
            }
            duration = stoul(temp_str);
        
            temp = false;

            while (not temp)
            {
                cout << "Введите возрастное ограничение (число лет)\t";
                cin >> temp_str;
                temp = Validator::is_unsigned(temp_str);
            }
            age_rate = stoul(temp_str);
        
            return Movie(name, genre, producer, duration, age_rate);
        }

        string name;
        string genre;
        string producer;
        unsigned duration;
        unsigned age_rate;

        Movie(string m_name, string m_genre, string m_producer, unsigned m_duration, unsigned m_age_rate)
        {
            name = m_name;
            genre = m_genre;
            producer = m_producer;
            duration = m_duration;
            age_rate = m_age_rate;
        }
};