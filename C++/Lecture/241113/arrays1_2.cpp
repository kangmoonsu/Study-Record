
#include <iostream>
using namespace std;

// Fraction class
class Fraction
{
private:
	int numerator;
	int denominator;

public:

	// Constructors
	Fraction();					// default
	Fraction( int, int );		// w/ input parameters

	// Print
	void print();
};
Fraction::Fraction()
{
	numerator = 0;
	denominator = 0;
}
Fraction::Fraction( int n, int d )
{
	numerator = n;
	denominator = d;
}
void Fraction::print()
{
	cout << numerator << "/" << denominator << endl;
}

// Function declaration that accepts a single array element
void arrayElement( int );

// Function declaration to add to a passed array
void addToArray( int[], int );

// Function declaration to pass an array
// and prevent changes to the array values
void addToArray_const( const int[], int );

// Function declarations to initialize
// and print elements in an array.
// In these functions we are passing
// the size of the array as a separate
// input argument.
void initArray( int[], int, int );
void printArray( const int[], int );

int main()
{
	// Arrays
	//
	// Arrays are a fundamental programming construct
	// we can use to store a group of elements.
	// An array is NOT a class, but rather a construct
	// of the language. When we create an array, a fixed
	// area of memory is created to store the elements.
	// All the elements occupy a contiguous area of memory.
	// In other words, the elements are stored sequentially
	// in memory one after another in order. The array stores
	// a specific, fixed number of elements. The number of
	// elements stored is fixed and cannot be changed. All the
	// elements in an array must be of the same data type.
	// We can use arrays to store a group of built-in types.
	// For example below we create an array to store a fixed
	// number (10) integer values.
	int iarray[10];

	// We use an index from 0 to N-1 (where N represents
	// the number of elements) to set or get element values
	// Below we are setting the first and last elements
	iarray[0] = 45;
	iarray[9] = 2;

	// Below we are getting the first and last elements
	cout << iarray[0] << ", " << iarray[9] << endl;

	// We can use the elements as we would any other variable
	int ival = iarray[0] - 10;
	cout << "ival: " << ival << endl;

	// A constant is useful for indicating the size of an
	// array since we can later change this value in one
	// location instead of updating it each time we are
	// using the size value.
	const int IARRAY_SIZE = 10;

	// We can use a for loop to get or set elements in an array
	// Below we set each element to a value computed using the
	// loop counter. Note how we can use the loop counter as the
	// array index that varies from 0 to 9
	for(int i = 0; i < IARRAY_SIZE; ++i)
	{
		iarray[i] = i * 10;
	}

	// We can use a range-based for loop (part C++11) with an array
	// Below we get and print the elements using a range-based loop
	for( int i : iarray)
	{
		cout << i << endl;
	}

	// If we know the values we'd like to assign to elements
	// when we create an array, we can use what is called an
	// "initialization statement" to set each element value. Below
	// we create an array of characters and set each element
	// using an initializer statement
	const int LETTERS_SIZE = 7;
	char letters[LETTERS_SIZE] = { 'c', 's', 'c', '-', '1', '2', '3' };
	for(int i = 0; i < LETTERS_SIZE; ++i)
		cout << "letters[" << i << "]: " << letters[i] << endl;


	// In addition to arrays of primitive types, we can store
	// objects of class types. Below we create an array of
	// Fraction objects and demonstrate storing and listing
	// them in the array. Note that an default constructor is
	// necessary when creating an array of objects
	const int FRACTIONS_SIZE = 3;
	Fraction fractions[FRACTIONS_SIZE];
	fractions[0] = Fraction(1,2);
	fractions[1] = Fraction(1,4);
	fractions[2] = Fraction(5,8);
	for(int i = 0; i < FRACTIONS_SIZE; ++i )
	{
		fractions[i].print();
	}



	// Declare and assign values to an integer array
	int iarray2[3] = { 10, 20, 30 };

	// Pass an array element to a function
	arrayElement( iarray2[1] );

	// Pass array to a function
	//
	// Arrays in function arguments
	//
	// An array is passed using call by reference.
	// The array name actually stores an address in memory to
	// the first element in the array. When we pass an array
	// to a function, a copy of this address is used within
	// the called function. If the function changes any of the
	// values in the array, it is changed in the calling program.
	// Below we pass our array to a function that changes
	// the array element values. Note the difference
	// before and after the call to this function.
	cout << "iarray2 values before addToArray call: " << iarray2[0] << ", " << iarray2[1] << ", " <<  iarray2[2] << endl;
	addToArray(iarray2, 10);
	cout << "iarray2 values after addToArray call: " << iarray2[0] << ", " << iarray2[1] << ", " <<  iarray2[2] << endl;

	// Pass constant array to a function
	cout << "iarray2 values before addToArray_const call: " << iarray2[0] << ", " << iarray2[1] << ", " <<  iarray2[2] << endl;
	addToArray_const(iarray2, 10);
	cout << "iarray2 values after addToArray_const call: " << iarray2[0] << ", " << iarray2[1] << ", " <<  iarray2[2] << endl;

	// More examples of using arrays in functions
	const int ARRAY_SIZE = 10;

	// Note the difference in values printed
	// before and after the array is initialized.
	// If an array is not initialized, it may contain
	// values left-over from a previous program using the
	// same area of memory now occupied by the array
	cout << "Values in iarray before initialization" << endl;
	printArray( iarray2, ARRAY_SIZE );
	initArray( iarray2, ARRAY_SIZE, 0 );
	cout << "Values in iarray after initialization" << endl;
	printArray( iarray2, ARRAY_SIZE );



	return 0;
}

// Function definition that accepts a single array element
void arrayElement( int a )
{
	cout << "Inside arrayElement function:" << endl;
	cout << "  Passed array element: " << a << endl;
}

// Function definition to add a value
// to each element of the passed array.
// Note you can optionally specify the length
// of the array in the parameter name.
void addToArray(int arr[3], int x)
{
	arr[0] += x;
	arr[1] += x;
	arr[2] += x;
}

// Function definition to pass an
// array and prevent changes to
// the array values.
void addToArray_const( const int arr[], int x )
{
	// Un-comment the section below and note the
	// compiler error since we are attempting
	// to change the values that have been
	// declared constant.s
/*
	arr[0] += x;
	arr[1] += x;
	arr[2] += x;
*/
	// Although we cannot modify the values,
	// we can still use them without any errors
	int newValue = arr[0] + 22;
	cout << "Inside addToArray_const function" << endl;
	cout << "  Example of using constant values in a function, newValue: " << newValue << endl;
}

// Function definitions to initialize
// and print elements in an array.
// In these functions we are passing
// the size of the array as a separate
// input argument.

// Initialize values in array
// Note these values are changed in the
// calling program since arrays are passed
// using call by reference.
void initArray( int array[], int size, int value )
{
	for(int i = 0; i < size; ++i)
	{
		array[i] = value;
	}
}

// Print values in array
// Note we make the array constant
// to prevent changes since we just
// want this function to use the
// values, not make any changes to them.
void printArray( const int array[], int size )
{
	for(int i = 0; i < size; ++i)
	{
		cout << "array[" << i << "]: " << array[i] << endl;
	}
}





