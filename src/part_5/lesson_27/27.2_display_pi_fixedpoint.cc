#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    const double PI{(double)22.0 / 7};
    cout << "Pi = " << PI << endl;

    cout << endl << "Setting precision to 7: " << endl;
    cout << setprecision(7);
    cout << "Pi = " << PI << endl;
    cout << fixed << "Fixed Pi = " << PI << endl;
    cout << scientific << "Scientific Pi = " << PI << endl;

    cout << endl << "Setting precision to 10: " << endl;
    cout << setprecision(10);
    cout << "Pi = " << PI << endl;
    cout << fixed << "Fixed Pi = " << PI << endl;
    cout << scientific << "Scientific Pi = " << PI << endl;

    cout << endl << "Enter a radius";
    double radius{0.0};
    cin >> radius;
    cout << "Area of circle: " << 2 * PI * radius * radius << endl;

    return 0;
}
