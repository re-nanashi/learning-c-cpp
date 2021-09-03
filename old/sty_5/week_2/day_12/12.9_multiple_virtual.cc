#include <iostream>

using namespace std;

class Mammal
{
public:
    Mammal() : its_age_(1) {}
    virtual ~Mammal() {}
    virtual void Speak() const { cout << "Mammal speak!\n"; }

protected:
    int its_age_;
};

class Dog : public Mammal
{
public:
    void Speak() const { cout << "Woof!\n"; }
};

class Cat : public Mammal
{
public:
    void Speak() const { cout << "Meow!\n"; }
};

class Horse : public Mammal
{
public:
    void Speak() const { cout << "Winnie!\n"; }
};

class Pig : public Mammal
{
public:
    void Speak() const { cout << "Oink!\n"; }
};

int main()
{
    Mammal *arr[5];
    Mammal *pointer;
    int choice, i;
    //pointer's address changes as loop is iterated but is assigned to the array so pointer address is not lost
    for (i = 0; i < 5; ++i)
    {
        cout << "(1)dog (2)cat (3)horse (4)pig:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            pointer = new Dog;
            break;
        case 2:
            pointer = new Cat;
            break;
        case 3:
            pointer = new Horse;
            break;
        case 4:
            pointer = new Pig;
            break;
        default:
            pointer = new Mammal;
            break;
        }
        arr[i] = pointer;
        cout << "array address" << arr[i] << endl;
    }
    cout << pointer << endl;

    for (i = 0; i < 5; ++i)
    {
        arr[i]->Speak();
        cout << "old_pointer address is now in array" << arr[i] << endl;
    }
    cout << "pointer and last arr is same address: " << arr[4] << " " << pointer << endl;

    return 0;
}