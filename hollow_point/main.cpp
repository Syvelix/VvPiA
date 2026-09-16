#include <iostream>
using std::cout, std::cin, std::endl, std::getline, std::stoul, std::find;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <functional>
using std::function;

#include <variant>
using std::variant;

#include <format>
using std::format;

#include <unordered_map>
using std::unordered_map;

#include "Client.hpp"
#include "Booking.hpp"
#include "Session.hpp"
#include "Movie.hpp"
#include "Seat.hpp"
#include "Validator.hpp"
using valid::Validator;

class Panel
{
    const string MAIN_MENU = "\n1. Добавить фильм\n2. Добавить сеанс\n3. Просмотр расписания\n4. Бронь места на сеанс\n5. Просмотр свободных места на сеанс\n6. Мои бронирования\n7. Отменить бронь\n8. Расчитать выручку\t";
    const string NO_FILMS = "\nПеред созданием сеанса необходимо добавить по крайней мере один фильм\n";
    const string NO_SESSSIONS = "\nНет доступных сеансов\n";
    const string NO_SEATS = "\nВсе места на сеанс уже заняты\n";

    Client client;

    protected:

        
        //Селектор главного меню
        void menu_selector(unsigned pick)
        {
            switch(pick)
            {
                //Добавить фильм
                case 1:
                {
                    Movie movie = Movie::movie();
                    movies.push_back(movie);
                    break;
                }
                //Добавить сеанс
                case 2:
                {
                    if (movies.size()== 0)
                    {
                        cout << NO_FILMS << endl;
                        break;
                    }
                    
                    Movie movie = movie_pick();

                    Session session = Session::session(movie);
                    sessions.push_back(session);
                    break;
                }
                //Просмотр расписания
                case 3:
                {
                    cout << schedule() << endl;
                    break;
                }
                //Бронь места на сеанс
                case 4:
                {
                    if (sessions.size() == 0)
                    {
                        cout << NO_SESSSIONS << endl;
                        break;
                    }

                    Session& session = session_pick();

                    vector<Seat*> empty_seats;

                    for (Seat& seat:session.seats)
                    {
                        if (seat.state == 1)
                        {
                            empty_seats.push_back(&seat);
                        }
                    }

                    if (empty_seats.size() == 0)
                    {
                        cout << NO_SEATS << endl;
                        break;
                    }

                    string temp_str;
                    bool temp = false;

                    while (not temp)
                    {
                        cout << format("Выберите количество мест для брони. (0 чтобы отменить бронь) Свободно {} мест(а)\t", empty_seats.size());
                        getline(cin, temp_str);

                        if (temp_str == "0")
                        {
                            return;
                        }

                        temp = Validator::is_unsigned(temp_str);

                        if (temp)
                        {
                            temp = Validator::is_in_range(stoul(temp_str), 1, empty_seats.size());
                        }
                    }

                    //Нужен именно список указателей, чтобы иметь возможность менять состояние мест из Client
                    vector<Seat*> picked_seats;
                    for (int i = 0; i < stoul(temp_str); i++)
                    {
                        Seat* seat = seat_pick(empty_seats);
                        picked_seats.push_back(seat);
                        //После того, как место выбрано, его следует удалить из списка свободных
                        empty_seats.erase(empty_seats.begin() + i);
                    }

                    //Указатели на выбранные места передаются клиенту
                    client.add_booking(session, picked_seats);
                    break;
                }
                //Просмотр свободных мест на сеанс
                case 5:
                {
                    if (sessions.size() == 0)
                    {
                        cout << NO_SESSSIONS << endl;
                        break;
                    }

                    Session& session = session_pick();

                    vector<Seat*> empty_seats;

                    for (Seat& seat:session.seats)
                    {
                        if (seat.state == 1)
                        {
                            empty_seats.push_back(&seat);
                        }
                    }

                    if (empty_seats.size() == 0)
                    {
                        cout << NO_SEATS << endl;
                        break;
                    }

                    cout << seats_str(empty_seats) << endl;
                    break;
                }
                //Просмотр списка бронирований
                case 6:
                {
                    client.bookings_out();
                    break;
                }
                //Отмена бронирования
                case 7:
                {
                    client.remove_booking();
                    break;
                }
                //Расчёт выручки за number сеансов
                case 8:
                {
                    if (sessions.size() == 0)
                    {
                        cout << NO_SESSSIONS << endl;
                        break;
                    }

                    Session& session = session_pick();

                    string number;
                    bool temp = false;

                    while (not temp)
                    {
                        cout << "Введите сколько раз был показан фильм по цене сеанса\t";
                        getline(cin, number);
                        temp = Validator::is_unsigned(number);
                    }

                    unsigned summ = session.price * stoul(number);
                    cout << format("За {} показов фильма было выручено {} рублей\n", number, summ) << endl;
                }
            }
        }

