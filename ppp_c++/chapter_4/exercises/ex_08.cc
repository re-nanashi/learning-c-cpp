#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
    double on_square{1};
    double sum{0};
    std::cout << "Square" << '\t' << "Grains" << '\t' << "Total\n";
    for (int square = 1; square <= 64; ++square)
    {
        sum += on_square;
        std::cout << square << '\t' << on_square << '\t' << sum << std::endl;
        on_square *= 2;
    }

    return 0;
}
