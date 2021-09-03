#include <iostream>

int main()
{
    int mul_arr[2][5] = {{0,1,2,3,4}, {0,2,4,6,8}};

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            std::cout << "mul_arr[" << i << "][" << j << "]: ";
            std::cout << mul_arr[i][j] << std::endl;
        }
    }
    return 0;
}
