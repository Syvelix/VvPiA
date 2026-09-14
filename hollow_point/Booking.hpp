#pragma once

#include <iostream>
#include "Client.hpp"
#include "Stuff.hpp"
#include "Session.hpp"
#include "Seat.hpp"
#include <ctime>
#include <format>
#include <list>

using std::string, std::getline, std::cin, std::cout, std::endl, std::stoul;

class Booking
{
    public:
        list<int> date;

        static Booking booking(auto l_client, Session l_session)
        {
            struct tm datetime;
            Session session = l_session;
            auto client = l_client;
            Seat seat = Seat::seat();
            list<int> date = {datetime.tm_mday, datetime.tm_mon, datetime.tm_year};

            return Booking(session, seat, client, date);
        }

        Booking(Session b_session, Seat b_seat, auto b_client, list<int> b_date)
        {
            Session session = b_session;
            Seat seat = b_seat;
            auto client = b_client;
            date = b_date;
        }
};
