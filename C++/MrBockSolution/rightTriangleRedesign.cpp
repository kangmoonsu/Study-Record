#include <iostream>
using namespace std;
#include <cmath>

// Function declarations
void displayMenu();
void rightTriangle_case1(double a, double b, double &c, double &alpha, double &beta);
void rightTriangle_case2(double a, double &b, double &c, double alpha, double &beta);
void rightTriangle_case3(double a, double &b, double c, double &alpha, double &beta);
void rightTriangle_case4(double &a, double &b, double c, double alpha, double &beta);
void displayValues(double a, double b, double c, double alpha, double beta);

// Declare global constants
const double RADIANS_TO_DEGREES = 180.0/M_PI;
const double DEGREES_TO_RADIANS = M_PI/180.0;

int main()
{
	// Continue if not done
	bool done = false;
	while( !done )
	{
		// Display the menu
		displayMenu();

		// Input menu selection
		int menuItem;
		cin >> menuItem;

		// Declare triangle variables
		double a,b,c;
		double alpha,beta;

		// Process menu item selection
		switch(menuItem)
		{
		case 1:			// Input sides a and b
			cout << "Enter length of side a: ";
			cin >> a;
			cout << "Enter length of side b: ";
			cin >> b;
			rightTriangle_case1(a,b,c,alpha,beta);
			displayValues(a,b,c,alpha,beta);
			break;

		case 2:			// Input side a and alpha
			cout << "Enter length of side a: ";
			cin >> a;
			cout << "Enter angle for alpha (in degrees): ";
			cin >> alpha;
			rightTriangle_case2(a,b,c,alpha,beta);
			displayValues(a,b,c,alpha,beta);
			break;

		case 3:			// Input side a and hypotenuse
			cout << "Enter length of side a: ";
			cin >> a;
			cout << "Enter length of hypotenuse(c): ";
			cin >> c;
			rightTriangle_case3(a,b,c,alpha,beta);
			displayValues(a,b,c,alpha,beta);
			break;

		case 4:			// Input hypotenuse and alpha
			cout << "Enter length of hypotenuse(c): ";
			cin >> c;
			cout << "Enter angle for alpha (in degrees): ";
			cin >> alpha;
			rightTriangle_case4(a,b,c,alpha,beta);
			displayValues(a,b,c,alpha,beta);
			break;

		case 5:			// Quit the program
			done = true;
			break;

		default:		// Incorrect menu item
			cout << "Incorrect menu selection, please try again" << endl;
		}
	}

	return 0;
}

// Function definitions
void displayMenu()
{
	cout << endl;
	cout << "=========================" << endl;
	cout << "Right Triangle calculator" << endl;
	cout << "=========================" << endl;
	cout << "Please select an option from the menu below" << endl;
	cout << "1) Input the lengths of side a and b of a right triangle" << endl;
	cout << "2) Input the length of side a and angle alpha of a right triangle" << endl;
	cout << "3) Input the length of side a and hypotenuse c of a right triangle" << endl;
	cout << "4) Input the length of hypotenuse c and angle alpha of a right triangle" << endl;
	cout << "5) Quit the program" << endl;
}
void displayValues(double a, double b, double c, double alpha, double beta)
{
	cout << "Results:" << endl;
	cout << "  Length of side a: " << a << endl;
	cout << "  Length of side b: " << b << endl;
	cout << "  Length of hypotenuse (c): " << c << endl;
	cout << "  Angle of alpha in degrees: " << alpha << endl;
	cout << "  Angle of beta in degrees: " << beta << endl;
}
void rightTriangle_case1( double a, double b, double &c, double &alpha, double &beta )
{
	c = sqrt( pow(a,2) + pow(b,2) );
	alpha = asin(a/c) * RADIANS_TO_DEGREES;
	beta = 90.0 - alpha;
}
void rightTriangle_case2( double a, double &b, double &c, double alpha, double &beta )
{
	alpha *= DEGREES_TO_RADIANS;
	c = a/sin(alpha);
	b = c * cos(alpha);
	beta = 90.0 - (alpha*RADIANS_TO_DEGREES);
}
void rightTriangle_case3( double a, double &b, double c, double &alpha, double &beta)
{
	b = sqrt( pow(c,2) - pow(a,2) );
	alpha = asin(a/c) * RADIANS_TO_DEGREES;
	beta = 90.0 - alpha;
}
void rightTriangle_case4( double &a, double &b, double c, double alpha, double &beta)
{
	alpha *= DEGREES_TO_RADIANS;
	a = c * sin(alpha);
	b = sqrt( pow(c,2) - pow(a,2) );
	beta = 90.0 - (alpha * RADIANS_TO_DEGREES);
}

