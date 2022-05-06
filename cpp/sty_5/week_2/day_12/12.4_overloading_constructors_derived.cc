#include <iostream>

using namespace std;

enum BREED
{
    GOLDEN,
    CAIRN,
    DANDIE,
    SHETLAND,
    DOBERMAN,
    LAB
};

class Mammal
{
public:
    Mammal();
    Mammal(int age);
    ~Mammal();

    int GetAge() const { return its_age_; }
    void SetAge(int age) { its_age_ = age; }
    int GetWeight() const { return its_weight_; }
    void SetWeight(int weight) { its_weight_ = weight; }

    void Speak() const { cout << "Mammal sound!\n"; }
    void Sleep() const { cout << "shhh. I'm sleeping.\n"; }

protected:
    int its_age_;
    int its_weight_;
};

class Dog : public Mammal
{
public:
    Dog();
    Dog(int age);
    Dog(int age, int weight);
    Dog(int age, BREED breed);
    Dog(int age, int weight, BREED breed);
    ~Dog();

    BREED GetBreed() const { return its_breed_; }
    void SetBreed(BREED breed) { its_breed_ = breed; }

    void WagTail() const { cout << "Tail wagging...\n"; }
    void BegForFood() const { cout << "Begging for food....\n"; }

private:
    BREED its_breed_;
};

//Mammal default constructor
Mammal::Mammal() : its_age_(1), its_weight_(5)
{
    cout << "Mammal constructor..." << endl;
}

//Mammal overloaded constructor
Mammal::Mammal(int age) : its_age_(age), its_weight_(5)
{
    cout << "Mammal(int) constructor..." << endl;
}

Mammal::~Mammal()
{
    cout << "Mammal destructor..." << endl;
}

//Default mammal default dog
Dog::Dog() : Mammal(), its_breed_(GOLDEN)
{
    cout << "Dog constructor..." << endl;
}

Dog::Dog(int age) : Mammal(age), its_breed_(GOLDEN)
{
    cout << "Dog(int) constructor..." << endl;
}

Dog::Dog(int age, int weight) : Mammal(age), its_breed_(GOLDEN)
{
    its_weight_ = weight;
    cout << "Dog(int, int) constructor..." << endl;
}

Dog::Dog(int age, int weight, BREED breed) : Mammal(age), its_breed_(breed)
{
    its_weight_ = weight;
    cout << "Dog(int, int, BREED) constructor..." << endl;
}

Dog::Dog(int age, BREED breed) : Mammal(age), its_breed_(breed)
{
    cout << "Dog(int, BREED) constructor..." << endl;
}

Dog::~Dog()
{
    cout << "Dog destructor..." << endl;
}

int main()
{
    Dog Momo;
    Dog Jojo(19);
    Dog Miguel(19, 74);
    Dog Fabro(19, GOLDEN);
    Dog Jose(19, 74, DOBERMAN);
    Momo.Speak();
    Jojo.WagTail();
    cout << "Miguel is " << Miguel.GetAge() << " years old" << endl;
    cout << "Jose weighs " << Jose.GetWeight() << " kilograms" << endl;
    return 0;
}