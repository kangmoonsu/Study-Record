
#include <iostream>
using namespace std;
#include <cmath>
#include <cstdlib>
#include <ctime>

int main()
{
	// Predefined functions
	//
	// Let's look at examples of using predefined functions
	// in the C++ language. Note that we add the #include <cmath>
	// above to use these predefined functions. These contain
	// information required by the compiler to "find" these
	// functions in the C++ libraries supplied on your system.
	// A good reference for all the C++ math functions is:
	// http://www.cplusplus.com/reference/cmath/
	//
	// Function to compute the absolute value of an integer.
	// Note how we pass the function some input information.
	// We call this input information a "function argument."
	// Note how we receive output information from the function.
	// In other words, output information is "returned" to us.
	// We call this output information the function "return" value.
	int returnValue;
	int inputArgument = -3;

	// When we use the function (as below), we call this
	// the "function call" or "function invocation."
	// We give the function what it needs (arguments) to compute
	// and store the information it gives us back (return value).
	returnValue = abs(inputArgument);
	cout << "The absolute value of " << inputArgument << " is " << returnValue << endl;

	// Since these functions return values, we can use
	// it in expressions.
	int result = abs(inputArgument) * 10;
	cout << "Result using abs in an expression: " << result << endl;

	// Example of using predefined functions
	// to compute the value of a number raised
	// to the power of an exponent. Note this function
	// requires two input arguments.
	double base = 3.0;
	double exponent = 3.0;
	double powResult = pow(base,exponent);
	cout << "The value " << base << " raised to " << exponent << ": " << powResult << endl;

	// Example of using predefined functions
	// to perform trigonometric calculations.
	// Below we compute the cosine of 45 degrees.
	// Note that all trigonometric functions
	// assume that all input arguments and return values
	// are in radians NOT degrees. If we want to
	// use values in degrees we must convert them
	// to and from radians. For this reason, we'll
	// declare the following constants to help
	// convert between radians and degrees. 
	// Note how we use the predefined constant value
	// of PI in the math library instead of using our own.
	const double RADIANS_TO_DEGREES = 180.0/M_PI;
	const double DEGREES_TO_RADIANS = M_PI/180.0;
	// Let's represent the input argument in degrees
	double cosInputDegrees = 45.0;
	// To compute the cosine, we need to convert this
	// from degrees to radians.
	double cosInputRadians = cosInputDegrees * DEGREES_TO_RADIANS;
	double cosResult = cos(cosInputRadians);
	// This result is in radians
	cout << "cosine of 45 degrees in radians: " << cosResult << endl;

	// The inverse of the cos function is the
	// arccos function which returns the angle
	// whose cosine is a given input. To return
	// this result in degrees, we need to convert
	// from radians to degrees. For example, we'll
	// convert the arccos of our output result above
	cout << "The arccos of " << cosResult << " radians as degrees: " << acos(cosResult) * RADIANS_TO_DEGREES << endl;

	// We can also use predefined functions to generate
	// random numbers. The random function is part of
	// another library called the C standard library:
	// http://www.cplusplus.com/reference/cstdlib/
	// The time function used to help generate the
	// random number is part of another library:
	// http://www.cplusplus.com/reference/ctime/
	//
	// We can use the rand and time functions along with
	// the modulus to generate random numbers within
	// different ranges. Below we generate an integer
	// between 1 and 100.

	// We do this once in our program to initialize
	// a random seed using the computer's clock time
	srand(time(NULL));

	// Generate random number between 1 and 100
	int randomNumber = rand() % 100 + 1;
	cout << "Random number between 1 and 100: " << randomNumber << endl;

	// Type-casting
	//
	// When using predefined functions, we may need
	// to convert variable types in our programs.
	// Below we use the abs function in an expression
	// requiring a double result. The first method
	// below truncates the result in standard integer division.
	int myIntVar = -9;
	double myDoubleVar;
	myDoubleVar = abs(myIntVar)/2;
	cout << "myDoubleVar: " << myDoubleVar << endl;

	// To avoid integer truncation, we convert the
	// integer (returned from abs) to a double value
	// using type-casting.
	myDoubleVar = static_cast<double>(abs(myIntVar))/2;
	cout << "myDoubleVar: " << myDoubleVar << endl;


	return 0;
}




