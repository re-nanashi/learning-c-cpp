#include <iostream>
#include <string>
#include <tuple>

template <typename tupleType> void DisplayTupleInfo(tupleType &tup)
{
    const int numMembers = std::tuple_size<tupleType>::value;
    std::cout << "Num elements in tuple: " << numMembers << std::endl;
    std::cout << "Last element value: " << std::get<numMembers - 1>(tup) << std::endl;
}

int main()
{
    std::tuple<int, char, std::string> tup1(std::make_tuple(101, 's', "Hello Tuple!"));
    DisplayTupleInfo(tup1);

    auto tup2(std::make_tuple(3.14, false));
    DisplayTupleInfo(tup2);

    auto concatTup(tuple_cat(tup2, tup1));
    DisplayTupleInfo(concatTup);

    double pi;
    std::string sentence;
    std::tie(pi, std::ignore, std::ignore, std::ignore, sentence) = concatTup;
    std::cout << "Unpacked! Pi: " << pi << " and \" " << sentence << "\"" << std::endl;

    return 0;
}
