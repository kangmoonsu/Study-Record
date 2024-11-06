
#include <iostream>
using namespace std;

/*
 * Let's design a structure that defines a data model describing a fraction.
 * A fraction consists of both a numerator and a denominator.
 * In order to define a fraction, we need to include these
 * as "members" in our new data type. Since both the numerator
 * and denominator are whole numbers, we can declare two
 * integer variables to store their values. Below is our
 * new struct data type describing a fraction
*/
struct Fraction
{
	int numerator;
	int denominator;
};

void printFraction( Fraction );
void modifyFraction( Fraction & );
Fraction addFractions( Fraction, Fraction );

int main()
{
	// We use struct types just as we do
	// primitive variable types.

	// We can declare a variable of this new type
	Fraction f1;

	// We can assign values to the struct members
	f1.numerator = 1;
	f1.denominator = 2;

	// We can assign values upon declaration
	// Note that this is usually done upon
	// declaration
	Fraction f2 = { 1, 4 };

	// We can pass input function parameters by value (call-by-value)
	cout << "f1: ";
	printFraction(f1);
	cout << "f2: ";
	printFraction(f2);

	// We can pass input function parameters by value (call-by-reference)
	Fraction f3 = { 1, 2 };
	modifyFraction(f3);
	cout << "f3: ";
	printFraction(f3);

	// We can return fractions
	Fraction f4 = addFractions(f1,f2);
	cout << "f1 + f2: ";
	printFraction(f4);

	return 0;
}

void printFraction( Fraction f )
{
	cout << f.numerator << "/" << f.denominator << endl;
}
void modifyFraction( Fraction &f )
{
	f.numerator += 3;
	f.denominator += 3;
}
Fraction addFractions( Fraction f1, Fraction f2 )
{
	Fraction result;
	result.numerator   = (f1.numerator*f2.denominator + f1.denominator*f2.numerator);
	result.denominator = (f1.denominator*f2.denominator);

	return result;
}


