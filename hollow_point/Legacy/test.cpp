#include <iostream>
#include <format>
#include <filesystem>
#include <cmath>

using std::cout, std::cin, std::endl, std::format, std::fabs;

int main()
{

    
    for (double x = 0; fabs(x - 1) > 0.000000001; x += 0.1) 
    {
        std::cout << x << std::endl;
    }
}
