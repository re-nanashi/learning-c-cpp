#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define MAX 1000
using namespace std;

int main()
{
    // int n, q;
    // cin >> n >> q;
    // vector<int> *arr = new vector<int>[n];
    // for (int i = 0; i < n; ++i)
    //{
    //    int vec_size(0), input(0);
    //    cin >> vec_size;
    //    for (int j = 0; j < vec_size && cin >> input; ++j)
    //    {
    //        arr[i].push_back(input);
    //    }
    //}
    // for (int i = 0; i < n; ++i)
    //{
    //    for (int j = 0; i < arr[i].size(); ++j)
    //    {
    //        cout << arr[i][j] << endl;
    //    }
    //}

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
