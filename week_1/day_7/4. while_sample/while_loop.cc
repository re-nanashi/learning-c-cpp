#include <iostream>

int main()
{
    using namespace std;
    unsigned short small;
    unsigned long large;

    const unsigned short MAXSMALL = 65535;

    cout << "Enter a small number: ";
    cin >> small;
    cout << "Enter a large number: ";
    cin >> large;

    cout << "small: " << small << "...";

    while (small < large && small < MAXSMALL)
    {
        if (small % 5000 == 0)
            cout << ".";

        ++small;
        large -= 2;
    }

    cout << "\nSmall: " << small << " Large: " << large << endl;

    return 0;
}
