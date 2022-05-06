#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

enum SELECTION
{
    ROCK = 1,
    PAPER,
    SCISSORS
};

void print_score(int const *score)
{
    std::cout << "\nCurrent score: \n";
    std::cout << "Player: " << score[0] << "\n";
    std::cout << "Computer: " << score[1] << "\n\n";
}

void print_score(int const *score, bool game_is_finished)
{
    std::cout << "Final score: \n";
    std::cout << "Player: " << score[0] << "\tComputer: " << score[1] << std::endl;

    if (score[0] > score[1])
        std::cout << "Player has won the game!\n";
    else
        std::cout << "Computer has won the game!";
}

bool game_is_finished(int const *score)
{
    constexpr int max_score{5};

    if (score[0] == max_score || score[1] == max_score)
    {
        return true;
    }

    return false;
}

SELECTION generate_computer_selection()
{

    int random_number = (rand() * 1.0 / RAND_MAX * 3) + 1;

    return (static_cast<SELECTION>(random_number));
}

int main()
{
    //Player : score[0], Computer : score[1]
    int score[2]{0, 0};
    int user_input;

    std::cout << "GAME: ROCK PAPER SCISSORS\n";
    std::cout << "Please enter either (1) Rock (2) Paper (3) Scissors.\n";
    while (!game_is_finished(score) && std::cin >> user_input)
    {
        SELECTION computer_selection = generate_computer_selection();
        SELECTION user_selection = static_cast<SELECTION>(user_input);

        switch (user_selection)
        {
        case ROCK:
            if (computer_selection == SCISSORS)
            {
                score[0] += 1;
                std::cout << "Rock beats scissors. Player has won the round.\n";
            }
            else if (computer_selection == PAPER)
            {
                score[1] += 1;
                std::cout << "Paper beats rock. Computer has won the round.\n";
            }
            else
            {
                std::cout << "Both the player and the computer chose rock ! It's a draw.\n";
            }

            break;

        case PAPER:
            if (computer_selection == ROCK)
            {
                score[0] += 1;
                std::cout << "Paper beats rock. Player has won the round.\n";
            }
            else if (computer_selection == SCISSORS)
            {
                score[1] += 1;
                std::cout << "Scissors beats paper. Computer has won the round.\n";
            }
            else
            {
                std::cout << "Both the player and the computer chose paper ! It's a draw.\n";
            }

            break;

        case SCISSORS:
            if (computer_selection == PAPER)
            {
                score[0] += 1;
                std::cout << "Scissors beats paper. Player has won the round.\n";
            }
            else if (computer_selection == ROCK)
            {
                score[1] += 1;
                std::cout << "Rock beats scissors. Computer has won the round.\n";
            }
            else
            {
                std::cout << "Both the player and the computer chose scissors ! It's a draw.\n";
            }

            break;
        default:
            std::cout << "Invalid input. Please try again. \n";
            break;
        }

        print_score(score);
    }

    //Game results
    print_score(score, true);

    return 0;
}