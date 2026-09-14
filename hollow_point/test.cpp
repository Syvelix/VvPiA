#include "Stuff.cpp"
#include "Movie.cpp"
#include <iostream>

using namespace std;

int main()
{
    Movie movie = Movie::movie();

    cout << "\n" << movie.name << "\n";
    return 0;
}