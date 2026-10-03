#include <iostream>
#include <random>

using std::random_device, std::mt19937, std::uniform_int_distribution;


int main()
{

    int arr[5] = {1, 2, 3, 4, 5};
for (int i = 0; i <= 5; i++) {
    std::cout << arr[i];
arr[i] = 0;
}

}
