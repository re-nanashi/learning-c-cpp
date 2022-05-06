#include <iostream>
#include <vector>

template <typename T> void DisplayVector(const std::vector<T> &inVec)
{
    // for (std::vector<T>::const_iterator <<< missing typename
    for (auto element = inVec.cbegin(); element != inVec.cend(); ++element)
        std::cout << *element << ' ';
    std::cout << std::endl;
}

int main()
{
    std::vector<int> integers;

    // Insert sample integers into the vector
    integers.push_back(50);
    integers.push_back(1);
    integers.push_back(987);
    integers.push_back(1001);

    std::cout << "Vector contains " << integers.size() << " elements: ";
    DisplayVector(integers);

    // Erase one element at the end
    integers.pop_back();

    std::cout << "After a call to pop_back()" << std::endl;
    std::cout << "Vector contains " << integers.size() << " elements: ";
    DisplayVector(integers);

    return 0;
}
