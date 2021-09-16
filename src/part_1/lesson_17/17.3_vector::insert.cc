/*
Although vector::insert() is a versatile function, push_back() should be your
preferred way of adding elements to a vector. This is because insert() is an inefficient
way to add elements to the vector (when adding in a position that is not the end of the
sequence) because adding elements in the beginning or the middle makes the vector
class shift all subsequent elements backward (after making space for the last ones at the end).
Thus, depending on the type of the objects contained in the sequence, the cost of
this shift operation can be significant in terms of the copy constructor or copy assignment operator invoked.
In our little sample, the vector contains objects of type int that
are relatively inexpensive to move around. This might not be the case in many other uses
of the vector class.
 * */
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void DisplayVector(const vector<int> &inVec)
{
    for (vector<int>::const_iterator element = inVec.begin(); element != inVec.end(); ++element)
        cout << *element << ' ';
    cout << endl;
}

int main()
{
    // Instantiate a vector with 4 elements, each initialized to 90
    vector<int> integers(4, 90);

    cout << "The initial contents of the vector: ";
    DisplayVector(integers);

    // Insert 25 at the beginning
    integers.insert(integers.begin(), 25);

    // Insert 2 numbers of value 45 at the end
    integers.insert(integers.end(), 2, 45);

    cout << "Vector after inserting elements at beginning and end: ";
    DisplayVector(integers);

    // Another vector containing 2 elements of value 30
    vector<int> another(3, 30);

    // Insert three elements from another container in position [1]
    integers.insert(integers.begin() + 1, another.begin(), another.end());

    cout << "Vector after inserting contents from another vector: ";
    cout << "in the middle:" << endl;
    DisplayVector(integers);

    return 0;
}
