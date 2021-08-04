#include <iostream>

int main()
{
    using namespace std;

    int v_int;
    int *p_int = 0;

    p_int = &v_int;

    *p_int = 40;

    cout << v_int << endl;

    return 0;
}
