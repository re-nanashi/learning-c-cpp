#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

double getMeanDistance(std::vector<double> const &);
double sum(std::vector<double> const &);

int main()
{
    double input{0.0};
    std::vector<double> distances;

    std::cout << "Input distances along a given route in m\n";
    while (std::cin >> input)
    {
        distances.push_back(input);
    }
    std::sort(distances.begin(), distances.end());
    std::cout << "Total distance: " << sum(distances) << "\n";
    std::cout << "Smallest distance: " << distances[0] << "\n";
    std::cout << "Greatest distance: " << distances[distances.size() - 1] << "\n";
    std::cout << "Mean distance: " << getMeanDistance(distances) << "\n";

    return 0;
}

double getMeanDistance(std::vector<double> const &r_array)
{
    int mid = r_array.size() / 2;
    if (r_array.size() % 2 == 0)
    {
        return (r_array[mid] + r_array[mid + 1]) / 2;
    }
    else
    {
        return r_array[mid];
    }
}

double sum(std::vector<double> const &r_array)
{
    double sum{0.0};

    for (int i = 0; i < r_array.size(); ++i)
    {
        sum += r_array[i];
    }

    return sum;
}