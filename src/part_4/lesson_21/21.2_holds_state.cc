#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T> struct DisplayElementKeepCount
{
    int count;

    DisplayElementKeepCount() : count(0)
    {
    } // constructor

    void operator()(const T &element)
    {
        ++count;
        cout << element << ' ';
    }
};

int main()
{
    vector<int> numsInVec{22, 2017, -1, 999, 43, 901};
    cout << "Displaying the vector of integers: " << endl;

    DisplayElementKeepCount<int> result; // constructor is called and count is apointed to 0
    result = for_each(numsInVec.begin(), numsInVec.end(), DisplayElementKeepCount<int>());

    cout << endl << "Function invoked " << result.count << " times" << endl;

    return 0;
}
