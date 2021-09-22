#include <algorithm>
#include <iostream>
#include <vector>

template <typename T> class Multiply
{
  public:
    T operator()(const T &elem1, const T &elem2)
    {
        return (elem1 * elem2);
    }
};

int main()
{
    using namespace std;

    vector<int> multiplicands{0, 1, 2, 3, 4};
    vector<int> multipliers{100, 101, 102, 103, 104};

    // a third container that holds the result of multiplication
    vector<int> vecResult;

    // make space for the result of the multiplication
    vecResult.resize(multipliers.size());
    transform(multiplicands.begin(), multiplicands.end(), multipliers.begin(), vecResult.begin(), Multiply<int>());

    cout << "The contents of the first vector are: " << endl;
    for (size_t index = 0; index < multiplicands.size(); ++index)
        cout << multiplicands[index] << ' ';
    cout << endl;

    cout << "The contents of the second vector are: " << endl;
    for (size_t index = 0; index < multipliers.size(); ++index)
        cout << multipliers[index] << ' ';
    cout << endl;

    cout << "The result of the multiplication is: " << endl;
    for (size_t index = 0; index < vecResult.size(); ++index)
        cout << vecResult[index] << ' ';
    cout << endl;

    return 0;
}
