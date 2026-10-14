//Вариант 13
#include <iostream>
using std::cout, std::endl;
#include <format>
using std::format;
#include <cmath>
using std::pow;
#include <random>
using std::random_device, std::mt19937, std::uniform_real_distribution, std::uniform_int_distribution;

int solveQuadratic(double a, double b, double c, double& x1, double& x2)
{
    double droot = pow(b*b - 4*a*c, 0.5);

    x1 = (b*-1 + droot) / 2*a;
    x2 = (b*-1 - droot) / 2*a;

    return 0;
}

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution disreal;
    uniform_int_distribution disint;

    double a = disint(gen) % 1000 + disreal(gen);
    double b = disint(gen) % 100 + disreal(gen);
    double c = (disint(gen) % 10000 + disreal(gen)) * -1;

    double x1{0}, x2{0};

    double& x1link = x1, x2link = x2;
    
    cout << format("a = {}, b = {}, c = {}\n\n", a, b, c);

    solveQuadratic(a,b,c,x1link,x2link);

    cout << format("x1 = {}, x2 ={}\n\n", x1link, x2link);

    return 0;
}