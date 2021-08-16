#include <iostream>

class SimpleCat
{
public:
    SimpleCat() { its_age_ = 2; }
    ~SimpleCat() {}
    int GetAge() const { return its_age_; }
    void SetAge(int age) { its_age_ = age; }

private:
    int its_age_;
};

int main()
{
    using namespace std;

    SimpleCat *frisky = new SimpleCat;

    cout << "Frisky is " << frisky->GetAge() << " years old " << endl;

    frisky->SetAge(5);
    cout << "Frisky is " << frisky->GetAge() << " years old " << endl;
    delete frisky;

    return 0;
}