#include <algorithm>
#include <iostream>
#include <string>

int main()
{
    using std::cout;
    using std::endl;
    using std::string;

    cout << "Please enter a string for case-convertion: " << endl;
    cout << "> ";

    string inStr;
    getline(std::cin, inStr);
    cout << endl;

    transform(inStr.begin(), inStr.end(), inStr.begin(), ::toupper);
    cout << "The string converted to upper case is: " << endl;
    cout << inStr << endl << endl;

    transform(inStr.begin(), inStr.end(), inStr.begin(), ::tolower);
    cout << "The string converted to lower case is: " << endl;
    cout << inStr << endl << endl;

    return 0;
}
