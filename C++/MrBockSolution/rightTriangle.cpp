#include <iostream>
using namespace std;
#include <cmath>

int main()
{
	// Continue if not done
	bool done = false;
	while( !done )
	{
		// Display the menu
		cout << endl;
		cout << "=========================" << endl;
		cout << "Right Triangle calculator" << endl;
		cout << "=========================" << endl;
		cout << "Please select an option from the menu below" << endl;
		cout << "1) Input the lengths of side a and b of a right triangle" << endl;
		cout << "2) Input the length of side a and angle alpha of a right triangle" << endl;
		cout << "3) Quit the program" << endl;

		// Input menu selection
		int menuItem;
		cin >> menuItem;

		// Declare triangle variables
		double a,b,c;
		double alpha,beta;

		// Declare constants
		const double RADIANS_TO_DEGREES = 180.0/M_PI;
		const double DEGREES_TO_RADIANS = M_PI/180.0;

		// Process menu item selection
		switch(menuItem)
		{
		case 1:			// Input sides a and b
			cout << "Enter length of side a: ";
			cin >> a;
			cout << "Enter length of side b: ";
			cin >> b;
			c = sqrt( pow(a,2) + pow(b,2) );
			alpha = asin(a/c) * RADIANS_TO_DEGREES;
			beta = 90.0 - alpha;
			cout << "Results:" << endl;
			cout << "  Length of hypotenuse (c): " << c << endl;
			cout << "  Angle of alpha in degrees: " << alpha << endl;
			cout << "  Angle of beta in degrees: " << beta << endl;
			break;

		case 2:			// Input side a, and alpha
			cout << "Enter length of side a: ";
			cin >> a;
			cout << "Enter angle for alpha (in degrees): ";
			cin >> alpha;
			alpha *= DEGREES_TO_RADIANS;
			c = a/sin(alpha);
			b = c * cos(alpha);
			beta = 90.0 - (alpha*RADIANS_TO_DEGREES);
			cout << "  Length of side b: " << b << endl;
			cout << "  Length of hypotenuse (c): " << c << endl;
			cout << "  Angle of beta in degrees: " << beta << endl;
			break;

		case 3:			// Quit the program
			done = true;
			break;

		default:		// Incorrect menu item
			cout << "Incorrect menu selection, please try again" << endl;
		}
	}

	return 0;
}



