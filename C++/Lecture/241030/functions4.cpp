#include <iostream>
using namespace std;

// void function declaration
// prints a menu to the screen
void printMenu();

// void function declaration
// performs division of integers
// after checking for a zero divisor
void divide( float, float );

// function declaration
// demonstrates call by reference
// note the ampersand used to indicate
// the integer parameter is to be
// passed using call by reference.
// note you can have mixed parameters
// below where one is call by reference
// and others are call by value
void addTo( int &, int );

int main()
{
	// Void functions
	//
	// Function call to print menu
	// Note that since a value is not
	// returned, the function call
	// is not part of an assignment
	// statement (we are not assigning
	// any return value to a variable).
	printMenu();


	// Since void functions do not return values,
	// we do not use it in a statement expecting a value
	// cout below expects input strings after the << operator
	// (also known as the output stream operator)
	// The function printMenu is printing strings
	// to the screen, but not returning the strings
	// Placing it on the right hand side of the cout
	// expression would cause an error
	//cout << printMenu();


	// return statements in void functions are often
	// used to break the flow of control within the function.
	// Oftentimes functions need to check if input arguments
	// contain valid values before they can be used.
	// One example might be an input argument that is
	// used as a divisor in an division equation.
	// If the divisor is zero, then the division should
	// not be executed to avoid a divide by zero error
	// In this case, the function should first check the
	// input argument’s value. If it is zero, the function
	// should immediately return, if not, continue with the calculation.
	// This function performs this break in the flow of control
	// using a return statement. Try using this function
	// with a zero and a non-zero value for the second argument.
	cout << "Calling divide function" << endl;
	divide( 10.0, 0.0 );

	// Call by reference
	//
	// The slides discussed how a copy of the memory address
	// of a function parameter is made when parameters are passed
	// by call by reference. The calling function then
	// works with the actual value of the paramter in memory.
	// As a result, it can change the value within the
	// calling function. Let's look at an example of how
	// this works. Refer to the addTo function below
	//
	int value = 10;
	cout << "value before function addTo is called: " << value << endl;
	addTo( value, 10 );
	cout << "value after function addTo is called: " << value << endl;



	return 0;
}

// void function definition
// prints a menu to the screen
void printMenu()
{
	// Display the menu
	cout << endl;
	cout << "=====================" << endl;
	cout << "Welcome to my program" << endl;
	cout << "=====================" << endl;
	cout << "Please select an option from the menu below" << endl;
	cout << "1) Menu option 1" << endl;
	cout << "2) Menu option 2" << endl;
	cout << "3) Quit the program" << endl;
	cout << endl;

	// Note that a return statement
	// at the end of a void function
	// is optional
	// return;
}

// void function definition
// performs division after checking for a zero divisor
void divide( float dividend, float divisor )
{
	// If divisor is equal to zero
	// break flow of control and return
	if( divisor == 0.0 )
	{
		cout << "ERROR: divide function, divisor must be non-zero value" << endl;
		return;
	}

	// Continue flow of control
	cout << "dividend/divisor calculation" << endl;
	cout << dividend << "/" << divisor << " = " << dividend/divisor << endl;
}

// function declaration
// demonstrates call by reference
// note the ampersand used to indicate
// the integer parameter is to be
// passed using call by reference.
// note you can have mixed parameters
// below where one is call by reference
// and others are call by value
void addTo( int &value, int v )
{
	value += v;
}


