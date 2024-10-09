#include <iostream>
#include <ctime>

using namespace std;

/*
Write an application that plays the Hi-Lo guessing game with numbers as shown below in a sample session. 
The program should generate a random number between 1 and 100, then repeatedly prompt the user to guess the number. 
On each guess, report to the user that he or she is correct or that the guess is high or low. 
Continue accepting guesses until the user guesses correctly or chooses to quit. 
Use the value 0 to determine whether the user wants to quit. 
Count the number of guesses and report that value when the user guesses correctly. 
At the end of each game (by quitting or a correct guess), prompt to determine whether the user wants to play again. 
Continue playing games until the user chooses to stop. 
Use the code example below to generate a random number between 1 and 100.
*/

int main() {

    int guess;       // User input
    int number;      // Random int
    int numGuesses;  // Guess count
    bool play = true; // Play or Quit

    srand(time(NULL));

    while (play) {
        number = rand() % 100 + 1; // Create a random int
        numGuesses = 0;

        cout << "Pick a number between 1 and 100, enter '0' to quit" << endl;

        while (guess != number) {
            cin >> guess;

            if (guess == 0) {
                cout << "Thanks for playing" << endl;
                play = false;
                return 0;
            }

            numGuesses++;  // Count guess 

            if (guess < number) {
                cout << "Too low" << endl;
            } else if (guess > number) {
                cout << "Too high" << endl;
            } else {
                cout << "Correct, number of guesses: " << numGuesses << endl;
            }
        }
    }
    return 0;
}