#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T> struct IsMultiple
{
    T Divisor;

    IsMultiple(const T &divisor)
    {
        Divisor = divisor;
    }

    bool operator()(const T &element) const
    {
        // Check if the Divisor is a multiple of the divisor
        return ((element % Divisor) == 0);
    }
};

int main()
{
    vector<int> numsInVec{25, 26, 27, 28, 29, 30, 31};
    cout << "The vector contains: 25,26,27, 28, 29, 30, 31" << endl;

    cout << "Enter divisor (> 0): ";
    int divisor = 2;
    cin >> divisor;

    // Find the first element hat is a multiple of divisor
    auto element = find_if(numsInVec.begin(), numsInVec.end(), IsMultiple<int>(divisor));

    if (element != numsInVec.end())
    {
        cout << "First element in vector divisible by " << divisor;
        cout << ": " << *element << endl;
    }

    return 0;
}
