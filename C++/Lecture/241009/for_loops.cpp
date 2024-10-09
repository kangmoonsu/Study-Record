#include <iostream>
using namespace std;

int main()
{
	// Review from Ch2.4 code, not postfix and prefix differences
	int icount = 15;
	int total;
	total = icount++; // first, total assigned 15, then count is incremented to 16 (postfix)
	cout << "total, icount: " << total << ", " << icount << endl;
	icount = 15;
	total = ++icount; // first, count is incremented to 16  (prefix), then total assigned 16
	cout << "total, icount: " << total << ", " << icount << endl;

	// for loop
	//
	// The "for" loop is ideal when we have statements we'd
	// like to repeat a specific number of times. For example,
	// suppose we'd like to print values that double for 10 times
	// in increasing order.
	int limit = 10;
	double val = 1.0;
	for (int i = 1; i <= limit; ++i)
	{
		cout << "i = " << i << ", " << "val = " << val << endl;
		val *= 2;
	}

	// Instead of the loop above, a more common convention is to
	// initialize the loop counter to zero and use the condition
	// to check if it is less than the number of times you'd like to
	// repeat the statements (instead of using <=) as shown below
	val = 1.0;
	for (int i = 0; i < limit; ++i)
	{
		cout << "i = " << i << ", " << "val = " << val << endl;
		val *= 2;
	}

	// We can also use the increment section of the for loop
	// to decrement. Suppose we'd like to print a count-down.
	// Note below how we can actually use the loop counter
	// (the variable "i") in the loop
	cout << "Countdown:" << endl;
	for (int i = 10; i > 0; --i)
		cout << "\tt minus " << i << endl;
	cout << "Blast off!" << endl;


	// Each expression in a for loop is optional
	//
	// If the initialize is left out, no initialization is performed
	// Below, we can initialize the counter outside the loop
	int count = 0;
	for(; count < 5; ++count)
	{
		cout << "count: " << count << endl;
	}

	// If the increment/decrement is left out, no increment/decrement
	// operation is performed. Below we can include the
	// increment/decrement operator at the end of the for loop
	count = 0;
	for(; count < 5;)
	{
		cout << "count: " << count << endl;
		++count;
	}
	// Obviously if the condition is left out, we would
	// have an infinite loop, so this is not recommended
	//
/*
	for(;;)
	{
		cout << "Infinite loop" << endl;
	}
*/


	// We can also nest for loops
	// Suppose we'd like to print a character in a grid
	// pattern with a specified number of rows and columns
	int nrows = 4;
	int ncols = 6;
	for (int i = 0; i < nrows; ++i)
	{
		for (int j = 0; j < ncols; ++j)
		{
			cout << "* ";
		}
		cout << endl;
	}

	return 0;
}

