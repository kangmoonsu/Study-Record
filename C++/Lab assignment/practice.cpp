#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    int guess;        // User input
    int number;       // Random int
    int numGuesses;   // Guess count
    bool play = true; // Play or Quit

    srand(time(NULL));

    while (play)
    {
        number = rand() % 100 + 1; // Create a random int
        numGuesses = 0;
        
        cout << "Pick a number between 1 and 100, enter '0' to quit" << endl;

        while (guess != number && guess != 0)
        {
            cin >> guess;

            if (guess == 0) // User quit
            {
                cout << "Thanks for playing" << endl;
                play = false; 
            }
            else // User play
            {
                numGuesses++; 

                if (guess < number)
                {
                    cout << "Too low" << endl;
                }
                else if (guess > number)
                {
                    cout << "Too high" << endl;
                }
                else
                {
                    cout << "Correct, number of guesses: " << numGuesses << endl;
                }
            }
        }  
    }
    return 0;
}