//Arrays
#include <iostream>

int main()
{
    int my_arr[5];
    int i;
    for (i = 0; i < 5; ++i)
    {
        std::cout << "Value for my_arr[" << i << "]; ";
        std::cin >> my_arr[i];
    }

    for (i = 0; i < 5; ++i)
    {
        std::cout << i << ": " << my_arr[i] << std::endl;
    }

    return 0;
}