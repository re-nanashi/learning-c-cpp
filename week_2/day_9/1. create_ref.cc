#include <iostream>

//Creating references
// int main()
// {
//     using namespace std;

//     int int_one;
//     int &r_some_ref = int_one;

//     int_one = 5;
//     cout << "int_one: " << int_one << endl;
//     cout << "r_some_ref: " << r_some_ref << endl;

//     r_some_ref = 7;
//     cout << "int_one: " << int_one << endl;
//     cout << "r_some_ref: " << r_some_ref << endl;

//     return 0;
// }

int main()
{
    using namespace std;

    int int_one;
    int &r_some_ref = int_one;

    int_one = 5;
    cout << "int_one: " << int_one << endl;
    cout << "r_some_ref: " << r_some_ref << endl;

    cout << "&int_one: " << &int_one << endl;
    cout << "&r_some_ref: " << &r_some_ref << endl;

    return 0;
}