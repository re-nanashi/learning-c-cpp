#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

const std::vector<std::string> legal_units{"cm", "m", "in", "ft"};

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

double convert_to_m(double, std::string);
void value_checker(double, double &, double &);

int main()
{
    double value{0.0};
    std::string unit{" "};
    std::vector<double> values_array;
    double smallest_so_far{0.0}, largest_so_far{0.0};
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

double convert_to_m(double value, std::string unit)
{
    constexpr double cm_convert = 1.0 / 100;
    constexpr double in_convert = 2.54 * cm_convert;
    const double ft_convert = 12.0 * in_convert;

    if (unit == "cm")
    {
        return (value * cm_convert);
    }
    else if (unit == "in")
    {
        return (value * in_convert);
    }
    else if (unit == "ft")
    {
        return (value * ft_convert);
    }
    else
        return value;
}

void value_checker(double val, double &r_smallest, double &r_largest)
{
    if (r_smallest == 0.0 && r_largest == 0.0)
    {
        r_smallest = val;
        r_largest = val;
        std::cout << "first loop so " << val << " is both the largest and smallest\n";
    }
    if (val < r_smallest)
    {
        std::cout << "Value entered is the smallest so far\n";
        r_smallest = val;
    }
    if (val > r_largest)
    {
        std::cout << "Value entered is the largest so far\n";
        r_largest = val;
    }
}