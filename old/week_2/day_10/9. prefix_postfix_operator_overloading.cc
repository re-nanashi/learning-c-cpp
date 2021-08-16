//Post fix operator overloading

#include <iostream>

using namespace std;

class Counter
{
public:
    Counter();
    ~Counter() {}
    int GetItsVal() const { return its_val_; }
    void SetItsVal(int new_val) { its_val_ = new_val; }
    const Counter &operator++();   //prefix
    const Counter operator++(int); //postfix

private:
    int its_val_;
};

Counter::Counter() : its_val_(0) {}

const Counter &Counter::operator++()
{
    ++its_val_;
    return *this;
}

const Counter Counter::operator++(int the_flag)
{
    Counter temp(*this);
    ++its_val_;
    return temp;
}

int main()
{
    Counter i;
    cout << "The value of i is " << i.GetItsVal() << endl;
    i++;
    cout << "The value of i is " << i.GetItsVal() << endl;
    ++i;
    cout << "The value of i is " << i.GetItsVal() << endl;

    Counter a = ++i;
    cout << "The value of a is " << a.GetItsVal() << endl;
    cout << "The value of i is " << i.GetItsVal() << endl;

    a = i++;
    cout << "The value of a is " << a.GetItsVal() << endl;
    cout << "The value of i is " << i.GetItsVal() << endl;

    return 0;
}