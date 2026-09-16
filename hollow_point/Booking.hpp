#pragma once

#include <iostream>
#include "Client.hpp"
#include "Session.hpp"
#include "Seat.hpp"
#include <ctime>
#include <format>
#include <vector>

using std::string, std::getline, std::cin, std::cout, std::endl, std::stoul, std::vector;

class Booking
{
    public:
        vector<int> date;

        Session session;
        vector<Seat*> seats;
        //Статический класс для получения ввода
        static Booking booking(int id, Session& l_session, vector<Seat*> l_seat)
        {
            struct tm datetime;
            int client_id = id;
            vector<int> date = {datetime.tm_mday, datetime.tm_mon, datetime.tm_year};

            return Booking(l_session, client_id, date, l_seat);
        }

        Booking(Session& b_session, int b_client_id, vector<int> b_date, vector<Seat*> b_seats):session(b_session),seats(b_seats)
        {
            int client_id = b_client_id;
            date = b_date;
        }
};
