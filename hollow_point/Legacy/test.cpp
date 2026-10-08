#include <iostream>
#include <random>
#include <string>
#include <bitset>
using namespace std;


int main()
{
    string s = "AAAABBAAB";
    string neww(s.size(), ' ');
    for (int i = 0; i < s.size(); i++)
    {
        neww[i] = s[s.size()-i];
    }   

    cout << neww;
}


