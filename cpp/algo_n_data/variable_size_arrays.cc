#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    // pointer to pointer
    // allocate an array of n int pointers
    int **vec = new int *[n];
    for (int i = 0; i < n; ++i)
    {
        int s;
        cin >> s;
        // allocate an array of s int pointer
        int *b = new int[s];
        for (int j = 0; j < s; ++j)
        {
            cin >> b[j];
        }
        // assign the b pointer to vec[i]
        *(vec + i) = b;
    }

    for (int i = 0; i < q; ++i)
    {
        cout << vec[i][0] << endl;
    }

    return 0;
}
