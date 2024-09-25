
#include <iostream>
using namespace std;

int main()
{
	// C++11 raw string literals
	//
	// avoids having to use escape sequences
	// to output special kinds of strings.
	// As an example, consider outputting
	// the string "c:\files\" below.
	//   We could use escape sequences
	//   which can look confusing
	cout << "\"c:\\files\\\"" << endl;

	//   Or we could use the raw string literal
	//   which is much easier to read
	cout << R"("c:\files\")" << endl;

	// Decimal point precision
	//
	// We can use the sequence of instructions
	// below to specify the precision of a decimal
	// number (or how many digits are listed
	// after the decimal point).
	double amount = 12.3456789;
	cout << "Default output precision for 12.3456789: " << amount << endl;

	// Specifies a single digit after the decimal point
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(1);
	cout << "One digit precision for 12.3456789: " << amount << endl;

	// Using cin
	// If you are prompting a user to enter in more
	// than one value, you can chain cin statements
	// as shown below. For example, to prompt a user
	// to enter three whole numbers, we first ask
	// the user to enter them
	cout << "Please enter 3 numbers separated by spaces: ";
	// Then we get the input and store them in variables
	int num1, num2, num3;
	cin >> num1 >> num2 >> num3;
	// Then print the values out
	cout << "You entered: " << num1 << ", " << num2 << ", " << num3 << endl;

	return 0;
}

