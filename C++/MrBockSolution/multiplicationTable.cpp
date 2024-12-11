#include <iostream>
using namespace std;
#include <iomanip>

const int NUM_ROWS = 5;
const int NUM_COLS = 5;

class MultiplicationTable
{
private:
	int data[NUM_ROWS][NUM_COLS];			// Stores two-dimensional data
	int min, max;							// Min and max of data

public:

	// Constructor
	MultiplicationTable();

	// Fill table with values
	void fill();

	// Find min, max
	void findMinMax();

	// Print
	void print();

	// Access methods
	void setValue(int,int,int);
	int getValue(int,int);
	int getMinValue();
	int getMaxValue();
};

void findMatch( MultiplicationTable mt, int valueToFind );

int main()
{
	// Create a multiplication table
	MultiplicationTable mtable;

	// Fill table
	mtable.fill();

	// Find min and max of table
	mtable.findMinMax();

	// Print
	mtable.print();

	// Prompt user for integer value in the table
	int inputValue;
	cout << "Enter a value in the multiplication table: ";
	cin >> inputValue;

	// Function prints table row and column indices
	// where input value matches value in table
	findMatch(mtable, inputValue);

	return 0;
}

// Constructor
MultiplicationTable::MultiplicationTable()
{
	// Initialize table
	for(int i = 0; i < NUM_ROWS; ++i)
	{
		for(int j = 0; j < NUM_COLS; ++j)
		{
			data[i][j] = 0;
		}
	}

	// Initialize min, max
	min = max = 0;
}

// Random fill
void MultiplicationTable::fill()
{
	for(int i = 0; i < NUM_ROWS; ++i)
	{
		for(int j = 0; j < NUM_COLS; ++j)
		{
			// Data value
			data[i][j] = (i+1) * (j+1);
		}
	}
}

// Find min and max
void MultiplicationTable::findMinMax()
{
	// Initialize min and max to first element
	min = max = data[0][0];
	for(int i = 0; i < NUM_ROWS; ++i)
	{
		for(int j = 0; j < NUM_COLS; ++j)
		{
			if( data[i][j] < min )
			{
				min = data[i][j];
			}
			if( data[i][j] > max )
			{
				max = data[i][j];
			}
		}
	}
}

// Print
void MultiplicationTable::print()
{
	cout << "Multiplication Table:" << endl;
	cout << "  minimum value: " << min << endl;
	cout << "  maximum value: " << max << endl;
	for(int i = 0; i < NUM_ROWS; ++i)
	{
		for(int j = 0; j < NUM_COLS; ++j)
		{
			cout << setw(4) << data[i][j] << " ";
		}
		cout << endl;
	}
}

// Return data value given row and column index
int MultiplicationTable::getValue(int r, int c)
{
	return data[r][c];
}

// Set data value given row and column index
void MultiplicationTable::setValue(int r, int c, int val)
{
	data[r][c] = val;
}

// Return minimum data value
int MultiplicationTable::getMinValue()
{
	return min;
}

// Return maximum data value
int MultiplicationTable::getMaxValue()
{
	return max;
}

// Function prints table row and column indices
// where input value matches value in table
void findMatch( MultiplicationTable mt, int value )
{
	// Indication if value is found
	bool found = false;

	// For each row
	for(int i = 0; i < NUM_ROWS; ++i)
	{
		// For each column
		for(int j = 0; j < NUM_COLS; ++j)
		{
			// Table value
			int tableValue = mt.getValue(i,j);

			// If match
			if( tableValue == value )
			{
				cout << value << " found in table at row, col: " << i << ", " << j << endl;
				found = true;
			}
		}
	}
	if(!found)
	{
		cout << value << " not found in table" << endl;
	}
}


