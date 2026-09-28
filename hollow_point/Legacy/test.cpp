#include <iostream>
#include <random>

using std::random_device, std::mt19937, std::uniform_int_distribution;


int main()
{

    int min = 0;
    int max = 100;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>dis(min, max);

    int i = dis(gen);
}
