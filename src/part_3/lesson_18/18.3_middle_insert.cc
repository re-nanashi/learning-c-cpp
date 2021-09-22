#include <iostream>
#include <list>

template <typename T> void DisplayContents(const T &container)
{
    for (typename T::const_iterator element = container.cbegin(); element != container.cend(); ++element)
        std::cout << *element << ' ';
    std::cout << std::endl;
}

int main()
{
    std::list<int> linkInts1;

    // Inserting elements at the beginning...
    linkInts1.insert(linkInts1.begin(), 2);
    linkInts1.insert(linkInts1.begin(), 2);

    // Inserting an element at the end ...
    linkInts1.insert(linkInts1.end(), 3);

    std::cout << "The contents of list 1 after inserting elements: " << std::endl;
    DisplayContents(linkInts1);

    std::list<int> linkInts2;

    // Inserting 4 element of the same value 0...
    linkInts2.insert(linkInts2.begin(), 4, 0);

    std::cout << "The contents of list 2 after inserting '";
    std::cout << linkInts2.size() << " ' elements of a value:" << std::endl;
    DisplayContents(linkInts2);

    std::list<int> linkInts3(linkInts1);
    std::list<int>::iterator it = linkInts2.begin();
    advance(it, 2);

    linkInts2.insert(it, linkInts1.begin(), linkInts1.end());

    std::cout << "The contents of list 2 after inserting the contents of ";
    std::cout << "list 1 at the postion 2:" << std::endl;
    DisplayContents(linkInts2);

    linkInts3.insert(linkInts3.end(), linkInts2.begin(), linkInts2.end());

    std::cout << "The contents of list 3 after inserting the contents of ";
    std::cout << "list 2 at the end:" << std::endl;
    DisplayContents(linkInts3);

    return 0;
}
