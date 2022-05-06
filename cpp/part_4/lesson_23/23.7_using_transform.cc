#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    using namespace std;

    string str{"THIS is a TEst string!"};
    cout << "The sample string is: " << str << endl;

    string strLowerCaseCopy;
    strLowerCaseCopy.resize(str.size());

    /*
    You get undefined behaviour if the second sequence is shorter than the first one.
    Otherwise, if the second one is longer, nothing bad happens; the rest of the elements will simply be ignored.
    */
    transform(str.cbegin(), str.cend(), strLowerCaseCopy.begin(), ::tolower);

    cout << "Result of 'transform' on the string with 'tolower':" << endl;
    cout << "\"" << strLowerCaseCopy << "\"" << endl << endl;

    // Two sample vectors of integers...
    vector<int> numsInVec1{2017, 0, -1, 42, 10101, 25};
    vector<int> numsInVec2(numsInVec1.size(), -1);

    // A destination range for holding the result of addition
    deque<int> sumInDeque(numsInVec1.size());
    transform(numsInVec1.cbegin(), numsInVec1.cend(), numsInVec2.cbegin(), sumInDeque.begin(), plus<int>());

    cout << "Result of 'transform' using binary function 'plus': " << endl;
    cout << "Index Vector1 + Vector2 = Result (in Deque)" << endl;
    for (size_t index = 0; index < numsInVec1.size(); ++index)
    {
        cout << index << "   \t" << numsInVec1[index] << "\t+    ";
        cout << numsInVec2[index] << "\t+    ";
        cout << sumInDeque[index] << endl;
    }

    return 0;
}
