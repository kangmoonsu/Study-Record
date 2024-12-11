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

	// Access
	void setNumerator(int);
	void setDenominator(int);

	// Print
	void print();
};
Fraction::Fraction()
{
	numerator = 0;
	denominator = 1;
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

// Type definition for a Fraction pointer variable
typedef Fraction* FractionPtr;

int main()
{
	// Pointers
	//
	// Declare a floating point variable
	float fVar = 23.0;

	// Declare a pointer to a floating-point variable
	// Note we are using the asterisk to declare the pointer
	float *fVarPtr;

	// Assign the address of fVar to the pointer fVarPtr
	fVarPtr = &fVar;

	// Note we are using the asterisk to refer to the variable below
	cout << "Value stored in fVar: " << fVar << endl;
	cout << "Pointer points to the value: " << *fVarPtr << endl;
	// Think of the statement above as "the variable (fVar) pointed to by fVarPtr"
	// This is also called "dereferencing"

	// Note we are using the asterisk to refer to the variable below
	// Note how this changes the value of the variable
	*fVarPtr = 77.0;
	cout << "Pointer points to the value: " << *fVarPtr << endl;
	cout << "Value stored in fVar: " << fVar << endl;

	// Pointer assignment
	// You can assign a pointer to another pointer
	float *fVarPtr2 = fVarPtr;

	// Now both fVarPtr and fVarPtr2 point to
	// the same variable
	cout << "*fVarPtr: " << *fVarPtr << endl;
	cout << "*fVarPtr2: " << *fVarPtr2 << endl;

	// Pointers to class objects
	//
	// We can use pointers to class objects
	// in the same way we do with primitive variables
	//
	// Declare a Fraction object
	Fraction f1(1,2);

	// Declare a pointer to a Fraction object
	Fraction *fPtr;

	// Assign the address of f1 to the  pointer fPtr
	fPtr = &f1;

	cout << "Fraction f1: ";
	f1.print();

	// Note how we use parentheses to first dereference the
	// pointer below, then invoke the member function (print)
	cout << "Pointer points to the fraction: ";
	(*fPtr).print();

	//
	// new and delete operators
	//
	// The new and delete operators are used to
	// dynamically allocate and delete memory for
	// a variable or object. Recall this is
	// what the vector class did as well when
	// it needed to add another element to its contents
	//
	// Declare a pointer to an integer
	int *p1;

	// Create a new integer dynamically and store
	// the address in the pointer
	p1 = new int;

	// We can now use the pointer to refer to
	// the integer. For example, we can assign
	// a value to the location pointed to by the pointer
	*p1 = 77;
	cout << "p1 points to the value: " << *p1 << endl;

	// delete the memory
	delete p1;

	// Note once this is deleted, we cannot
	// refer to this memory location. This pointer
	// is often referred to as a dangling pointer
	// or a pointer not pointing to anything
	cout << "p1 has been deleted" << endl;
	cout << "p1 is now pointing to: " << *p1 << endl;
	// Instead of printing garbage, this could
	// cause what is called a segmentation fault
	// on other compilers/systems.

	// Note we can also combine the declaration
	// and the use of the new operator
	int *p2 = new int;
	*p2 = 78;
	cout << "p2 points to the value: " << *p2 << endl;

	// delete the memory
	delete p2;

	// Create a new Fraction dynamically
	Fraction *f2 = new Fraction(1,2);
	cout << "f2 points to the Fraction: ";
	(*f2).print();

	// Note the same statement above can be 
	// represented using this form:
	f2->print();

	// delete the memory
	delete f2;

	// Dynamically create an array of integers
	int *iarray = new int[10];

	// Assign the values
	// Note how we can refer to each value
	// in the array using the name of the pointer
	// without needing to use the asterisk dereference operator
	for(int i = 0; i < 10; ++i)
	{
		iarray[i] = i*10;
	}

	// Print the values
	for(int i = 0; i < 10; ++i)
	{
		cout << "iarray[" << i << "]: " << iarray[i] << endl;
	}

	// delete the memory for an array
	delete[] iarray;

	// Dynamically create an array of Fractions
	// The default constructor is used to create
	// each of the 10 Fraction objects
	Fraction *farray = new Fraction[10];

	// Print the values
	for(int i = 0; i < 10; ++i)
	{
		cout << "farray[" << i << "]: ";
		farray[i].print();
	}

	// delete the memory for an array
	delete[] farray;

	// Oftentimes type definitions are used to
	// make it easier to refer to pointer variables
	// Consider the typedef at the top of the program
	// used to give "Fraction *" a different name "FractionPtr"
	// We can now use this new definition in
	// place of specifying "Fraction *"
	FractionPtr f3 = new Fraction(3,4);
	cout << "f3 points to: ";
	(*f3).print();
	// or
	f3->print();


	return 0;
}

