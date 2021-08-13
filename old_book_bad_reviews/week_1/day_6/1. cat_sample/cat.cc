#include "cat.h"

using namespace std;

Cat::Cat(int initial_age)
{
    its_age_ = initial_age;
}

Cat::~Cat()
{
}

int main()
{
    Cat Frisky(5);
    Frisky.Meow();
    cout << "Firsky is a cat who is ";
    cout << Frisky.GetAge() << " years old.\n";
    Frisky.Meow();
    Frisky.SetAge(7);
    cout << "Now Frisky is ";
    cout << Frisky.GetAge() << " years old.\n";
    return 0;
}