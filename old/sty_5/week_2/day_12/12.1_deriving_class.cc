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
    ~Mammal();

    int GetAge() const;
    void SetAge(int);
    int GetWeight() const;
    void SetWeight();

    void Speak() const;
    void Sleep() const;

protected:
    int its_age_;
    int its_weight_;
};

class Dog : public Mammal
{
public:
    Dog();
    ~Dog();

    BREED GetBreed() const;
    void SetBreed(BREED);

    void WagTail();
    void BegForFood();

protected:
    BREED its_breed_;
};