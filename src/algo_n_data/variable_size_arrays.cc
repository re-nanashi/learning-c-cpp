#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define MAX 1000
using namespace std;

int main()
{
    int arr[MAX][MAX];
    int n, q, size, pos1, pos2;
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
    {
        cin >> size;
        for (int j = 0; j < size; ++j)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < q; ++i)
    {
        cin >> pos1 >> pos2;
        cout << arr[pos1][pos2] << "\n";
    }
    return 0;
}
