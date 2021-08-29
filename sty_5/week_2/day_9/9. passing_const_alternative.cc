#include <iostream>

using namespace std;

class Person
{
public:
    Person();
    Person(Person &);
    ~Person();

    int GetAge() const { return age_; }
    void SetAge(int age) { age_ = age; }

private:
    int age_;
};

Person::Person()
{
    cout << "Person Constructor..." << endl;
    age_ = 20;
}

Person::Person(Person &)
{
    cout << "Person Copy Constructor..." << endl;
}

Person::~Person()
{
    cout << "Person Destructor..." << endl;
}

//References cannot be reassigned therefore they are const already.
//const object only
const Person &FunctionTwo(const Person &the_person);

int main()
{
    cout << "Making a person..." << endl;
    Person John;
    cout << "John is " << John.GetAge() << " years old" << endl;

    int age = 21;

    John.SetAge(age);
    cout << "John is " << John.GetAge() << " years old" << endl;

    cout << "Calling FunctionTwo..." << endl;
    FunctionTwo(John);
    cout << "John is " << John.GetAge() << " years old" << endl;

    return 0;
}

const Person &FunctionTwo(const Person &the_person)
{
    cout << "FunctionTwo. Returning..." << endl;
    cout << "John is now " << the_person.GetAge() << " years old" << endl;

    return the_person;
}