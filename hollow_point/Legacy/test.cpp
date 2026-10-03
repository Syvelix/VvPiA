#include <iostream>
#include <random>

using std::random_device, std::mt19937, std::uniform_int_distribution;


int main()
{

    int m[3][3] = {0};
    for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
m[i][j] = i + j;
}
    }
    std::cout << m[2][2];
}


