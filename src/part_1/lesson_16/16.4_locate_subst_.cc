#include <iostream>
#include <string>

int main()
{
    using std::cout;
    using std::endl;
    using std::string;

    string sampleStr{"Good day String! Today is beautiful!"};
    cout << "Sample string is: " << endl << sampleStr << endl << endl;

    // Find substring "day" - find() returns position
    size_t charPos = sampleStr.find("day", 0);

    // NOTE: search string::npos
    if (charPos != string::npos)
        cout << "First instance \"day\" at pos. " << charPos << endl;
    else
        cout << "Substring not found." << endl;

    cout << "Locating all instances of substring \"day\"" << endl;
    size_t subStrPos = sampleStr.find("day", 0);

    while (subStrPos != string::npos)
    {
        cout << "\"day\" found at position " << subStrPos << endl;

        // Make find() search forward forward the next character onwards
        size_t searchOffset = subStrPos + 1;

        subStrPos = sampleStr.find("day", searchOffset);
    }

    return 0;
}
