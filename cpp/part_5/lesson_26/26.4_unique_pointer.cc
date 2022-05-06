#include <iostream>
#include <memory> // include this to use std::unique_ptr

class Fish
{
  public:
    Fish()
    {
        std::cout << "Fish: Constructed!" << std::endl;
    }
    ~Fish()
    {
        std::cout << "Fish: Destructed!" << std::endl;
    }

    void Swim() const
    {
        std::cout << "Fish swims in water" << std::endl;
    }
};

void MakeFishSwim(const std::unique_ptr<Fish> &inFish)
{
    inFish->Swim();
}

int main()
{
    std::unique_ptr<Fish> smartFish(new Fish);

    smartFish->Swim();
    MakeFishSwim(smartFish);

    std::unique_ptr<Fish> copySmartFish;
    // copySmartFish = smartFish  << error: operator = is private

    return 0;
}
