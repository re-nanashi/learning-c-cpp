#include <iostream>

class SimpleCat
{
public:
    SimpleCat();
    ~SimpleCat();
    int GetAge() const { return *its_age_; }
    void SetAge(int age) { *its_age_ = age; }
    int GetWeight() const { return *its_weight_; }
    void SetWeight(int weight) { *its_weight_ = weight; }

private:
    int *its_age_;
    int *its_weight_;
};

SimpleCat::SimpleCat()
{
    its_age_ = new int(2);
    its_weight_ = new int(5);
}

SimpleCat::~SimpleCat()
{
    delete its_age_;
    delete its_weight_;
}

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