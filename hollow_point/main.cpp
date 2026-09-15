#include <iostream>
using std::cout, std::cin, std::endl, std::getline, std::stoul;

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
    const string MAIN_MENU = "1. Добавить фильм\n2. Добавить сеанс\n3. Просмотр расписания\n";
    const string NO_FILMS = "Перед созданием сеанса необходимо добавить по крайней мере один фильм";

    protected:
        //Селектор главного меню
        void menu_selector(unsigned pick)
        {
            switch(pick)
            {
                case 1:
                {
                    Movie movie = Movie::movie();
                    movies.push_back(movie);
                    break;
                }
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
                case 3:
                {
                    cout << schedule() << endl;
                }
            }
        }

        string schedule()
        {
            string str_schedule = "\n";
            
            for (int i = 0; i < sessions.size(); i++)
            {
                Session session = sessions[i];
                str_schedule += format("{} - {}\nДата и время начала сеанса: {}.{}.{} в {}:{}\nЗал: {}\nЦена билета: {}р\n", i + 1, session.movie.name, session.date[0], session.date[1], session.date[2], session.time[0], session.time[1], session.hall, session.price);
            }

            return str_schedule;
        }

        Movie movie_pick()
        {
            string str_movies = "\n";
            string pick;
            bool temp = false;

            for (int i = 0; i < movies.size(); i++)
            {
                string mov_name = movies[i].name;
                str_movies += format("{} - {}\n", i + 1, mov_name);
            }

            cout << str_movies << endl;

            while (not temp)
            {
               cout << "Выберите фильм из списка по номеру\t";
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
            }
            menu_selector(stoul(choice));
            
        }

        Panel(Client p_client)
        {
            Client client = p_client;
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