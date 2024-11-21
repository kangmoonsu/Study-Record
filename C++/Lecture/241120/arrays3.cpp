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
	cout << numerator << "/" << denominator;
}

const int NUM_ROWS = 2;
const int NUM_COLS = 3;

void initArray(int[][NUM_COLS]);
void printArray(int[][NUM_COLS]);

void initArray(Fraction[][NUM_COLS]);
void printArray(Fraction[][NUM_COLS]);

int main()
{
	// Two-dimensional arrays
	//
	// A two-dimensional array is commonly used
	// to store elements organized conceptually
	// as cells in a table or spreadsheet with
	// multiple rows and columns. The statement below
	// creates a two-dimensional array of integers.
	// Thinking of this as a two-dimensional table
	// or spreadsheet, the value in the first bracket
	// represents the number of rows (2) while the
	// value in the second bracket represents the number
	// of columns (3).
	int array2d[NUM_ROWS][NUM_COLS];

	// We can use a nested for loop to initialize values
	// in a two-dimensional array in this function
	initArray(array2d);

	// We can use a nested for loop to print values
	// in a two-dimensional array in this function
	printArray(array2d);

	// If we wanted to assign the value in the first
	// row, second column, we use 0 as the row index
	// and 1 as the column index
	array2d[0][1] = 77;
	printArray(array2d);

	// As in our print functions, we can use nested for
	// loops to access the elements in a two-dimensional array.
	int val = 0;
	for (int row = 0; row < NUM_ROWS; ++row)
	{
		for (int col = 0; col < NUM_COLS; ++col)
		{
			array2d[row][col] = val++;
		}
	}
	printArray(array2d);

	// Just as with one-dimensional arrays, we can store
	// class objects in two-dimensional arrays.
	// Below is an example of a two-dimensional array
	// of Fractions that have been initialized and printed
	Fraction fractions[NUM_ROWS][NUM_COLS];

	// We can overload the initArray and printArray functions
	// to accept a two-dimensional array of Fractions as shown.
	// Remember "overloading" means the same method name
	// but different parameter types.
	initArray(fractions);
	printArray(fractions);

	return 0;
}

// Function definition to initialize a two-dimensional array
// of integers in a table form showing rows and columns
// using nested standard for loops
void initArray(int arr[][NUM_COLS])
{
	// For each row
	for(int i = 0; i < NUM_ROWS; ++i)
	{
		// For each column
		for(int j = 0; j < NUM_COLS; ++j)
		{
			arr[i][j] = 0;
		}
	}
}

// Function definition to initialize a two-dimensional array
// of Fractions in a table form showing rows and columns
// using nested standard for loops. Note we are using
// the for loop indices as numerator and denominator values.
void initArray(Fraction arr[][NUM_COLS])
{
	// For each row
	for(int i = 0; i < NUM_ROWS; ++i)
	{
		// For each column
		for(int j = 0; j < NUM_COLS; ++j)
		{
			arr[i][j] = Fraction(i+1,j+1);
		}
	}
}

// Function definition to print a two-dimensional array
// of integers in a table form showing rows and columns
// using nested standard for loops
void printArray(int arr[][NUM_COLS])
{
	cout << "Array values:" << endl;

	// For each row
	for(int i = 0; i < NUM_ROWS; ++i)
	{
		// For each column
		for(int j = 0; j < NUM_COLS; ++j)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

// Function definition to print a two-dimensional array
// of Fractions in a table form showing rows and columns
// using nested standard for loops
void printArray(Fraction arr[][NUM_COLS])
{
	cout << "Array values:" << endl;

	// For each row
	for(int i = 0; i < NUM_ROWS; ++i)
	{
		// For each column
		for(int j = 0; j < NUM_COLS; ++j)
		{
			arr[i][j].print();
			cout << " ";
		}
		cout << endl;
	}
}

