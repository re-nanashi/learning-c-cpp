#include <bits/stdc++.h>

int main()
{
    int x, y, z;
    std::cin >> x >> y >> z;
    int arr[3] = {x, y, z};
    int len = sizeof(arr) / sizeof(arr[0]);
    if (!std::cin)
        std::cout
            << ("something went bad with the read");
    std::cout << "values read : " << x << ", " << y << ", " << z << '\n';

    //sort
    std::sort(arr, arr + len);

    std::cout << "values sorted : " << arr[0] << ", " << arr[1] << ", " << arr[2] << '\n';

    return 0;
}
