#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> numsInVec{25, 4, 101, 2017, -50};

    auto evenNum = find_if(numsInVec.cbegin(), numsInVec.cend(), [](const int &num) { return ((num % 2) == 0); });

    if (evenNum != numsInVec.cend())
    {
        int evenNumCount =
            count_if(numsInVec.cbegin(), numsInVec.cend(), [](const auto &element) { return ((element % 2) == 0); });

        for (int i = 0; i < evenNumCount; ++i)
        {
            cout << "Even number in collection is: " << *evenNum++ << endl;
        }
    }

    return 0;
}
