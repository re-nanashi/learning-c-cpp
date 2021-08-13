//"Slicing" is where you assign an object of a derived class to an instance of a base class, thereby losing part of the information

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

void ValueFunc(Mammal);
void PointerFunc(Mammal *);
void RefFunc(Mammal &);

int main()
{
    Mammal *ptr = 0;
    int choice;
    while (1)
    {
        bool f_quit = false;
        cout << "(1)dog (2)cat (0)Quit: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            f_quit = true;
            break;
        case 1:
            ptr = new Dog;
            break;
        case 2:
            ptr = new Cat;
            break;
        default:
            ptr = new Mammal;
            break;
        }

        if (f_quit == true)
            break;

        PointerFunc(ptr);
        RefFunc(*ptr);
        ValueFunc(*ptr);
        cout << ptr << endl;
    }

    return 0;
}

void ValueFunc(Mammal MammalValue)
{
    MammalValue.Speak();
}

void PointerFunc(Mammal *p_mammal)
{
    p_mammal->Speak();
}

void RefFunc(Mammal &r_mammal)
{
    r_mammal.Speak();
}