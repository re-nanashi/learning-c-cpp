#include <iostream>
#include <vector>

int main()
{
    // vector of int
    std::vector<int> var;

    // vector initialized using c++11 list initialization
    std::vector<int> initVar{202, 2017, -1};
    // Instantiate a vector  with 10 elements
    std::vector<int> tenElements(10);
    // Instantiate a vector  with 10 elements, each initialized to 90
    std::vector<int> tenElemInit(10, 90);
    // Instantiate a vector  to the contents of another
    std::vector<int> copyVector{tenElemInit};
    // Vector initialized to 5 elements from another using iterators
    std::vector<int> partialCopy{tenElements.cbegin(), tenElements.cbegin() + 5};

    for (int i = 0; i < 5; ++i)
    {
        std::cout << partialCopy[i] << std::endl;
    }

    return 0;
}
