#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

template <typename T> void DisplayContents(const T &container)
{
    for (auto element = container.cbegin(); element != container.cend(); ++element)
        cout << *element << ' ';
    cout << endl;
}

int main()
{
    vector<int> numsInVec{2017, 0, -1, 42, 10101, 25, 9, 9, 9};
    list<int> numsInList{-1, 42, 10101};

    cout << "The contents of the sample vector are: " << endl;
    DisplayContents(numsInVec);

    cout << "The contents of the sample list are: " << endl;
    DisplayContents(numsInList);

    cout << "search() for the contents of list in vector: " << endl;
    auto range = search(numsInVec.cbegin(), numsInVec.cend(), numsInList.cbegin(), numsInList.cend());

    if (range != numsInVec.end())
    {
        cout << "Sequence in list found in vector at position: ";
        cout << distance(numsInVec.cbegin(), range) << endl;
    }

    cout << "Searching {9, 9, 9} in vector using search_n(): " << endl;
    auto partialRange = search_n(numsInVec.cbegin(), numsInVec.cend(), 3, 9);

    if (partialRange != numsInVec.end())
    {
        cout << "Sequence {9, 9, 9} found in vector at position: ";
        cout << distance(numsInVec.cbegin(), partialRange) << endl;
    }
}
