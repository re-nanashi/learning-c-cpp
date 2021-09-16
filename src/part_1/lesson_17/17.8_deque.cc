#include <algorithm>
#include <deque>
#include <iostream>

int main()
{
    // Define a deque of integers
    std::deque<int> intDeque;

    // Insert integers at the bottom of the array
    intDeque.push_back(3);
    intDeque.push_back(4);
    intDeque.push_back(5);

    // Insert integers at the bottom of the array
    intDeque.push_front(2);
    intDeque.push_front(1);
    intDeque.push_front(0);

    std::cout << "The contents of the deque after inserting elements ";
    std::cout << "at the top and bottom are:" << std::endl;

    // Display content on the screen
    for (size_t count = 0; count < intDeque.size(); ++count)
    {
        std::cout << "Element [" << count << "] = ";
        std::cout << intDeque[count] << std::endl;
    }

    std::cout << std::endl;

    // Erase an element at the top
    intDeque.pop_front();

    // Erase an element at the bottom
    intDeque.pop_back();

    std::cout << "The contents of the deque after erasing an element ";
    std::cout << "from the top and bottom are:" << std::endl;

    // Display contents again: this time using iterators
    // if on older compilers, remove auto and uncomment next line
    for (std::deque<int>::iterator element = intDeque.begin(); element != intDeque.end(); ++element)
    {
        size_t offset = distance(intDeque.begin(), element);
        std::cout << "Element [" << offset << "] = " << *element << std::endl;
    }

    return 0;
}
