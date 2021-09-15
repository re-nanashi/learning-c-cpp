#include <iostream>
#include <string>

int main()
{
    const char *constCstyleString = "Hello String!";
    std::cout << "Constant string is; " << constCstyleString << std::endl;

    std::string strFromConst{constCstyleString};
    std::cout << "strFromConst is: " << strFromConst << std::endl;

    std::string str2{"Hello string!"};
    std::string str2Copy{str2};
    std::cout << "str2Copy is: " << str2Copy << std::endl;

    // Initialize a string to the first 5 characters of another
    std::string strPartialCopy{constCstyleString, 5};
    std::cout << "strPartialCopy is: " << strPartialCopy << std::endl;

    // Initialize a string object to contain 10 'a's
    std::string strRepeatChars{10, 'a'};
    std::cout << "strRepeat Chars is: " << strRepeatChars << std::endl;

    return 0;
}
