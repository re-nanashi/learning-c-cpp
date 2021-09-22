#include <iostream>
#include <tuple>

int main()
{
    // Initialize a tuple
    std::tuple<int, std::string> person(20, "Tim");
    // Getting a value from tuple
    std::cout << std::get<1>(person);
    // Changing value of a tuple
    std::get<1>(person) = "Billy";

    // Making a tuple
    std::tuple<int, char, bool, float> thing;
    thing = std::make_tuple(23, 'H', true, 24.3);
    // size of the tuple
    // auto len = std::tuple_size<decltype(thing)>::value;

    // swapping tuples for same no.type and elements
    std::tuple<int, int> t1 = std::make_tuple(1, 2);
    std::tuple<int, int> t2 = std::make_tuple(3, 4);
    t1.swap(t2);

    // decompse tuple and assign to variables
    std::tuple<int, int> t3 = std::make_tuple(1, 2);
    int x, y;
    std::tie(y, x) = t3;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << std::get<0>(t3) << std::endl;
    std::cout << std::get<1>(t3) << std::endl;
    std::cout << "Hello" << std::endl;

    // Simpler method of decomposing
    auto tup = std::make_tuple(1, "hello");
    auto [z, p] = tup;
    std::cout << "C++17: " << z << p << std::endl;

    // tuple concatenation
    std::tuple<int, char> t4(20, 't');
    std::tuple<char, std::string> t5('r', "hello world!");
    std::tuple<int, char, char, std::string> t6 = tuple_cat(t4, t5);
    // auto t6 = tuple_cat(t4, t5);

    return 0;
}
