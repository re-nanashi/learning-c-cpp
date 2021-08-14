#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

double getMedianTemperature(std::vector<double> &r_temp);

int main()
{
    std::vector<double> temps;
    for (double temp; std::cin >> temp;)
        temps.push_back(temp);

    // compute mean temperature:
    double sum{0.0};
    for (double x : temps)
        sum += x;
    std::cout << "Average temperature: " << sum / temps.size() << '\n';

    // compute median temperature:
    std::sort(temps.begin(), temps.end());
    std::cout << "Median temperature: " << getMedianTemperature(temps) << '\n';

    return 0;
}

double getMedianTemperature(std::vector<double> &r_temp)
{
    int mid = r_temp.size() / 2;
    if (r_temp.size() % 2 == 0)
    {
        return double((r_temp[mid] + r_temp[mid + 1]) / 2);
    }
    else
    {
        return double(r_temp[mid]);
    }
}