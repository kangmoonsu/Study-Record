#include <iostream>
using namespace std;

int main()
{
	// Boolean expression example (from slide discussing truth tables)
	//
	bool raining = true;
	float temperature = 77.5;

	// IF it's NOT raining and the temperature is less than 80.0 degrees,
	// go to the park
	// ELSE
	// stay home
	if( !raining && temperature < 80.0 )
	{
		cout << "Go to the park" << endl;
	}
	else
	{
		cout << "Stay home" << endl;
	}
	// NOTE: to help remember precedence, we can write the condition above as
	//if( (!raining) && (temperature < 80.0) )


	// Enumerated type example
	//
	// We first create a new enumerated data type named Direction
	enum Direction { NORTH, SOUTH, EAST, WEST };

	// Next, we declare a variable of this new type
	Direction dir = EAST;

	// We can now use it in an expression
	if( dir == SOUTH )
	{
		cout << "Pointing South" << endl;
	}
	else
	{
		cout << "Pointing another direction other than South" << endl;
	}

	// Multiway branching
	//
	// The text shows the following example of nested if-else statements
/*
	int count = 4;
	int score = 7;
	if( count > 0 )
		if( score > 5 )
			cout << "count > 0 and score > 5\n";
		else
			cout << "count > 0 and score <= 5\n";
*/

	// Let's re-write this using parentheses to improve readability and logic.
	int count = 4;
	int score = 7;
	if( count > 0 )
	{
		if( score > 5 )
		{
			cout << "count > 0 and score > 5\n";
		}
		else
		{
			cout << "count > 0 and score <= 5\n";
		}
	}


	// Multiway branching
	//
	// We can use "else if" when requiring more than 2 ways to branch
	// based on some condition as in the guessing game example below.
	// Note also how we can use either another "else if" or a
	// simple "else" for the final branch. Typically a single "else"
	// is used for the last branch.
	int number = 45;
	int guess = 30;
	if( guess > number )
	{
		cout << "Too high" << endl;
	}
	else if( guess < number )
	{
		cout << "Too low" << endl;
	}
	else
	{
		cout << "Correct" << endl;
	}


	// switch statement
	//
	// "switch" statements are most often used to select among multiple
	// options upon the match of a condition. Each "case" represents
	// one of many different options that might match the condition in the switch
	// statement. Once a match is found, flow of control continues immediately
	// after the "case" statement. For example, we might want to execute statements
	// based on an input value from a user.
	cout << "Enter the integer 1, 2, or 3: " << endl;
	int value;
	cin >> value;

	cout << "First switch statement example" << endl;
	switch(value)
	{
	case 1:
		cout << "\tcase 1 matched condition in switch statement" << endl;
		break;
	case 2:
		cout << "\tcase 2 matched condition in switch statement" << endl;
		break;
	case 3:
		cout << "\tcase 3 matched condition in switch statement" << endl;
		break;
	}

	// If we want to execute a statement(s) if none of our specified cases
	// match, we can use an optional "default" case
	cout << "Second switch statement example" << endl;
	switch(value)
	{
	case 1:
		cout << "\tcase 1 matched condition in switch statement" << endl;
		break;
	case 2:
		cout << "\tcase 2 matched condition in switch statement" << endl;
		break;
	case 3:
		cout << "\tcase 3 matched condition in switch statement" << endl;
		break;
	default:
		cout << "\tno matched condition in switch statement" << endl;
	}

	// Note how we use "break" statements above to break control of flow out
	// of the switch statement and continue after the closing switch statement
	// curly brace. If we didn't include a "break" after each case, flow of control
	// continues into the next case whether it matches the condition or NOT!
	// The majority of the time, this is NOT what we intend to accomplish
	// with a switch statement. 
	cout << "Third switch statement example" << endl;
	switch(value)
	{
	case 1:
		cout << "\tcase 1 matched condition in switch statement" << endl;
	case 2:
		cout << "\tcase 2 matched condition in switch statement" << endl;
	case 3:
		cout << "\tcase 3 matched condition in switch statement" << endl;
	default:
		cout << "\tno matched condition in switch statement" << endl;
	}


	return 0;
}




