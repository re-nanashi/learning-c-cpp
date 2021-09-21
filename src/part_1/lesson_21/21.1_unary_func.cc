#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

// struct that behaves as a unary function
template <typename T> struct DisplayElement
{
    void operator()(const T &element) const
    {
        cout << element << ' ';
    }
};

int main()
{
    vector<int> numsInVec{0, 1, 2, 3, -1, -9, 0, -999};
    cout << "Vector of integers contains: " << endl;

    for_each(numsInVec.begin(), numsInVec.end(), DisplayElement<int>()); // Unary function object

    // Display the list of characters
    list<char> charsInList{'a', 'z', 'k', 'd'};
    cout << endl << "List of characters contains: " << endl;

    for_each(charsInList.begin(), charsInList.end(), DisplayElement<char>());

    return 0;
}
