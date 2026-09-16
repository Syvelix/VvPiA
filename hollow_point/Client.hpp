#pragma once

#include <iostream>
#include <vector>
#include "Booking.hpp"
#include "Session.hpp"

using std::string, std::vector, std::cout, std::cin, std::getline;

class Client
{

    const string NO_BOOKINGS = "\nУ вас нет бронирований\n";

    string bookings_str()
    {
            //Проверка наличия бронирований
            if (bookings.size() == 0)
            {
                return NO_BOOKINGS;
            }

            string str_bookings = "\n";
            
            for (int i = 0; i < bookings.size(); i++)
            {
                Booking booking = bookings[i];
                str_bookings += format("{}. - {} мест(а) на сеанс {} {}.{}.{} в {}:{}\n\n", i + 1, booking.seats.size(), booking.session.movie.name, booking.session.date[0], booking.session.date[1], booking.session.date[2], booking.session.time[0], booking.session.time[1]);
            }

            return str_bookings;
    }

    public:
        int id;
        string name;
        string phone_num;
        vector<Booking> bookings;

        //Статический класс для получения ввода
        static Client client(int id)
        {
            string name;
            string phone_num;
            vector<Booking> bookings;

            cout << "Введите имя\t";
            getline(cin, name);

            cout << "Введите номер телефона\t";
            getline(cin, phone_num);

            return Client(id, name, phone_num, bookings);
        }

        Client(int c_id, string c_name, string c_phone_num, vector<Booking> c_bookings)
        {
            id = c_id;
            name = c_name;
            phone_num = c_phone_num;
            bookings = c_bookings;
        }

        //Добавить бронь на выбранный сеанс
        void add_booking(Session session, vector<Seat*> seats)
        {
            Booking new_booking = Booking::booking(id, session, seats);
            bookings.push_back(new_booking);

            //Места помечаются как занятые
            for (Seat* seat: seats)
            {
                seat->state  = 0;
            }
            
            cout << "Бронь добавлена" << endl;
        }
        //Список бронирований
        void bookings_out()
        {
            cout << bookings_str() << endl;
        }
        //Отменить бронь
        void remove_booking()
        {
            string str_bookings = bookings_str();

            cout << str_bookings << endl;

            if (str_bookings == NO_BOOKINGS)
            {
                return;
            }

            string pick;
            bool temp = false;

            while (not temp)
            {
                cout << "Выберите, какую бронь отменить (0 чтобы не отменять ничего)\t";
                getline(cin, pick);

                if (pick == "0")
                {
                    return;
                }

                temp = Validator::is_unsigned(pick);

                if (temp)
                {
                    temp = Validator::is_in_range(stoul(pick), 1, bookings.size());
                }

                //Места помечаются как свободные
                for (Seat* seat: bookings[stoul(pick) - 1].seats)
                {
                    seat->state = 1;
                }
                bookings.erase(bookings.begin() + stoul(pick) - 1);

                cout << "Бронь отменена" << endl;
            }
        }
};