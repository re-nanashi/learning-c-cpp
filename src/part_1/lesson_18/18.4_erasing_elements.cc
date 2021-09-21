#include <iostream>
#include <list>
using namespace std;

template <typename T> void DisplayContents(const T &container)
{
    for (auto element = container.cbegin(); element != container.cend(); ++element)
        cout << *element << ' ';
    cout << endl;
}

int main()
{
    list<int> linkInts{4, 3, 5, -1, 2017};

    auto val2 = linkInts.insert(linkInts.begin(), 2);

    cout << "Initial contents of the list: " << endl;
    DisplayContents(linkInts);

    cout << "After erasing element '" << *val2 << "':" << endl;
    linkInts.erase(val2);
    DisplayContents(linkInts);

    linkInts.erase(linkInts.begin(), linkInts.end());
    cout << "Number of elements after erasing range: ";
    cout << linkInts.size() << endl;

    return 0;
}
