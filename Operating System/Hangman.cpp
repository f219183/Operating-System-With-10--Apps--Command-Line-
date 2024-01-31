#include <iostream>
#include <string>
using namespace std;
int main() {
    string secretWord;
    string guessedWord;
    char incorrectLetters[6];

    int maxAttempts = 6;
    int attempts = 0;

    cout << "Welcome to Hangman!" << endl;
    cout << "Enter the secret word: ";
    cin >> secretWord;

    guessedWord = string(secretWord.length(), '_');

    while (true) 
    {
    cout << "Guess a letter: ";
    char guess;
    cin >> guess;
    bool correctGuess = false;
    for (int i = 0; i < secretWord.length(); i++) 
    {
    if (secretWord[i] == guess) 
    {
    guessedWord[i] = guess;
    correctGuess = true;
    }
    }
    if (!correctGuess) 
    {
    incorrectLetters[attempts] = guess;
    attempts++;
    }

    cout << "Guessed word: " << guessedWord << endl;
    if (guessedWord == secretWord) 
    {
    cout << "Congratulations! You guessed the word." << endl;
    break;
    }

    cout << "Incorrect letters: ";
    for (int i = 0; i < attempts; i++) 
    {
    cout << incorrectLetters[i] << " ";
    }
    cout << endl;
    cout << "Attempts left: " << maxAttempts - attempts << endl;
    if (attempts == maxAttempts) 
    {
    cout << "You lost! The word was: " << secretWord << endl;
    break;
    }
    }

    return 0;
}
