#include <iostream>
using namespace std;
#include <cmath>

// Function declaration to add 10 to an input integer
// argument and return the result
int add( int );

// Function declaration to multiply two float variables
// and return the result
float multiply( float, float );

// Function declaration to compute the perimeter of a circle
// and return the result
float circlePerim( float );

// Function declaration to demonstrate best practice
// when requiring different values to return
int returnValues( int, int );

int main()
{
	// Function call examples
	//
	int intArg = 10;
	int intResult= add( intArg );
	cout << "intArg, intResult: " << intArg << ", " << intResult << endl;

	float floatArg1 = 2.5;
	float floatArg2 = 3.5;
	float floatResult = multiply( floatArg1, floatArg2 );
	cout << "floatArg1, floatArg2, floatResult: " << floatArg1 << ", " << floatArg2 << ", " << floatResult << endl;

	float circleRadius = 2.0;
	float perim = circlePerim( circleRadius );
	cout << "Perimeter of a circle with radius " << circleRadius << " is " << perim << endl;

	// A single return statement
	//
	// Example function showing how to write a function
	// requiring different output values using a single
	// return statement
	cout << "Result of returnValues( 2, 5 ): " << returnValues(2,5) << endl;
	cout << "Result of returnValues( 2, 5 ): " << returnValues(5,2) << endl;
	cout << "Result of returnValues( 2, 5 ): " << returnValues(2,2) << endl;


	return 0;
}

// Function definition to add 10 to an input integer
// argument and return the result.
int add( int inputArg )
{
	// We can return the result without
	// storing it in a variable
	return inputArg + 10;
}

// Function definition to multiply two input floating-point
// variables and return the result.
float multiply( float inArg1, float inArg2 )
{
	// We can store the result in a variable
	// and return the variable
	float result = inArg1 * inArg2;
	return result;
}

// Function definition to compute the perimeter of a
// circle given an input radius and return the result
float circlePerim( float radius )
{
	// Equation 2.0 * PI * radius
	// Note how we can use predefined functions
	// in our programmer defined functions
	return (2.0 * M_PI * radius);
}

// Function definition to demonstrate best practice
// when requiring different values to return
int returnValues( int inArg1, int inArg2 )
{
	// Return -1 if inArg1 is less than inArg2
	// Return 1 if inArg1 is greater than inArg2
	// Return 0 if inArg1 is equal to inArg2
	int retVal;
	if( inArg1 < inArg2 )
	{
		retVal = -1;
	}
	else if( inArg1 > inArg2 )
	{
		retVal = 1;
	}
	else
	{
		retVal = 0;
	}

	return retVal;

	// Note this is typically a better practice
	// than the code below
/*
	if( inArg1 < inArg2 )
	{
		return -1;
	}
	else if( inArg1 > inArg2 )
	{
		return 1;
	}
	else
	{
		return 0;
	}
*/

}
