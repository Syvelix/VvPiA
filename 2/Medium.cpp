//Расстояние через время и скорость

#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout, std::cin, std::fixed, std::setprecision, std::endl, std::abs;

int main()
{
    //Скорость возьму дробной, тк она - результат деления м на с
    double speed;
    //Время будет целое, секунды в этой программе - наименьшая единица времени
    int time;

    cout << "Введите скорость (м/с)\t";
    cin >> speed;
    //Абсолютизация скорости (допустимо в физике)
    speed = abs(speed);

    cout << "Введите целое время (с)\t";
    cin >> time;

    //Проверка на отрицательное время
    if (time < 0)
    {
        cout << "Путешествия во времени не поддерживаются этой версией программы" << "\n";
        return 1;
    }

    // Точное расстояние, возможна унификация
    double distance_dbl{time * speed};
    // Округлённое расстояние, нет унификации из-за потери точности, явное преоброзование
    int distance_int = static_cast<int>(round(time * speed));

    //Вывод результатов
    cout << "Расстояние с точностью до тысячных:\t" << fixed << setprecision(3) << distance_dbl << "м" << endl;
    cout << "Округлённое расстояние:\t" << distance_int << "м" << "\n";

    return 0;
}