#include <iostream>

using namespace std;

// int main()
// {
//     char ch = 'a';

//     do
//     {
//         cout << ch << " ";
//         ch++;
//     } while (ch <= 'z');

//     return 0;
// }

int main()
{
    int x = 0;
    do
        cout << "X: " << x++ << endl;
    while (x < 10);

    return 0;
}