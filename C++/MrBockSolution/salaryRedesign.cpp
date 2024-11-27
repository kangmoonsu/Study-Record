
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Number of lines in file
const int NUM_LINES = 10;

// Salary class
class Salary
{
	// What the class "knows"
private:
	double base;
	double bonus;
	double deductionPercent;
	double net;

	// What the class "does"
public:

	// Constructors
	Salary();								// default
	Salary(double,double,double,double);	// w/ input parameters

	// Compute net salary
	void computeNet();

	// Print information
	void print();

	// Access methods (get/set)
	double getBase();
	void setBase(double);
	double getBonus();
	void setBonus(double);
	double getDeduction();
	void setDeduction(double);
	double getNet();
	void setNet(double);
};

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

	// Declare an array of Salary objects
	Salary salaries[NUM_LINES];

	// Temporary variables
	double tmpBase, tmpBonus, tmpDeduction;

	// For each line in the file
	Salary salary;
	for(int i = 0; i < NUM_LINES; ++i)
	{
		// Read and store base amount
		inFile >> tmpBase;

		// Read and store bonus amount
		inFile >> tmpBonus;

		// Read and store percent deduction amount
		inFile >> tmpDeduction;

		// Create a salary object, assign the
		// information read, and assign to array
		salaries[i] = Salary(tmpBase, tmpBonus, tmpDeduction, 0.0 );
		// We also could have done the following
		// salaries[i] = { tmpBase, tmpBonus, tmpDeduction, 0.0 };

		// We also could have done the following
		/*
		Salary salary;
		salary.setBase(tmpBase);
		salary.setBonus(tmpBonus);
		salary.setDeduction(tmpDeduction);
		salaries[i]	= salary;
		 */
	}

	// Close payroll file
	inFile.close();

	// For each salary
	for(int i = 0; i < NUM_LINES; ++i)
	{
		salaries[i].computeNet();
		salaries[i].print();
	}

	return 0;
}

// Salary class definitions
Salary::Salary()
{
	base = 0.0;
	bonus = 0.0;
	deductionPercent = 0.0;
	net = 0.0;
}
Salary::Salary(double a, double b, double c, double d)
{
	base = a;
	bonus = b;
	deductionPercent = c;
	net = d;
}

// Function definitions
void Salary::computeNet()
{
	double deduction = (base + bonus) * deductionPercent;
	net = (base + bonus) - deduction;
}
void Salary::print()
{
	cout << "Base, Bonus, Deduction, NetSalary:";
	cout.precision(9);
	cout << setw(9) << base;
	cout << setw(7) << bonus;
	cout << setw(6) << deductionPercent;
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << setw(12) << net;
	cout.unsetf(ios::fixed);
	cout << endl;
}
double Salary::getBase()
{
	return base;
}
void Salary::setBase(double d)
{
	base = d;
}
double Salary::getBonus()
{
	return bonus;
}
void Salary::setBonus(double d)
{
	bonus = d;
}
double Salary::getDeduction()
{
	return deductionPercent;
}
void Salary::setDeduction(double d)
{
	deductionPercent = d;
}
double Salary::getNet()
{
	return net;
}
void Salary::setNet(double d)
{
	net = d;
}


