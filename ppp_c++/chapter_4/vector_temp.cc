#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
    std::vector<double> temps;

    for (double temp; std::cin >> temp;)
        temps.push_back(temp);

    double sum = 0;
    for (int x : temps)
        sum += x;

    std::cout << "Average temperature: " << sum / temps.size() << "\n";

    std::sort(temps.begin(), temps.end());

    //size divided by 2 to get the mid
    std::cout << "Median temperature: " << temps[temps.size() / 2] << "\n";

    return 0;
}