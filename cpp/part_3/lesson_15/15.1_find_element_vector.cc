#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    // Dynamic array
    std::vector<int> intVector;

    // Insert sample integers into the array
    intVector.push_back(50);
    intVector.push_back(2991);
    intVector.push_back(23);
    intVector.push_back(9999);

    std::cout << "The contents of the vector are: " << std::endl;

    // Walk the vector and read values using an iterator
    std::vector<int>::iterator arrIterator = intVector.begin();

    // begin() = first element : end() = after the last element
    while (arrIterator != intVector.end())
    {
        // Write the value to the screen
        std::cout << *arrIterator << std::endl;

        // Increment the iterator to access the next element
        ++arrIterator;
    }

    // return val if found and last element if not
    std::vector<int>::iterator elFound = std::find(intVector.begin(), intVector.end(), 2991);

    // Check if value was found
    if (elFound != intVector.end())
    {
        int elPos = distance(intVector.begin(), elFound);
        std::cout << "Value " << *elFound << " found in the vector position: ";
        std::cout << elPos << std::endl;
    }

    return 0;
}
