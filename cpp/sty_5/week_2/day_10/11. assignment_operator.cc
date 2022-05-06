//Assignment operator
//Prevents var_one = var_one as the left deletes itself first

#include <iostream>

using namespace std;

class Cat
{
public:
    Cat();
    //copy constructor and destructor elided
    int GetAge() const { return *its_age_; }
    int GetWeight() const { return *its_weight_; }
    void SetAge(int age) { *its_age_ = age; }
    Cat &operator=(const Cat &);

private:
    int *its_age_;
    int *its_weight_;
};

Cat::Cat()
{
    its_age_ = new int;
    its_weight_ = new int;
    *its_age_ = 5;
    *its_weight_ = 9;
}

Cat &Cat::operator=(const Cat &rhs)
{
    //If the same object is assigned to itself it will return it self pointer
    if (this == &rhs)
        return *this;
    //Else get the object values that are being copied through public accessors
    //Copy to allocated member pointer so that it doesnt point at the same address
    *its_age_ = rhs.GetAge();
    *its_weight_ = rhs.GetWeight();
    return *this;
}

int main()
{
    Cat Frisky;
    cout << "Frisky's age: " << Frisky.GetAge() << endl;
    cout << "Setting Frisky to 6...\n";

    Frisky.SetAge(6);

    Cat Whiskers;
    cout << "Whiskers's age: " << Whiskers.GetAge() << endl;
    cout << "Copying Frisky to Whiskers...\n";

    Whiskers = Frisky;
    cout << "Whisker's age: " << Whiskers.GetAge() << endl;

    return 0;
}