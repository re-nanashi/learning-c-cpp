#include <iostream>

const int MAX = 3;

int main ()
{
    int var[MAX]{10,100,200};
    int *ptr;

    ptr = &var[MAX-1];

    for (int i = MAX; i > 0; --i)
    {
        std::cout << "Address of var[" << i << "] = ";
        std::cout << ptr << std::endl;

        std::cout << "Value of var[" << i << "] = ";
        std::cout << *ptr << std::endl;

        ptr--;
    }

    return 0;
}
