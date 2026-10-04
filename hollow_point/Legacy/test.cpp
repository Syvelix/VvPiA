#include <iostream>
#include <random>
#include <string>
#include <bitset>
using namespace std;


int main()
{
    string test = "ааб b";
    u32string newtest;

    for (int i = 0; i < test.size(); i++)
    {
        bitset<8> bits(test[i]);

        if (bits[7] != 0)
        {
            cout << test[i] << test[i+1];
            i++;
        }
        else
        {
            cout << test[i];
        }

    }

    
}


