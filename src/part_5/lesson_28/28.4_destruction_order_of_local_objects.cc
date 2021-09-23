#include <iostream>

using namespace std;

struct StructA
{
    StructA()
    {
        cout << "StructA constructor" << endl;
    }
    ~StructA()
    {
        cout << "StructA destructor" << endl;
    }
};

struct StructB
{
    StructB()
    {
        cout << "StructB constructor" << endl;
    }
    ~StructB()
    {
        cout << "StructB destructor" << endl;
    }
};

void FuncB()
{
    cout << "In Func B" << endl;
    StructA objA;
    StructB objb;
    cout << "About to throw up!" << endl;
    throw "Throwing for the heck of it";
}

void FuncA()
{
    try
    {
        cout << "In Func A" << endl;
        StructA objA;
        StructB objb;
        FuncB(); // will throw
        // Calls destructor and this line won't be outputted
        cout << "FuncA: returning to caller" << endl;
    }
    // first one will catch the throw
    catch (const char *exp)
    {
        cout << "FuncA: Caught exception: " << exp << endl;
        cout << "Handled it, will not throw to caller" << endl;
        // throw; <<<< if uncommented this will be thrown to main()
    }
}

int main()
{
    cout << "main(): Started execution" << endl;
    try
    {
        FuncA();
    }
    catch (const char *exp)
    {
        cout << "Exception: " << exp << endl;
    }

    cout << "main(): exiting gracefully" << endl;

    return 0;
}
