#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> integers{50, 1, 987, 1001};

    for (size_t index = 0; index < integers.size(); ++index)
    {
        cout << "Element [" << index << "] = ";
        cout << integers[index] << endl;
    }

    integers[2] = 2011;
    cout << "After replacement: " << endl;
    cout << "Elemenent[2] = " << integers[2] << endl;

    return 0;
}

/*
A safer alternative is to use the at() member function:

// gets element at position 2
cout < < integers.at (2);

// the vector::at() version of the code above in
Listing 17.4, line 11:
cout < < integers.at(index);

at() performs a runtime check against the size() of the
container and throws an exception if you cross the boundaries
(which you shouldn’t anyway).
Subscript operator ([]) is safe when used in a manner that
ensures bound integrity, as in the earlier example.<< inte
 * */
