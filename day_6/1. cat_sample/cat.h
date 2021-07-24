#include <iostream>

class Cat
{
public:
    Cat(int initial_age);
    ~Cat();
    int GetAge() const { return its_age_; }
    void SetAge(int age) { its_age_ = age; }
    void Meow() const { std::cout << "Meow.\n"; }

private:
    int its_age_;
};