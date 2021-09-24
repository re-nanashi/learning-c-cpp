#include <algorithm>
#include <iostream>
#include <list>
#include <string>

using namespace std;

template <typename T> void DisplayContents(const T &cont)
{
    for (auto element = cont.cbegin(); element != cont.cend(); ++element)
        cout << *element << endl;
}

int main()
{
    list<string> names{"John", "Brad", "jack", "sean", "Anna"};

    cout << "Sorted contents of the list are: " << endl;
    names.sort();
    DisplayContents(names);

    cout << "Lowest index where \"Brad\" can be inserted is: ";
    list<string>::iterator minPos = lower_bound(names.begin(), names.end(), "Brad");
    cout << distance(names.begin(), minPos) << endl;

    cout << "Highest index where \"Brad\" can be inserted is: ";
    list<string>::iterator maxPos = upper_bound(names.begin(), names.end(), "Brad");
    cout << distance(names.begin(), maxPos) << endl;

    cout << endl;

    cout << "List after inserting Brad in sorted order: " << endl;
    names.insert(minPos, "Brad");
    DisplayContents(names);

    return 0;
}
