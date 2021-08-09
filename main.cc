#include <iostream>

using namespace std;

class SimpleCircle
{
public:
    SimpleCircle();
    SimpleCircle(int);
    //Copy constructor
    SimpleCircle(const SimpleCircle &);
    ~SimpleCircle();

    void SetRadius(int);
    int GetRadius() const;

    //operators
    const SimpleCircle &operator++();
    const SimpleCircle operator++(int);
    SimpleCircle &operator=(const SimpleCircle &);

private:
    int *its_radius_;
};

SimpleCircle::SimpleCircle()
{
    its_radius_ = new int(5);
}

SimpleCircle::SimpleCircle(int radius)
{
    its_radius_ = new int(radius);
}

SimpleCircle::SimpleCircle(const SimpleCircle &rhs)
{
    int val = rhs.GetRadius();
    its_radius_ = new int(val);
}

SimpleCircle &SimpleCircle::operator=(const SimpleCircle &rhs)
{
    if (this == &rhs)
        return *this;

    delete its_radius_;
    its_radius_ = new int;
    *its_radius_ = rhs.GetRadius();
    return *this;
}

const SimpleCircle &SimpleCircle::operator++()
{
    ++(*its_radius_);
    return *this;
}

const SimpleCircle SimpleCircle::operator++(int)
{
    SimpleCircle temp(*this);
    ++(*its_radius_);
    return temp;
}

int SimpleCircle::GetRadius() const
{
    return *its_radius_;
}

SimpleCircle::~SimpleCircle()
{
    delete its_radius_;
}

int main()
{
    SimpleCircle CircleOne, CircleTwo(9);
    CircleOne++;
    ++CircleTwo;

    cout << "Circle one:" << CircleOne.GetRadius() << endl;
    cout << "Circle two:" << CircleTwo.GetRadius() << endl;

    CircleOne = CircleTwo;

    cout << "Circle one:" << CircleOne.GetRadius() << endl;
    cout << "Circle two:" << CircleTwo.GetRadius() << endl;

    return 0;
}