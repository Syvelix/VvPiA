#pragma once

#include <iostream>
#include <vector>
#include "Booking.hpp"
#include "Session.hpp"


using std::string, std::vector, std::cout, std::cin, std::getline;
using booking::Booking;

class Client
{
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
        void add_booking(Session session)
        {
            Booking new_booking = Booking::booking(id, session);
            bookings.push_back(new_booking);
        }
};