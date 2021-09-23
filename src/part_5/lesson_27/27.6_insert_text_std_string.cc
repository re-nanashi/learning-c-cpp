#include <iostream>
#include <string>

using namespace std;

// int main()
//{
//    cout << "Enter your name: ";
//    string name;
//    cin >> name;
//    cout << "Hi " << name << endl;
//
//    return 0;
//}

/*
Enter your name: Siddartha Rao
Hi Siddhartha <<<<<< only the first letter was get
*/

int main()
{
    cout << "Enter your name: ";
    string name;
    getline(cin, name);
    cout << "Hi " << name << endl;

    return 0;
}

/*
Enter your name: Siddartha Rao
Hi Siddhartha Rao <<<<<< only the first letter was get
*/
