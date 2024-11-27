
#include <iostream>
using namespace std;
#include <vector>

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

int main()
{
	// Vector class
	//
	// The vector is a C++ class that acts as
	// a dynamic array that grows in size as
	// elements are added during a running program.
	// As a class, it can also perform many useful
	// operations on the data it stores through
	// class member functions. These functions and
	// other information on vectors can be found
	// at the link below:
	// http://www.cplusplus.com/reference/vector/vector/
	//
	// Since a vector is a C++ class, we must include
	// it's class definition in the header file
	// that is specified above #include <vector>
	//
	// Below we declare a vector to store integer variables
	vector<int> intVec;

	// To add elements to vector, we can use the member
	// function named push_back as shown below.
	intVec.push_back(77);
	intVec.push_back(3);
	intVec.push_back(44);

	// To iterate through all the elements we can
	// use a for loop as we do with arrays. Note the
	// member function size() that returns the size
	// of the array. Since this function returns an
	// unsigned int, on some compilers, we need to type-cast 
	// the unsigned int to match our int loop counter type. 
	// This is shown in the commented line below.
	// With other compilers, it is not necessary.
	// Note also how we can access each element using the [] as 
	// we do with arrays.
	//int len = static_cast<unsigned int>(intVec.size());
	int len = intVec.size();
	for( int i = 0; i < len; ++i)
		cout << "intVec[" << i << "]: " << intVec[i] << endl;

	// Instead of type-casting the unsigned int to an int,
	// we could just declare our loop counter as an
	// unsigned int.
	for( unsigned int i = 0; i < intVec.size(); ++i)
		cout << "intVec[" << i << "]: " << intVec[i] << endl;

	// Vector constructor accepts a number of elements
	// to intially allocate
	vector<int> intVec2(3);

	// Since memory is allocated for the first three
	// positions, we can simply assign values to each
	intVec2[0] = 34;
	intVec2[1] = 55;
	intVec2[2] = 8;
	for( unsigned int i = 0; i < intVec2.size(); ++i)
		cout << "intVec2[" << i << "]: " << intVec2[i] << endl;

	// We can also store objects of class types in vectors
	// Note how we specify our Fraction class type in our
	// vector below. 
	vector<Fraction> fracVec;
	fracVec.push_back(Fraction(1,2));
	fracVec.push_back(Fraction(3,4));
	fracVec.push_back(Fraction(5,8));
	for( unsigned int i = 0; i < fracVec.size(); ++i)
	{
		cout << "fracVec[" << i << "]: ";
		fracVec[i].print();
	}

	// Fraction vector with initial size
	// Note that when these Fraction objects are created
	// the default Fraction constructor is called to
	// initialize the member variables.
	vector<Fraction> fracVec2(3);
	for( unsigned int i = 0; i < fracVec2.size(); ++i)
	{
		cout << "fracVec2[" << i << "]: ";
		fracVec2[i].print();
	}


	return 0;
}
