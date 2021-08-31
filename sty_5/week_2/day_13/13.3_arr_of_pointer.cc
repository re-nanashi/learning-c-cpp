#include <iostream>

class Cat
{
    public:
        Cat() {its_age_ = 1; its_weight_ = 5;}
        ~Cat() {}
        int GetAge() const {return its_age_;}
        int GetWeight() const {return its_weight_;}
        void SetAge(int age) {its_age_ = age;}

    private:
        int its_age_;
        int its_weight_;
};


int main()
{
    Cat * Family[500];
    int i;
    Cat * p_cat;
    for (i = 0; i < 500; ++i)
    {
        p_cat = new Cat;
        p_cat->SetAge((2*i) + 1);
        Family[i] = p_cat;
    }

    for (i=0; i<500; ++i)
    {
        std::cout << "Cat #" << i + 1 << ": ";
        std::cout << Family[i]->GetAge() << std::endl;
    }
    return 0;
}
