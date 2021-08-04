#include <iostream>

using namespace std;
short Factor(int n, int *p_squared, int *p_cubed);

int main()
{
    int number, squared, cubed;
    short error;

    cout << "Enter a number (0 - 20): ";
    cin >> number;

    error = Factor(number, &squared, &cubed);

    //any type/int except 0 is true. therefore, if !0 == true
    if (!error)
    {
        cout << "number: " << number << endl;
        cout << "square: " << squared << endl;
        cout << "cubed: " << cubed << endl;
    }
    else
        cout << "Error encountered!!" << endl;

    return 0;
}

short Factor(int n, int *p_squared, int *p_cubed)
{
    short Value = 0;
    if (n > 20)
        Value = 1;
    else
    {
        *p_squared = n * n;
        *p_cubed = n * n * n;
        Value = 0;
    }

    return Value;
}