#include <iostream>
using namespace std;

/*
 * Let's practice designing and writing a C++ class
 * by extending our previous struct that defined a Fraction.
 * We'll start fresh by creating a "knows/does" design table
 * as discussed in the slides for this section. Refer to
 * the slides for an in-depth discussion of this design table.
 *
 * A design table begins with a listing what a Fraction "knows" and "does"
 *
 * 	           Fraction
 *  ==============================================================
 *       "knows"	|	"does"
 *  --------------------------------------------------------------
 *       numerator	|        add another Fraction, return result
 *					|
 *      denominator	|
 *					|        get the value of the numerator
 *					|        get the value of the denominator
 *					|
 *					|        set the value of the numerator
 *					|        set the value of the denominator
 *					|
 *					|        print the contents of the Fraction
 *
 *
 * Next, we add primitive types to our what the class "knows"
 * and convert what the class "does" to functions
 *
 * 	           Fraction
 *  ==============================================================
 *       "knows"	|	"does"
 *  --------------------------------------------------------------
 *  int numerator	|        Fraction add( Fraction )
 *					|
 *  int denominator	|
 *					|        int getNumerator()
 *					|        int getDenominator()
 *					|
 *					|        void setNumerator( int )
 *					|        void setDenominator( int )
 *					|
 *					|        void print()
 */

// Class definition
class Fraction
{
	// What the class "knows"
	// Note these variables are private
	// to support the concept of encapsulation (see slides)
private:
	int numerator;
	int denominator;

	// What the class "does"
	// Note these are the member function declarations.
	// They are public so they are "visible" (or can
	// be called by objects) in programs using this class
public:

	// Constructor (default)
	Fraction();

	// Constructor w/ arguments
	Fraction( int, int );

	// Add a fraction and return result
	Fraction add( Fraction );

	// Print
	void print();

	// Access methods (get/set)
	// These methods provide the ability
	// for programs using this class to
	// get private member variable values and
	// set private member variable values
	int getNumerator();
	void setNumerator(int);
	int getDenominator();
	void setDenominator(int);
};

int main()
{
	// Create a Fraction object using
	// an empty constructor and access methods
	Fraction f1;
	f1.setNumerator(1);
	f1.setDenominator(2);

	// Create a Fraction object using
	// a constructor to assign member variables
	Fraction f2(1,4);

	// Add two fractions and return result
	Fraction f3 = f1.add(f2);

	// Print results
	cout << "f1: ";
	f1.print();
	cout << "f2: ";
	f2.print();
	cout << "f1 + f2: ";
	f3.print();

	return 0;
}

// Class member function definitions
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
Fraction Fraction::add( Fraction f2 )
{
	Fraction result;
	result.numerator   = (numerator*f2.denominator + denominator*f2.numerator);
	result.denominator = (denominator*f2.denominator);

	return result;
}
int Fraction::getNumerator()
{
	return numerator;
}
void Fraction::setNumerator(int n)
{
	numerator = n;
}
int Fraction::getDenominator()
{
	return denominator;
}
void Fraction::setDenominator(int d)
{
	denominator = d;
}

