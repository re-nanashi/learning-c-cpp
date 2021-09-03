//C++ has a number of built-in types
//Add operators to own classes using operator overloading with return type **could also use void
//Prefix

#include <iostream>

using namespace std;

class Counter
{
public:
    Counter();
    ~Counter() {}
    int GetItsVal() const { return its_val_; }
    void SetItsVal(int new_value) { its_val_ = new_value; }
    //sample function for counting capability but cumbersome
    void Increment() { ++its_val_; }
    //Overloading operator function
    Counter operator++();

private:
    int its_val_;
};

Counter::Counter() : its_val_(0) {}

//Will return a counter object that has the current value
Counter Counter::operator++()
{
    ++its_val_;
    Counter temp;
    temp.SetItsVal(its_val_);
    return temp;
}

int main()
{
    Counter i;
    cout << "The value of i is " << i.GetItsVal() << endl;
    i.Increment();
    cout << "The value of i is " << i.GetItsVal() << endl;
    ++i;
    cout << "The value of i is " << i.GetItsVal() << endl;
    Counter a = ++i;
    cout << "The value of a is " << a.GetItsVal() << endl;
    cout << "The value of i is " << i.GetItsVal() << endl;

    return 0;
}