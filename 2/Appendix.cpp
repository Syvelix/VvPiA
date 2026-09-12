#include <iostream>
#include <cmath>

using std::cout, std::cin, std::endl;
int main()

{ 
double a = 0.1 + 0.2;
if (abs(a - 0.3) < 0.000001) 
{
    std::cout << "Равны";
} 
else 
{
    std::cout << "Не равны";
}
cout << endl;
}