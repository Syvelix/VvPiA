#include <iostream>
using std::cin, std::cout, std::getline, std::stoi, std::endl;
#include <format>
using std::format;
#include <random>
using std::random_device, std::mt19937, std::uniform_int_distribution;
#include <vector>
using std::vector;
#include <array>
using std::array;
#include <string>
using std::string;

const int ROWS = 4;
const int COLUMS = 4;

//Выдаёт вектор полных локальных минимумов
vector<array<int, 2>> matrix_mins(int matrix[ROWS][COLUMS])
{
    vector<array<int, 2>> mins;
    for (int r = 1; r < ROWS - 1; r ++)
    {
        for (int c = 1; c < COLUMS - 1; c++)
        {
            int now = matrix[r][c];
            if (now < matrix[r-1][c] &&
            now < matrix[r+1][c] &&
            now < matrix[r][c+1] &&
            now < matrix[r][c-1])
            {
                mins.push_back({r, c});
            }
        }
    }
    return mins;
}

//Получение строки из матрицы интов
string pretty_matrix(int matrix[ROWS][COLUMS])
{ 
    string str_matr{"{\n"};

    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLUMS; c++)
        {
            str_matr += format(" {}", matrix[r][c]);
        }
        str_matr += "\n";
    }
    str_matr += " }";
    return str_matr;
}

int main()
{
    int matrix[ROWS][COLUMS];

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>dis(-100, 100);

    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLUMS; c++)
        {
            matrix[r][c] = dis(gen);
        }
    }

    cout << format("Матрица\n{}", pretty_matrix(matrix)) << endl;

    vector<array<int, 2>> mins = matrix_mins(matrix);

    cout << "Локальные минимумы:\n";
    for (int el = 0; el < mins.size(); el++)
    {
        cout << format("{}:{} - {},\n", mins[el][0]+1, mins[el][1]+1, matrix[mins[el][0]][mins[el][1]]);
    }

    cout << endl << endl;

}