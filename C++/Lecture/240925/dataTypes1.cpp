#include <iostream>
using namespace std;

int main()
{
	// There are two categories of data types in C++.
	//
	// The first category is called "primitive", or "built-in", data.
	// These data types store information only.
	//
	// Examples of primitive data type variable declarations
	short s;			// short integer, 16 bits
	int i;				// integer, 32 bits
	long l;				// long integer, 64 bits
	float f;			// float decimal, 32 bits
	double d;			// double decimal, 64 bits
	char c;				// character, 8 bits
	bool tf;			// boolean, two states only (true or false)

	// Examples of assigning variable values
	s = 34;
	i = 10;
	l = 450;
	f = 32.45f;			// note use of 'f' to sometimes distinguish float from double
	d = 32.456789832;
	c = 's';
	tf = false;

	// We can also assign values in the declaration
	int i2 = 20;
	bool b2 = true;

	// Printing the values to the Console window
	cout << "s: " << s << endl;
	cout << "i: " << i << endl;
	cout << "l: " << l << endl;
	cout << "f: " << f << endl;
	cout << "d: " << d << endl;
	cout << "c: " << c << endl;
	cout << "tf: " << tf << endl;
	cout << "i2: " << i2 << endl;
	cout << "b2: " << b2 << endl;

	// We can change the values of variables anytime
	i = 33;
	cout << "New value of i: " << i << endl;


	// The second date type category is called a class.
	//
	// This data type can store information AND perform operations.
	// The name we use for these operations are called "functions" or
	// "methods." We use a class when we can't describe our information
	// using the primitive types. For example, consider information
	// describing a "dog." We might have a color, an age, a height,
	// a weight, a breed, and so on to describe a dog.
	// Since we can't store all this information in a single primitive type,
	// to represent a "dog" in C++, we might create our own "class."
	// We'll be looking at the class type later in the course.

	// Before creating our own classes, we'll first learn to use existing
	// classes. The first class we'll use is the "string" class
	// This is a C++ class that describes a sequence of characters
	// It also has methods that can operate on this sequence of characters
	// We'll be looking at how to use these methods later. For now, let's
	// look at how to declare, assign, and output this class type

	// Declaration of a "string" class type
	string str;

	// We can assign it a value and print to the Console
	str = "Hello";
	cout << "Value of str: " << str << endl;;

	// We can change the value
	str = "CSC123";
	cout << "New value of str: " << str << endl;

	// We can also assign the value when we create the object
	string str2 = "Hello";
	cout << "Value of str2: " << str2 << endl;

	// Among other things (as we'll later), we can append to a string.
	// This is an example of how a class can perform operations
	// in addition to storing information.
	str2.append(" World");
	cout << "Concatenated str2: " << str2 << endl;


	// Inputting characters
	//
	// Let's prompt a user to input two characters.
	// If we don't add a newline, the user's input
	// will be after the colon in the output below
	cout << "Please input two characters: ";

	// We'll now store the input from the user
	char c1, c2;
	cin >> c1 >> c2;

	// When writing programs it is very useful to
	// print out what the user enters to be sure
	// you are storing what you expect to store.
	// Try entering the two characters with and
	// without a space. Note that spaces are ignored.
	cout << "You entered: " << c1 << " and " << c2 << endl;

	// If you want the user to enter the
	// two characters separated by a comma, you need
	// to specify an additional character to store the comma.
	// Any other symbol (other than a white-space) must be
	// considered and read.
	char comma;
	cout << "Please input two characters separated by a comma: ";
	cin >> c1 >> comma >> c2;
	cout << "You entered: " << c1 << " and " << c2 << endl;


	// Arithmetic Expressions
	//
	// If either or both operands in an arithmetic expression
	// is a decimal value (floating-point), then the result
	// is also a floating-point value. Note we are using
	// parentheses as good practice to help the "readability"
	// of our code
	float x = 1.2;
	int y = 4;
	cout << "x + y: " << (x + y) << endl;

	// Division using integers will truncate the
	// fractional part. Note this removes the fractional
	// part, it does NOT round the result
	int z = 11;
	cout << "z / y: " << (z / y) << endl;

	// Remainder operator, also called the modulus operator
	// returns remainder of dividing the first value by
	// the second value. Note this is NOT the fractional
	// part of a division, but rather how much is left
	// over after the first is divided by the second
	// Consider z % y or 11 % 4 with our variables above.
	// 11 divided by 4 would be 2 to "remove" 8 with 3 left over
	// In other words, 4 can go into 11 2 times leaving a
	// remainder of 3. Another way to think of this is
	// if you had 11 slices of pizza and 2 friends eat
	// 4 slices at a time, how many would that leave you?
	// It would leave you 3 slices after your 2 friends
	// had their 4 slices each.
	cout << "z % y: " << (z % y) << endl;

	// When storing the result of an expression, the expression
	// is solved first, then the result is assigned to the variable
	// Note since x is a floating-point value, the result of
	// x * y is also a floating-point value and since this
	// intermediate result is a floating-point value adding
	// it to another integer, z, also results in a floating-point
	float result = x * y + z;
	cout << "x * y + z: " << result << endl;

	// We can use a variable in an expression, then overwrite it
	result = result + 2;
	cout << "result: " << result << endl;


	return 0;
}




