#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

bool condition_is_met(std::string name_input, int score_input)
{

    if (name_input == "NoName" && score_input == 0)
    {
        return false;
    }

    return true;
}

bool is_valid(std::vector<std::string> const &r_vector, std::string name_input)
{
    if (r_vector.size() == 0)
    {
        return true;
    }

    for (int i = 0; i < r_vector.size(); ++i)
    {
        if (r_vector[i] == name_input)
            return false;
    }

    return true;
}

void print_all_values(std::vector<std::string> const &names_vector, std::vector<int> const &scores_vector)
{
    std::cout << "Names: " << '\t' << "Scores:\n";
    for (int i = 0; i < names_vector.size(); ++i)
    {
        std::cout << names_vector[i] << '\t' << scores_vector[i] << std::endl;
    }
}

int main()
{
    std::vector<std::string> names;
    std::vector<int> scores;

    std::string name_input{""};
    int score_input{0};
    std::cout << "Please enter a name followed by a score. \n";
    while (std::cin >> name_input >> score_input && condition_is_met(name_input, score_input))
    {
        if (!is_valid(names, name_input))
        {
            std::cout << "Name is entered twice. Program is terminating...\n";
            break;
        }

        names.push_back(name_input);
        scores.push_back(score_input);
    }

    print_all_values(names, scores);

    return 0;
}