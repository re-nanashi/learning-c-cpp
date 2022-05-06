#include <iostream>

using namespace std;

class Mammal
{
public:
    Mammal() : its_age_(1) { cout << "Mammal constructor...\n"; }
    virtual ~Mammal() { cout << "Mammal destructor...\n"; }
    void Move() const { cout << "Mammal move one step\n"; }
    virtual void Speak() const { cout << "Mammal speak!\n"; }

protected:
    int its_age_;
};

class Dog : public Mammal
{
public:
    Dog() { cout << "Dog constructor...\n"; }
    virtual ~Dog() { cout << "Dog destructor...\n"; }
    void WagTail() { cout << "Wagging Tail...\n"; }
    void Speak() const { cout << "Woof!\n"; }
    void Move() const { cout << "Dog moves 5 steps...\n"; }
};

int main()
{
    Mammal *p_dog = new Dog;
    //compiler knows that move() is non virtual therefore it calls the mammal class' move method
    p_dog->Move();
    //compilter knows that speak is virtual which will eventually be overridden thus even tho this is a mammal pointer it calls derived class' speak()
    p_dog->Speak();

    return 0;
}