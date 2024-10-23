#include <iostream>
using namespace std;

// NOTE: Include this file
#include <time.h>

int main()
{
	// Initialize random seed
	srand(time(NULL));

	// The guess number
	int guessNumber;

	// Continue if not done
	bool done = false;
	while( !done )
	{
		// Generate random number
		int actualNumber = rand() % 100 + 1;

		// Initialize guess count
		int guessCount = 0;

		// Prompt user
		cout << "Pick a number between 1 and 100, enter '0' to quit" << endl;

		// Repeat if not correct and not done
		bool correct = false;
		while( !correct && !done )
		{
			// The guess number
			cin >> guessNumber;

			// Check if done
			if(guessNumber == 0)
				done = true;

			// Check if out of range
			else if(guessNumber < 0 || guessNumber > 100)
			{
				cout << "Number must be between 1 and 100" << endl;
			}

			// Process the guess
			else
			{
				// Increment guess count
				++guessCount;

				// Compare guess number with actual number
				if( guessNumber < actualNumber )
				{
					cout << "Too low" << endl;
				}
				else if( guessNumber > actualNumber )
				{
					cout << "Too high" << endl;
				}
				else
				{
					cout << "Correct, number of guesses: " << guessCount << endl;
					correct = true;
				}
			}
		}
	}

	// Done message
	cout << "Thanks for playing" << endl;

	return 0;
}

