#pragma once

#include <iostream>
#include <list>
#include "Stuff.hpp"
#include "Booking.hpp"
#include "Session.hpp"

using std::string, std::list, std::cout, std::cin, std::getline;

class Client
{
    public:
        string name;
        string phone_num;
        list<Booking> bookings;

        static Client client()
        {
            string name;
            string phone_num;
            list<Booking> bookings;

            cout << "Введите имя\t";
            getline(cin, name);

            cout << "Введите номер телефона\t";
            getline(cin, phone_num);

            return Client(name, phone_num, bookings);
        }

        Client(string c_name, string c_phone_num, list<Booking> c_bookings)
        {
            name = c_name;
            phone_num = c_phone_num;
            bookings = c_bookings;
        }

        //Добавить бронь на выбранный сеанс
        void add_booking(Session session)
        {
            Booking new_booking = Booking::booking(*this, session);
            bookings.push_back(new_booking);
        }
};