//Limitations on operator overloading
//built in types cannot be overloaded

#include <iostream>

using namespace std;

class Counter
{
public:
    Counter();
    Counter(int initial_value);
    ~Counter() {}
    int GetItsVal() const { return its_val_; }
    void SetItsVal(int new_val) { its_val_ = new_val; }
    // Counter Add(const Counter &);
    Counter operator+(const Counter &);

private:
    int its_val_;
};

Counter::Counter(int initial_value) : its_val_(initial_value) {}

Counter::Counter() : its_val_(0) {}

// Counter Counter::Add(const Counter &rhs)
// {
//     return Counter(its_val_ + rhs.GetItsVal());
// }

Counter Counter::operator+(const Counter &rhs)
{
    return Counter(its_val_ + rhs.GetItsVal());
}

int main()
{
    Counter var_one(2), var_two(4), var_three;
    // var_three = var_one.Add(var_two);
    var_three = var_one + var_two; //var_three = var_one.operator+(var_two);
    cout << "var_one: " << var_one.GetItsVal() << endl;
    cout << "var_two: " << var_two.GetItsVal() << endl;
    cout << "var_three: " << var_three.GetItsVal() << endl;

    return 0;
}