#include <iostream>
#include <string>

int main()
{
    std::string sample_string{"Good day String! Today is beautiful!"};

    size_t letterAPos = sample_string.find('a', 0);
    std::cout << "Locating all instances of substring \"day\"" << std::endl;

    while (letterAPos != std::string::npos)
    {
        std::cout << "\"day\" found at position " << letterAPos << std::endl;

        // Make find() search forward forward the next character onwards
        size_t searchOffset = letterAPos + 1;

        letterAPos = sample_string.find("day", searchOffset);
    }
    return 0;
}
