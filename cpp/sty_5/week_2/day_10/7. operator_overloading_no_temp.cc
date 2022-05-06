//Alternative solution for creating temp object to return value
//Uses constructor overloading + namesless

#include <iostream>

using namespace std;

class Counter
{
public:
    Counter();
    Counter(int new_val);
    ~Counter() {}
    int GetItsVal() const { return its_val_; }
    void SetItsVal(int x) { its_val_ = x; }
    void Increment() { ++its_val_; }
    Counter operator++();

private:
    int its_val_;
};

Counter::Counter() : its_val_(0) {}

Counter::Counter(int new_val) : its_val_(new_val) {}

Counter Counter::operator++()
{
    ++its_val_;
    return Counter(its_val_);
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