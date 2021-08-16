#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

void ratio(int, int);

int main()
{
    std::cout << "Please enter two int: \n";
    int val1, val2;
    std::cin >> val1 >> val2;

    std::cout << std::string(val1 < val2 ? "val1 is smaller than val2" : "val2 is smaller than val1") << std::endl;
    std::cout << std::string(val1 < val2 ? "val2 is larger than val1" : "val1 is larger than val1") << std::endl;
    std::cout << "val1 and val2 has a sum of: " << (val1 + val2) << std::endl;
    std::cout << "val1 and val2 has a difference of: " << (val1 - val2) << std::endl;
    std::cout << "val1 and val2 has a product of: " << (val1 * val2) << std::endl;
    ratio(val1, val2);

    return 0;
}

int GCD(int val1, int val2)
{
    int gcf;
    if (val2 > val1)
    {
        int temp = val2;
        val2 = val1;
        val1 = temp;
    }

    for (int i = 1; i <= val2; ++i)
    {
        if (val1 % i == 0 && val2 % i == 0)
            gcf = i;
    }

    return gcf;
}

void ratio(int val1, int val2)
{
    int gcd = GCD(val1, val2);
    int x = val1 / gcd;
    int y = val2 / gcd;

    std::cout << "The ratio of val1 and val2 is: " << x << ":" << y << std::endl;
}