//Overriding a function is done by having a method from the base class
//and using it's name and signature in the derived class
//all other "overloaded" methods in base class will be hidden

#include <iostream>

using namespace std;

class Mammal
{
public:
    void Move() const { cout << "Mammal move one step.\n"; }
    void Move(int distance) const
    {
        cout << "Mammal move ";
        cout << distance << " steps. \n";
    }

protected:
    int its_age_;
    int its_weight_;
};

class Dog : public Mammal
{
public:
    void Move() const { cout << "Dog move 5 steps.\n"; }
    void MoveMammal() const;
};

void Dog::MoveMammal() const
{
    cout << "In dog move...\n";
    Mammal::Move(3);
}

int main()
{
    Mammal big_animal;
    Dog Momo;
    big_animal.Move();
    big_animal.Move(2);
    Momo.Move();
    //Momo.Move(10); compiler knows that momo's base class' method move(int) is hidden
    //to use hidden class method use a function that has Mammal::move(3);
    Momo.MoveMammal();

    return 0;
}