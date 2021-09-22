#include <iostream>
#include <map>
#include <string>

using namespace std;

template <typename T> void DisplayContents(const T &cont)
{
    for (auto element = cont.cbegin(); element != cont.cend(); ++element)
        cout << element->first << " -> " << element->second << endl;
    cout << endl;
}

int main()
{
    multimap<int, string> mmapIntToStr;

    mmapIntToStr.insert(make_pair(3, "Three"));
    mmapIntToStr.insert(make_pair(45, "Forty Five"));
    mmapIntToStr.insert(make_pair(-1, "Minus One"));
    mmapIntToStr.insert(make_pair(1000, "Thousand"));
    mmapIntToStr.insert(make_pair(1000, "Thousand"));

    cout << "The multimap contains " << mmapIntToStr.size();
    cout << " key-value pairs. They are: " << endl;

    // Print the contents of the map to the screen
    DisplayContents(mmapIntToStr);

    cout << "Enter the key you wish to find: ";
    int key{0};
    cin >> key;

    multimap<int, string>::const_iterator pairFound = mmapIntToStr.find(key);
    // Check if find() succeeded
    if (pairFound != mmapIntToStr.end())
    {
        // Find the number of pairs that have the same supplied key
        size_t numPairsInMap = mmapIntToStr.count(key);

        for (size_t counter = 0; counter < numPairsInMap; ++counter)
        {
            cout << "Key: " << pairFound->first;
            cout << ", Value [" << counter << "] = ";
            cout << pairFound->second << endl;

            ++pairFound; // Increment iterator
        }
    }
    else
        cout << "Sorry, pair with key " << key << " not in map" << endl;

    return 0;
}
