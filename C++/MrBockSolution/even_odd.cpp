#include <iostream>
using namespace std;

int main()
{
	// Initialize even and odd counts
	int evenCount = 0;
	int oddCount = 0;

	// Prompt user for an integer and continue until not done
	bool done = false;
	while (!done)
	{
		cout << "Enter a positive integer (or negative integer to quit): ";
		int value;
		cin >> value;

		// If this is a negative value
		if (value < 0)
		{
			// Set done to true to end the while loop
			done = true;
		}
		else
		{
			// Use remainder operator to determine
			// if the value is even or odd
			if (value % 2 == 0)
			{
				// Increment the even count
				evenCount++;
			}
			else
			{
				// Increment the odd count
				oddCount++;
			}
		}
	}

	// Print results
	cout << endl;
	cout << "Number of even digits entered: " << evenCount << endl;
	cout << "Number of odd digits entered: " << oddCount << endl;

	return 0;
}




