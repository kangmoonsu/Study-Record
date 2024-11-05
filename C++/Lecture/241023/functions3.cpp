
#include <iostream>
using namespace std;

// Function declaration
// Note that you can provide formal parameter
// names for the input arguments or just provide
// the variable type
//float add( float variableA, float variableB );
float add( float, float );

int multiply( int );

int addTo(int, int);

// Overloaded function declarations
// Note the difference in input arguments
int subtract( int, int );
int subtract( int, int, int );
// Note that is it illegal to have
// two overloaded functions differ
// only by return type. Uncomment
// the function below to verify
//float subtract( int, int );

int main()
{
	// Formal parameter names
	//
	// The names of variables used as input arguments
	// to functions do not need to match the names
	// given in the function declaration (also called
	// the formal parameter names). Below the variables
	// we are using named "x" and "y" do not need to
	// match the formal parameter names "variableA"
	// and "variableB" used in either the declaration
	// or the definition
	float x = 2.5;
	float y = 3.5;
	float result = add( x, y );
	cout << "x, y, result: " << x << ", " << y << ", " << result << endl;

	// Scope
	//
	// Variables live between curly braces in which
	// they are declared (also known as scope)
	// Note below how we are declaring a variable
	// with the same name in the main function scope
	// as well as within the if statement scope below.
	// NOTE: this is only shown to demonstrate where
	// scope is defined. Using two variables with the
	// same name in this manner can be confusing.
	int var1 = 20;
	if( var1 < 40 )
	{
		int var1 = 40;
		cout << "var1 inside if statement: " << var1 << endl;
	}
	cout << "var1 outside if statement: " << var1 << endl;

	// Variables declared in different function scopes
	// live (are local to) the function in which they
	// are declared.
	//
	// var2 below is local to this main function
	// The variable "scale" in the multiply function
	// definition below is local to the multiply function.
	int var2 = 4;
	int mResult = multiply( var2 );
	cout << "var2, mResult: " << var2 << ", " << mResult << endl;

	// Call by value
	//
	// The slides discussed how a copy of a function
	// parameter is made when parameters are passed
	// by call by value. The calling function then
	// works with the copy leaving the original argument
	// untouched. Let's look at an example of how
	// this works. Refer to the addTo function below
	//
	int value = 10;
	cout << "value before function addTo is called: " << value << endl;
	addTo( value, 10 );
	cout << "value after function addTo is called: " << value << endl;
	//
	// Note that the value of the variable ivalue never changed.
	// This is because the addTo function was working on
	// a copy of the variable passed, not the actual variable

	// Overloading functions
	//
	// Functions can have the same name but
	// differ in the input argument list
	cout << "Overloaded function result 1: " << subtract( 20, 10 ) << endl;
	cout << "Overloaded function result 2: " << subtract( 20, 10, 5 ) << endl;


	return 0;
}

// Function definition
// Returns the addition of two input arguments
float add( float variableA, float variableB )
{
	return (variableA + variableB);
}

// Function definition
// Returns the result of the input argument
// multiplied by a scale factor of 100
int multiply( int v )
{
	// multiplier below is local to the multiply function
	int scale = 100;

	return (v * scale);
}

// Function definition
// Multiplies an input argument by the second argument
// Returns zero
int addTo( int value, int v )
{
	value += v;
	cout << "value inside the addTo function: " << value << endl;
	return 0;
}

// Overloaded function definitions
//
// Subtract a single value from the first argument
int subtract( int first, int v1 )
{
	return (first - v1);
}
// Subtract two values from the first argument
int subtract( int first, int v1, int v2 )
{
	return (first - v1 - v2);
}

// Note that is it illegal to have
// two overloaded functions differ
// only by return type. Uncomment
// the function below to verify
/*
float subtract( int first, int v1 )
{
	return (first - v1);
}
*/


