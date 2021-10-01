#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int size, q_size, q;
    cin >> size;
    vector<int> vec;
    int input;
    for (int i = 0; i < size; ++i)
    {
        cin >> input;
        vec.push_back(input);
    }

    cin >> q_size;
    for (int i = 0; i < q_size; ++i)
    {
        cin >> q;
        auto find_q = find(vec.cbegin(), vec.cend(), q);
        if (find_q != vec.cend())
        {
            cout << "Yes " << (find_q - vec.begin()) + 1 << endl;
        }
        else
        {
            find_q = find_if(vec.begin(), vec.end(), [&q](int ele) { return ele > q; });
            cout << "No" << (find_q - vec.begin()) + 1 << endl;
        }
    }

    return 0;
}
