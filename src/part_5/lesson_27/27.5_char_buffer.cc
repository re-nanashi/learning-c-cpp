#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Enter a line: " << endl;
    char charBuf[10] = {0};
    cin.get(charBuf, 9);
    cout << "charBuf: " << charBuf << endl;

    return 0;
}

/*
Enter a line:
Testing if I can cross the bounds of the buffer
charBuf: Testing i << 9 chars
*/
