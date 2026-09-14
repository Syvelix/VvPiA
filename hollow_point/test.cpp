#include "Stuff.hpp"
#include "Movie.hpp"
#include "Seat.hpp"
#include "Session.hpp"
#include "Client.hpp"
#include <iostream>
#include <format>

using namespace std;

int main()
{
    Client client = Client::client();
    client.add_booking(Session::session());
}