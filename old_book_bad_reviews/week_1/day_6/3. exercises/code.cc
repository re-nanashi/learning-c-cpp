#include <iostream>

using namespace std;

class Employee
{
public:
    Employee(int age, int years_of_service, int salary);
    ~Employee() {}

    int GetAge() const { return its_age_; }
    int GetYearsOfService() const { return its_years_of_service_; }
    int GetSalary() const { return its_salary_; }

    void SetAge(int new_age) { its_age_ = new_age; }
    void SetYearsOfService(int new_years_of_service) { its_years_of_service_ = new_years_of_service; }
    void SetSalary(int new_salary) { its_salary_ = new_salary; }

    void EarningsReport();

private:
    int its_age_;
    int its_years_of_service_;
    int its_salary_;
};

Employee::Employee(int age, int years_of_service, int salary)
{
    its_age_ = age;
    its_years_of_service_ = years_of_service;
    its_salary_ = salary;
}

void Employee::EarningsReport()
{
    int rounded_salary = its_salary_ % 1000 >= 500 ? its_salary_ + 1000 - its_salary_ % 1000 : its_salary_ - its_salary_ % 1000;

    cout << "Earnings: " << rounded_salary << endl;
}

int main()
{
    Employee John(20, 2, 1000000);
    Employee Fabro(20, 1, 22499);

    cout << "John's age, years of service, and salary: ";
    cout << John.GetAge() << ", " << John.GetYearsOfService() << ", " << John.GetSalary() << "." << endl;

    cout << "Fabro's age, years of service, and salary: ";
    cout << Fabro.GetAge() << ", " << Fabro.GetYearsOfService() << ", " << Fabro.GetSalary() << "." << endl;

    John.EarningsReport();
    Fabro.EarningsReport();

    return 0;
}