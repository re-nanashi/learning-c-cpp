#include <iostream>

typedef unsigned short int USHORT;

int main()
{
    using namespace std;

    USHORT my_age;
    USHORT *p_age = 0;

    my_age = 5;

    cout << "my_age: " << my_age << endl;
    p_age = &my_age;
    cout << "*p_age: " << *p_age << endl
         << endl;

    cout << "Setting *p_age = 7" << endl;
    *p_age = 7;

    cout << "*p_age: " << *p_age << endl;
    cout << "my_age: " << my_age << endl
         << endl;

    cout << "Setting my_age = 9..." << endl;
    my_age = 9;

    cout << "my_age: " << my_age << endl;
    cout << "*p_age: " << *p_age << endl;

    return 0;
}