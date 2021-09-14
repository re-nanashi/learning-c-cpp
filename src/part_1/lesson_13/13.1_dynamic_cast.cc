#include <iostream>

class Fish
{
  public:
    virtual void Swim()
    {
        std::cout << "Fish swims in water" << std::endl;
    }

    virtual ~Fish()
    {
    }
};

class Tuna : public Fish
{
  public:
    void Swim()
    {
        std::cout << "Tuna swims real fast in the sea" << std::endl;
    }

    void BecomeDinner()
    {
        std::cout << "Tuna became dinner in Sushi" << std::endl;
    }
};

class Carp : public Fish
{
  public:
    void Swim()
    {
        std::cout << "Carp swims real slow in the lake" << std::endl;
    }

    void Talk()
    {
        std::cout << "Carp talked crap!" << std::endl;
    }
};

void DetectFishType(Fish *objFish)
{
    // The return value of a dynamic_cast operation should always be checked for validity. It is null when cast fails
    Tuna *objTuna = dynamic_cast<Tuna *>(objFish);
    if (objTuna)
    {
        std::cout << "Detected Tuna. Making Tuna dinner: " << std::endl;
        objTuna->BecomeDinner();
    }

    Carp *objCarp = dynamic_cast<Carp *>(objFish);
    if (objCarp)
    {
        std::cout << "Detected Carp. Making carp talk: " << std::endl;
        objCarp->Talk();
    }

    std::cout << "Verifying type using virtual Fish::Swim: " << std::endl;
    objFish->Swim();
}

int main()
{
    Carp myLunch;
    Tuna myDinner;

    DetectFishType(&myDinner);
    std::cout << std::endl;
    DetectFishType(&myLunch);

    return 0;
}
