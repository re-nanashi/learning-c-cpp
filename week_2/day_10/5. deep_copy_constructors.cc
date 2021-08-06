//Solution to shallow copy pointer problem
//PROBLEM: old_cat object and new_cat object both has a member variable that points to the same memory address
//To address the problem, create a copy constructor that creates a new allocation on heap memory.
//Copy the old value through public accessors of old object;

#include <iostream>

using namespace std;

class Cat
{
public:
    Cat();
    Cat(const Cat &);
    ~Cat();

    int GetAge() const { return *its_age_; }
    int GetWeight() const { return *its_weight_; }
    void SetAge(int age) { *its_age_ = age; }

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

//argument is a reference to the old object
Cat::Cat(const Cat &rhs)
{
    //Creates new pointer to allocate memory of deep object copy
    its_age_ = new int;
    its_weight_ = new int;
    *its_age_ = rhs.GetAge(); // public accessor from the original object
    *its_weight_ = *(rhs.its_weight_);
}

Cat::~Cat()
{
    delete its_age_;
    its_age_ = 0;

    delete its_weight_;
    its_weight_ = 0;
}

int main()
{
    Cat Frisky;
    cout << "Frisky's age: " << Frisky.GetAge() << endl;
    cout << "Setting Frisky to 6...\n";
    Frisky.SetAge(6);
    cout << "Creating Boots from Frisky\n";

    Cat Boots(Frisky);
    cout << "Frisky's age: " << Frisky.GetAge() << endl;
    cout << "Boots' age: " << Boots.GetAge() << endl;
    cout << "setting Frisky to 7...\n";
    Frisky.SetAge(7);

    cout << "Frisky's age: " << Frisky.GetAge() << endl;
    cout << "boot's age: " << Boots.GetAge() << endl;

    return 0;
}