#pragma once

#include <string>
#include <list>
#include <format>
#include "Seat.hpp"
#include "Stuff.hpp"
#include "Movie.hpp"

using std::string, std::list, std::cout, std::cin, std::getline, std::format;

class Session
{
    public:

        list<unsigned> date;
        list<unsigned> time;
        string hall;
        unsigned price;
        list<Seat> seats;

        static Session session()
        {
            list<unsigned> date;
            list<unsigned> time;
            string hall;
            unsigned price;
            unsigned seat_amount;
            list<Seat> seats;

            bool temp = false;
            string temp_str;

            while (not temp)
            {
                cout << "Введите число (день) показа сеанса\t";
                getline(cin, temp_str);
                temp = Validator::is_unsigned(temp_str);
                if (temp)
                {
                    temp = Validator::is_in_range(stoul(temp_str), 1, 31);
                }
            }
            date.push_back(stoul(temp_str));
            temp = false;

            while (not temp)
            {
                cout << "Введите месяц показа сеанса\t";
                getline(cin, temp_str);
                temp = Validator::is_unsigned(temp_str);
                if (temp)
                {
                    temp = Validator::is_in_range(stoul(temp_str), 1, 12);
                }
            }
            date.push_back(stoul(temp_str));
            temp = false;

            while (not temp)
            {
                cout << "Введите год показа сеанса\t";
                getline(cin, temp_str);
                temp = Validator::is_unsigned(temp_str);
            }
            date.push_back(stoul(temp_str));
            temp = false;

            while (not temp)
            {
                cout << "Введите время показа (часы)\t";
                getline(cin, temp_str);
                temp = Validator::is_unsigned(temp_str);
                if (temp)
                {
                    temp = Validator::is_in_range(stoul(temp_str), 0, 24);
                }
            }
            time.push_back(stoul(temp_str));
            temp = false;

            while (not temp)
            {
                cout << "Введите время показа (минуты)\t";
                getline(cin, temp_str);
                temp = Validator::is_unsigned(temp_str);
                if (temp)
                {
                    temp = Validator::is_in_range(stoul(temp_str), 0, 59);
                }
            }
            time.push_back(stoul(temp_str));
            temp = false;

            cout << "Введите название зала\t";
            getline(cin, hall);

            while (not temp)
            {
                cout << "Введите цену билета (рубли)\t";
                getline(cin, temp_str);
                temp = Validator::is_unsigned(temp_str);
            }
            price = stoul(temp_str);
            temp = false;

            while (not temp)
            {
                cout << "Введите количество мест в зале\t";
                getline(cin, temp_str);
                temp = Validator::is_unsigned(temp_str);
            }
            seat_amount = stoul(temp_str);
            temp = false;

            for (unsigned i = 0; i < seat_amount; i++)
            {
                cout << format("Место №{}", i + 1) << endl;
                seats.push_back(Seat::seat());
            }
            
            return Session(Movie::movie(), date, time, hall, price, seats);
        }
        

        
    
        Session(Movie s_movie, list<unsigned> s_date, list<unsigned> s_time, string s_hall, unsigned s_price, list<Seat> s_seats)
        {
            Movie movie = s_movie;
            date = s_date;
            time = s_time;
            hall = s_hall;
            price = s_price;
            seats = s_seats;
        }

};