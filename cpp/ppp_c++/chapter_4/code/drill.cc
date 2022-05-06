#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

constexpr double cm_to_m{0.01};
constexpr double in_to_m{2.54 * cm_to_m};
constexpr double ft_to_m{12.0 * in_to_m};
const std::vector<std::string> legal_units{"cm", "m", "in", "ft"};

bool legalUnit(std::string unit);
double convert_to_m(double, std::string);
void printLegalUnits();
void value_checker(double n, double &, double &);

int main()
{
    std::cout << "Enter a double value followed by a unit with or without a space in between (followed by 'Enter'):\n";
    double value{0.0};
    std::string unit{" "};
    std::vector<double> values_array;
    double smallest_so_far = 0.0;
    double largest_so_far = 0.0;
    double sum = {0.0};
    int counter = 0;

    while (std::cin >> value >> unit)
    {
        if (legalUnit(unit))
        {
            std::cout << "Value entered: " << value << unit << "\n";
            double converted_value = convert_to_m(value, unit);

            values_array.push_back(converted_value);
            value_checker(converted_value, smallest_so_far, largest_so_far);

            sum += converted_value;
            ++counter;
        }
        else
        {
            std::cout << "Error: no legal unit. Enter one of \n";
            break;
        }
    }
    std::cout << "Largest: " << largest_so_far << "meters (converted)\n";
    std::cout << "Smallest: " << smallest_so_far << "meters (converted)\n";
    std::cout << "Number of values: " << counter << " values were entered.\n";
    std::cout << "Sum of values: " << sum << "meters.\n";

    std::sort(values_array.begin(), values_array.end());

    for (int i = 0; i < values_array.size(); ++i)
    {
        std::cout << values_array[i] << " meters.\n";
    }

    return 0;
}

bool legalUnit(std::string unit)
{
    bool legal = false;
    for (auto legal_unit : legal_units)
    {
        if (unit == legal_unit)
        {
            legal = true;
        }
    }
    return legal;
}

double convert_to_m(double value, std::string unit)
{
    if (unit == "cm")
    {
        return (value * cm_to_m);
    }
    else if (unit == "in")
    {
        return (value * in_to_m);
    }
    else if (unit == "ft")
    {
        return (value * ft_to_m);
    }
    else
        return value;
}

void value_checker(double val, double &small, double &large)
{
    if (small == 0.0 && large == 0.0)
    {
        small = val;
        large = val;
        std::cout << "first loop so " << val << " is both the largest and smallest\n";
    }
    if (val < small)
    {
        std::cout << "Value entered is the smallest so far\n";
        small = val;
    }
    if (val > large)
    {
        std::cout << "Value entered is the largest so far\n";
        large = val;
    }
}

void printLegalUnits()
{
    std::cout << "\tcm for centimeters\n"
              << "\tm for meters\n"
              << "\tin for inches\n"
              << "\tft for feet\n";
}
