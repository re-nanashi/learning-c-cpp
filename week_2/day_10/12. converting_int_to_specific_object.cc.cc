#include <iostream>

using namespace std;

class Counter
{
public:
    Counter();
    Counter(int val);
    ~Counter() {}
    int GetItsVal() const { return its_val_; }
    void SetItsVal(int new_val) { its_val_; }

private:
    int its_val_;
};

Counter::Counter() : its_val_(0) {}

Counter::Counter(int val) : its_val_(val) {}

int main()
{
    int the_int = 5;
    Counter the_counter = the_int;

    cout << "the_counter: " << the_counter.GetItsVal() << endl;
    return 0;
}
