#pragma once

#include <iostream>
#include "Client.hpp"
#include "Session.hpp"
#include "Seat.hpp"
#include <ctime>
#include <format>
#include <vector>

using std::string, std::getline, std::cin, std::cout, std::endl, std::stoul, std::vector;

namespace booking
{
class Booking
{
    public:
        vector<int> date;

        //Статический класс для получения ввода
        static Booking booking(int id, Session l_session)
        {
            struct tm datetime;
            Session session = l_session;
            int client_id = id;
            Seat seat = Seat::seat();
            vector<int> date = {datetime.tm_mday, datetime.tm_mon, datetime.tm_year};

            return Booking(session, seat, client_id, date);
        }

        Booking(Session b_session, Seat b_seat, int b_client_id, vector<int> b_date)
        {
            Session session = b_session;
            Seat seat = b_seat;
            int client_id = b_client_id;
            date = b_date;
        }
};}
