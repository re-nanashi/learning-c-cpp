#include <iostream>
#include <list>

template <typename T> void DisplayContents(const T &container)
{
    for (typename T::const_iterator element = container.cbegin(); element != container.cend(); ++element)
    {
        std::cout << typeid(element).name() << std::endl;
        std::cout << *element << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::list<int> linkInts{-101, 42};

    linkInts.push_front(10);
    linkInts.push_front(2011);
    linkInts.push_back(-1);
    linkInts.push_back(9999);

    DisplayContents(linkInts);

    return 0;
}
