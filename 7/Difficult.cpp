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
#include <cmath>
using std::pow;

const int ROWS = 4;
const int COLUMNS = 4;

//Рекурсивная функция для вычисления миноров, самопис, есть возможность масштабирования размеров матрицы
vector<vector<int>> cut_it(vector<vector<int>> to_cut, int row, int column)
{
    if (row >= to_cut.size())
    {
        row--;
    }
    if (column >= to_cut[row].size())
    {
        column--;
    }

    vector<vector<int>> newvector;

    for (int r = 0; r < to_cut.size(); r++)
    {
        if (r == row)
        {
            continue;
        }
            
        vector<int> curr_row;
        for (int c = 0; c < to_cut[r].size(); c++)
        {
            if (c == column)
            {
                continue;
            }
            curr_row.push_back(to_cut[r][c]);
        }

        newvector.push_back(curr_row);
    }

    return newvector;
}

//Вычисление определителя (работает для матриц размерами не меньше 3x3, остальное по задаче и не нужно)
int determinant(vector<vector<int>> matrix)
{
    if (matrix.size() == 3)
    {
        if (matrix.size() == 3)
    {
        int main_diag =
            matrix[0][0] * matrix[1][1] * matrix[2][2];

        int main_triag1 =
            matrix[0][1] * matrix[1][2] * matrix[2][0];

        int main_triag2 =
            matrix[0][2] * matrix[1][0] * matrix[2][1];

        int second_diag =
            matrix[0][2] * matrix[1][1] * matrix[2][0];

        int second_triag1 =
            matrix[0][0] * matrix[1][2] * matrix[2][1];

        int second_triag2 =
            matrix[0][1] * matrix[1][0] * matrix[2][2];

        return main_diag + main_triag1 + main_triag2
             - second_diag - second_triag1 - second_triag2;
    }
    }

    int result = 0;

    for (int c = 0; c < matrix.size(); c++)
    {
        vector<vector<int>> minor = cut_it(matrix, 0, c);

        int degree = (c % 2 == 0) ? 1 : -1;

        result += matrix[0][c] * determinant(minor) * degree;
    }

    return result;
}


//Первичные идеи
/*int appendix (int matrix[ROWS][COLUMNS], int row, int column)
{
    vector<vector<int>> temp_vector;

    for (int r = 0; r < ROWS; r++)
    {
        vector<int> curr_row;
        for (int c = 0; c < COLUMNS; c++)
        {
            curr_row.push_back(matrix[r][c]);
        }
        temp_vector.push_back(curr_row);
    }

    while (temp_vector.size() != 3)
    {
        temp_vector = cut_it(temp_vector, row, column);
        row += 1;
        column += 1;
    }

    int degree = pow(-1, row + column);

    int main_diag = temp_vector[0][0] * temp_vector[1][1] * temp_vector[2][2];
    int main_triag1 = temp_vector[0][1] * temp_vector[1][2] * temp_vector[2][0];
    int main_triag2 = temp_vector[0][2] * temp_vector[1][0] * temp_vector[2][1];
    int main_star = main_diag + main_triag1 + main_triag2;

    int second_diag = temp_vector[0][2] * temp_vector[1][1] * temp_vector[2][0];
    int second_triag1 = temp_vector[0][0] * temp_vector[1][2] * temp_vector[2][1];
    int second_triag2 = temp_vector[0][1] * temp_vector[1][0] * temp_vector[2][2];
    int second_star = second_diag + second_triag1 + second_triag2;

    return (main_star - second_star) * degree;
}   */

/*array<array<int, ROWS>, COLUMNS> appendix_array(int matrix[ROWS][COLUMNS])
{
    array<array<int, ROWS>, COLUMNS> appendixies;

    for (int r = 0; r < ROWS; r++)
    {
        array<int, ROWS> curr_row;
        for (int c = 0; c < COLUMNS; c++)
        {
            curr_row[c] = appendix(matrix, r, c);
        }
        appendixies[r] = curr_row;
    }

    return appendixies;
}*/


//Получение строки из матрицы интов
string pretty_matrix(vector<vector<int>> matrix)
{ 
    string str_matr{"{\n"};

    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLUMNS; c++)
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
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>dis(1,20);
    int matrix[ROWS][COLUMNS];

    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLUMNS; c++)
        {
            matrix[r][c] = dis(gen);
        }
    }

    vector<vector<int>> matrvec;

    for (int r = 0; r < ROWS; r++)
    {
        vector<int> curr_row;
        for (int c = 0; c < COLUMNS; c++)
        {
            curr_row.push_back(matrix[r][c]);
        }
        matrvec.push_back(curr_row);
    }

    cout << format("Матрица: {}\n", pretty_matrix(matrvec));

    cout << format("Определитель: {}", determinant(matrvec)) << endl;

    return 0;
}