#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

template <typename T> void DisplayContents(const T &cont)
{
    for (auto element = cont.cbegin(); element != cont.cend(); ++element)
        cout << *element << ' ';
    cout << " | Number of elements: " << cont.size() << endl;
}

int main()
{
    list<int> numsInList{2017, 0, -1, 42, 10101, 25};

    cout << "Source (list) contains: " << endl;
    DisplayContents(numsInList);

    // Initialize vector to hold 2x elements as the list
    vector<int> numsInVec(numsInList.size() * 2);

    // start source and end source then dest range
    auto lastElement = copy(numsInList.cbegin(), numsInList.cend(), numsInVec.begin());

    // copy odd numbers from list into vector
    copy_if(numsInList.cbegin(), numsInList.cend(), lastElement, [](int element) { return ((element % 2) != 0); });

    cout << "Destination (vector) after copy and copy_if:" << endl;
    DisplayContents(numsInVec);

    // Sample copy_backward
    std::vector<int> from_vector;
    for (int i = 0; i < 10; ++i)
    {
        from_vector.push_back(i);
    }

    // 15 size
    std::vector<int> to_vector(15);

    std::copy_backward(from_vector.begin(), from_vector.end(), to_vector.end());

    std::cout << "to vector contains: ";
    for (auto i : to_vector)
    {
        std::cout << i << " ";
    }
    cout << endl;

    // Remove all instances of '0', resize vector using erase()
    auto newEnd = remove(numsInVec.begin(), numsInVec.end(), 0);
    numsInVec.erase(newEnd, numsInVec.end());

    newEnd = remove_if(numsInVec.begin(), numsInVec.end(), [](int element) { return ((element % 2) != 0); });

    numsInVec.erase(newEnd, numsInVec.end());

    cout << "Destination (vector) after remove, remove_if, erase: " << endl;
    DisplayContents(numsInVec);

    return 0;
}
