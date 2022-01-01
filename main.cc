#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int x = 1;
int z = x + 3; // 4
int f(int y)
{
    return x + y;
}

int main()
{
    int x = 2;
    int y = 2;
    int result = f(z + y); // (4 + 2) + 1 not

    std::cout << result << std::endl;
    std::cout << z << std::endl;

    return 0;
}
