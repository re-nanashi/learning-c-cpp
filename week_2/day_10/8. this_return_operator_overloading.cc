//Instead of using temp counter class use this

#include <iostream>

using namespace std;

class Counter
{
public:
    Counter();
    ~Counter() {}
    int GetItsVal() const { return its_val_; }
    void SetItsVal(int new_val) { its_val_ = new_val; }
    void Increment() { ++its_val_; }
    const Counter &operator++(); //returns a counter reference

private:
    int its_val_;
};

Counter::Counter() : its_val_(0) {}

//This should be a constant reference to block the possibility of using ++ twice by the same function scope; ++++a; on line 41;
//const on references refers to the object as constant unlike pointers
const Counter &Counter::operator++()
{
    ++its_val_;
    //"this" pointer is a hidden pointer to all member functions
    //that point to the object
    //Return the value of this with the current its_val_
    return *this;
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