        //Читабельная строка свободных мест
        string seats_str(vector<Seat*> empty_seats)
        {
            string str_seats = "\n";
            
            for (int i = 0; i < empty_seats.size(); i++)
            {
                Seat* seat = empty_seats[i];
                str_seats += format("\n{}. - Место {} в {} ряду\n", i + 1, seat->number, seat->row);
            }
            return str_seats;
        }
        //Выбор места из списка свободных
        Seat* seat_pick(vector<Seat*> empty_seats)
        {
            string str_seats = seats_str(empty_seats);
            string pick;
            bool temp = false;

            cout << str_seats << endl;

            while (not temp)
            {
               cout << "\nВыберите место из списка по номеру\t";
               getline(cin, pick);
               temp = Validator::is_unsigned(pick);

               if (temp)
               {
                    temp = Validator::is_in_range(stoul(pick), 1, empty_seats.size());
               }
            }
            return empty_seats[stoul(pick) - 1];
        }
        
        //Выбор сеанса из списка
        Session& session_pick()
        {
            string str_sessions = "\n";
            string pick;
            bool temp = false;

            for (int i = 0; i < sessions.size(); i++)
            {
                Session session = sessions[i];
                str_sessions += format("\n{} - Сеанс фильма {} {}.{}.{} на {}:{}\n", i + 1, session.movie.name, session.date[0], session.date[1], session.date[2], session.time[0], session.time[1]);
            }

            cout << str_sessions << endl;

            while (not temp)
            {
               cout << "\nВыберите сеанс из списка по номеру\t";
               getline(cin, pick);
               temp = Validator::is_unsigned(pick);

               if (temp)
               {
                    temp = Validator::is_in_range(stoul(pick), 1, sessions.size());
               }
            }
            return sessions[stoul(pick) - 1];
        }

        //Создание строки расписания
        string schedule()
        {
            //Проверка наличия сеансов
            if (sessions.size() == 0)
            {
                return NO_SESSSIONS;
            }

            string str_schedule = "\n";
            
            for (int i = 0; i < sessions.size(); i++)
            {
                Session session = sessions[i];
                str_schedule += format("{}. - {}\nДата и время начала сеанса: {}.{}.{} в {}:{}\nЗал: {}\nЦена билета: {} рублей\n\n", i + 1, session.movie.name, session.date[0], session.date[1], session.date[2], session.time[0], session.time[1], session.hall, session.price);
            }

            return str_schedule;
        }

        //Выбор фильма из списка
        Movie movie_pick()
        {
            string str_movies = "\n";
            string pick;
            bool temp = false;

            for (int i = 0; i < movies.size(); i++)
            {
                string mov_name = movies[i].name;
                str_movies += format("{}. - {}\n", i + 1, mov_name);
            }

            cout << str_movies << endl;

            while (not temp)
            {
               cout << "\nВыберите фильм из списка по номеру\t";
               getline(cin, pick);
               temp = Validator::is_unsigned(pick);

               if (temp)
               {
                    temp = Validator::is_in_range(stoul(pick), 1, movies.size());
               }
            }
            return movies[stoul(pick) - 1];
        }

    public:

        //Список id пользователей (плейсхолдер, не используется, но есть потенциал)
        static vector<int> ids;
        //Список фильмов
        static vector<Movie> movies;
        //Список сеансов
        static vector<Session> sessions;
        
        //Основной цикл
        void main()
        {
            bool temp = false;

            string choice;
            cout << MAIN_MENU;

            while (not temp)
            {
                getline(cin, choice);
                temp = Validator::is_unsigned(choice);

                if (temp)
                {
                    temp = Validator::is_in_range(stoul(choice), 1, 8);
                }
            }
            menu_selector(stoul(choice));
            
        }

        Panel(Client& p_client):client(p_client)
        {
        }
};

class Boot
{
    public:
        static Client boot()
        {
            cout << "Необзодимо создать профиль клиента для работы с программой\n";
            int id = Panel::ids.size() + 1;
            Client client = Client::client(id);
            Panel::ids.push_back(id);
            return client;
        }
};

vector<int> Panel::ids;
vector<Movie> Panel::movies;
vector<Session> Panel::sessions;

int main()
{
    Client client = Boot::boot();
    Panel panel = Panel(client);
    while (true)
    {
        panel.main();
    }
}




//Проверка работы указателей
//cout << client.bookings[0].seats[0]->state << endl;
//                    cout << sessions[0].seats[0].state << endl;
//
//                  client.bookings[0].seats[0]->state = 2;
//
//                  cout << client.bookings[0].seats[0]->state << endl;
//                cout << sessions[0].seats[0].state << endl;
//