
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Salary struct data type
struct Salary
{
	double base;
	double bonus;
	double deduction;
	double net;
};

// Function definitions
void printSalary( Salary );
void computeNet( Salary & );

// Number of lines in file
const int NUM_LINES = 10;

int main()
{
	// Open payroll file
	char fileName[20] = "payroll.txt";
	ifstream inFile( fileName );
	if( inFile.fail() )
	{
		cout << "Error opening " << fileName << endl;
		exit(1);
	}

	// Declare a Salary struct variable
	Salary salary;

	// For each line in the file
	for(int i = 0; i < NUM_LINES; ++i)
	{
		// Read and store base amount
		inFile >> salary.base;

		// Read and store bonus amount
		inFile >> salary.bonus;

		// Read and store percent deduction amount
		inFile >> salary.deduction;

		// Compute net amount
		computeNet( salary );

		// Print salary
		printSalary( salary );
	}

	// Close payroll file
	inFile.close();

	return 0;
}

// Function definitions
void computeNet( Salary &s )
{
	double deduction = (s.base + s.bonus) * s.deduction;
	s.net = (s.base + s.bonus) - deduction;
}
void printSalary( Salary s )
{
	cout << "Base, Bonus, Deduction, NetSalary:";
	cout.precision(9);
	cout << setw(9) << s.base;
	cout << setw(7) << s.bonus;
	cout << setw(6) << s.deduction;
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << setw(12) << s.net;
	cout.unsetf(ios::fixed);
	cout << endl;
}

