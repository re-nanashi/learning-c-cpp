#include <iostream>
#include <string>

int main()
{
    const std::string hexdigits = "0123456789ABCDEF";
    std::cout << "Enter a series of numbers between 0 and 15 separated by spaces.";
    std::cout << " Hit ENTER when finished: " << std::endl;
    std::string result;
    std::string::size_type n;
    while (std::cin >> n)
        if (n < hexdigits.size())
            result += hexdigits[n];
    std::cout << "Your hex number is: " << result << std::endl;

    return 0;
}

// Input: 12 0 5 15 8 15
// Ouput: C05F8F
