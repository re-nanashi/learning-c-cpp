#include <iostream>

int main()
{
    using namespace std;

    int local_variable = 5;
    int *p_local = &local_variable;
    int *p_heap = new int;

    *p_heap = 7;

    cout << "local_variable: " << local_variable << endl;
    cout << "*p_local: " << *p_local << endl;
    cout << "*p_heap: " << *p_heap << endl;

    delete p_heap;

    p_heap = new int;
    *p_heap = 9;

    cout << "*p_heap: " << *p_heap << endl;
    delete p_heap;

    return 0;
}