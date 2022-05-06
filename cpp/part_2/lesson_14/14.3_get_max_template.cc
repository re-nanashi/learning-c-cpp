#include <iostream>
#include <string>

template <typename T> const T &GetMax(const T &value1, const T &value2)
{
    if (value1 > value2)
        return value1;
    else
        return value2;
}

template <typename T> void DisplayComparison(const T &value1, const T &value2)
{
    using std::cout;

    cout << "GetMax(" << value1 << ", " << value2 << ") = ";
    cout << GetMax(value1, value2) << std::endl;
}

int main()
{
    int num1 = -101, num2 = 2011;
    DisplayComparison<int>(num1, num2);

    double d1 = 3.14, d2 = 3.1416;
    DisplayComparison<double>(d1, d2);

    std::string name1("Jack"), name2("John");
    DisplayComparison<std::string>(name1, name2);

    return 0;
}
