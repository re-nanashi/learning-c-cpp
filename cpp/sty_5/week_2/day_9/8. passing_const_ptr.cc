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
    age_ = 10;
}

Person::Person(Person &)
{
    cout << "Person Copy Constructor..." << endl;
}

Person::~Person()
{
    cout << "Person Destructor..." << endl;
}

const Person *const FunctionTwo(const Person *const the_person);

int main()
{
    cout << "Making a person..." << endl;
    Person John;
    cout << "John is ";
    cout << John.GetAge() << " years old" << endl;

    int age = 20;

    John.SetAge(20);
    cout << "John is " << John.GetAge() << " years old" << endl;

    cout << "Calling FunctionTwo..." << endl;
    FunctionTwo(&John);
    cout << "John is " << John.GetAge() << " years old" << endl;

    return 0;
}

const Person *const FunctionTwo(const Person *const the_person)
{
    cout << "Function Two. Returning..." << endl;
    cout << "John is now " << the_person->GetAge()
         << " years old " << endl;
    return the_person;
}