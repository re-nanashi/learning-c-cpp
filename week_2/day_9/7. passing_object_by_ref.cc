#include <iostream>

using namespace std;

//Simple class with a copy constructor
class SimpleCat
{
public:
    SimpleCat();
    SimpleCat(SimpleCat &);
    ~SimpleCat();
};

SimpleCat::SimpleCat()
{
    cout << "Simple Cat Constructor..." << endl;
}

SimpleCat::SimpleCat(SimpleCat &)
{
    cout << "Simple Cat Copy Constructor..." << endl;
}

SimpleCat::~SimpleCat()
{
    cout << "Simple Cat Destructor..." << endl;
}

SimpleCat FunctionOne(SimpleCat the_cat);
SimpleCat *FunctionTwo(SimpleCat *the_cat);

int main()
{
    cout << "Making a cat..." << endl;
    SimpleCat frisky; //SimpleCat Constructor is called
    cout << "Calling FunctionOne..." << endl;
    FunctionOne(frisky); //SimpleCat is copied to the function so copy constructor is called
    //FunctionOne returns a SimpleCat Object, calling copy constructor then destructs
    //SimpleCat copy in function is destroyed thus destructor is called.
    cout << "Calling FunctionTwo..." << endl;
    FunctionTwo(&frisky);
    //Only message is Function two returns
    //Simple Cat destructor is called on the first object instance on line 35.
    return 0;
}

SimpleCat FunctionOne(SimpleCat the_cat)
{
    cout << "Function One. Returning..." << endl;
    return the_cat;
}

SimpleCat *FunctionTwo(SimpleCat *the_cat)
{
    cout << "Function Two. Returning..." << endl;
    return the_cat;
}

//Console log
/*
Making a cat...
Simple Cat Constructor...
Calling FunctionOne...
Simple Cat Copy Constructor...
Function One. Returning...
Simple Cat Copy Constructor...
Simple Cat Destructor...
Simple Cat Destructor...
Calling FunctionTwo...
Function Two. Returning...
Simple Cat Destructor...
*/