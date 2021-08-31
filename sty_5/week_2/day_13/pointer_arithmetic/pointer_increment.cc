#include <iostream>

const int MAX = 3;

int main()
{
    int var[MAX]{10,100,200};
    int *ptr;

    ptr = var;

    for (int i = 0; i < MAX; ++i)
    {
        std::cout << "Address of var[" << i << "] = ";
        std::cout << ptr << std::endl;

        std::cout << "Value of var[" << i << "] = ";
        std::cout << *ptr << std::endl;

        ptr++;
    }
    
    return 0;
}
