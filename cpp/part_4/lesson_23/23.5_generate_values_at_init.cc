#include <algorithm>
#include <ctime>
#include <iostream>
#include <list>
#include <vector>

int main()
{
    using namespace std;
    srand(time(NULL)); // seed random generator using time

    vector<int> nums_in_vec(5);
    // generate uses the end() iterator
    generate(nums_in_vec.begin(), nums_in_vec.end(), rand); // generator function

    cout << "Elements in the vector are: ";
    for (size_t index = 0; index < nums_in_vec.size(); ++index)
        cout << nums_in_vec[index] << ' ';
    cout << endl;

    list<int> nums_in_list(5);
    // generate_n uses number of elements to be generated
    generate_n(nums_in_list.begin(), 3, rand);

    cout << "Elements in the list are: ";
    for (auto element = nums_in_list.begin(); element != nums_in_list.end(); ++element)
        cout << *element << ' ';

    return 0;
}
