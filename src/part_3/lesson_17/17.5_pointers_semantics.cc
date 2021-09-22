#include <iostream>
#include <vector>

int main()
{
    std::vector<int> integers{50, 1, 987, 1001};

    std::vector<int>::const_iterator element = integers.cbegin();

    while (element != integers.end())
    {
        size_t index = distance(integers.cbegin(), element);
        std::cout << "Element at position ";
        std::cout << index << " is: " << *element << std::endl;

        // move to the next element
        ++element;
    }

    return 0;
}
