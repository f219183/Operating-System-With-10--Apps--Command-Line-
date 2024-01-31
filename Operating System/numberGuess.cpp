#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() 
{
    srand(time(0));

    const int targetNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "I have selected a number between 1 and 100.\n";

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess > targetNumber) 
        {
        cout << "Too high!\n";
        } 
        else if (guess < targetNumber) 
        {
        cout << "Too low!\n";
        } else 
        {
        cout << "Congratulations! You guessed the number in " << attempts << " attempts!\n";
        break;
        }
    } while (guess != targetNumber);

    cout << "Thank you for playing!\n";

    return 0;
}
