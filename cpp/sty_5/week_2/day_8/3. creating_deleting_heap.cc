#include <iostream>

using namespace std;

class SimpleCat
{
public:
    SimpleCat();
    ~SimpleCat() { cout << "Destructor called. " << endl; }

private:
    int its_age_;
};

SimpleCat::SimpleCat()
{
    cout << "Constructor called. " << endl;
    its_age_ = 1;
}

int main()
{
    cout << "SimpleCat Frisky..." << endl;
    SimpleCat frisky;
    cout << "SimpleCat *p_rags = new SimpleCat..." << endl;
    SimpleCat *p_rags = new SimpleCat;
    cout << "Delete p_rags..." << endl;
    delete p_rags;
    cout << "Exiting, watch frisky go..." << endl;

    return 0;
}
