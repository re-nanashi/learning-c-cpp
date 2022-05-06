#include <iostream>
#include <string>

int main()
{
    std::string sample_string{"Good day String! Today is beautiful!"};

    std::cout << "Locating all instances of substring \"a\"" << std::endl;
    std::size_t a_pos = sample_string.find('a', 0);

    while (a_pos != std::string::npos)
    {
        std::cout << "\"a\" is found at position " << a_pos << std::endl;

        // Add 1 to the current a_pos to offset
        size_t search_offset = a_pos + 1;

        a_pos = sample_string.find('a', search_offset);
    }

    return 0;
}
