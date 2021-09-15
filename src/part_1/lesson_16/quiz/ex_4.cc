#include <iostream>
#include <string>

int main()
{
    std::string resultingString{""};
    std::string stringObj[4]{"I", "Love", "STL", "String"};

    for (int i = 0; i < 4; ++i)
    {
        resultingString.append(stringObj[i]).append(1, ' ');
    }

    std::cout << resultingString << std::endl;

    return 0;
}
