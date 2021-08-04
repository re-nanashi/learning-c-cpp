#include <iostream>

class SimpleCat
{
public:
    SimpleCat(int age, int weight);
    ~SimpleCat() {}
    int GetAge() { return its_age_; }
    int GetWeight() { return its_weight_; }

private:
    int its_age_;
    int its_weight_;
};

SimpleCat::SimpleCat(int age, int weight)
{
    its_age_ = age;
    its_weight_ = weight;
}

int main()
{
    SimpleCat frisky(5, 8);
    SimpleCat &rCat = frisky;

    std::cout << "frisky is: " << frisky.GetAge() << " years old." << std::endl;
    std::cout << "and frisky weighs: " << rCat.GetWeight() << " pounds." << std::endl;

    return 0;
}