#include <iostream>
#include <cstdlib>
#include <ctime>
#include<string>
using namespace std;
int main() 
{
    srand(time(0)); 

    string choices[] = { "Rock", "Paper", "Scissors" };

    cout << "Welcome to Rock, Paper, Scissors!" << endl;

    while (true) 
    {
    cout << "Enter your choice (0 - Rock, 1 - Paper, 2 - Scissors): ";
    int playerChoice;
    cin >> playerChoice;
    if (playerChoice < 0 || playerChoice > 2) 
    {
    cout << "Invalid choice. Please try again." << endl;
    continue;
    }
    int computerChoice = rand() % 3;
    cout << "You chose: " << choices[playerChoice] << endl;
    cout << "Computer chose: " << choices[computerChoice] << endl;
    if (playerChoice == computerChoice) 
    {
    cout << "It's a tie!" << std::endl;
    } 
    else if ((playerChoice == 0 && computerChoice == 2) ||(playerChoice == 1 && computerChoice == 0) ||(playerChoice == 2 && computerChoice == 1)) 
    {
    cout << "Congratulations! You win!" << endl;
    } 
    else 
    {
    cout << "Sorry, you lose. Better luck next time!" << endl;
    }
    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    if (playAgain != 'y' && playAgain != 'Y') 
    {
    break;
    }
    cout << endl;
    }

    return 0;
}
