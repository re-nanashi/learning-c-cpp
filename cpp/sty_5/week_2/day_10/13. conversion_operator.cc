//To solve the conversion back to a different type from objects

#include <iostream>

using namespace std;

class Counter
{
public:
    Counter();
    Counter(int val);
    ~Counter() {}
    int GetItsVal() const { return its_val_; }
    void SetItsVal(int x) { its_val_ = x; }
    //returns into
    operator unsigned int();

private:
    int its_val_;
};

Counter::Counter() : its_val_(0) {}

Counter::Counter(int val) : its_val_(val) {}

Counter::operator unsigned int()
{
    return (int(its_val_));
}

int main()
{
    Counter ctr(5);
    int the_int = ctr;
    cout << "the_int: " << the_int << endl;
    return 0;
}