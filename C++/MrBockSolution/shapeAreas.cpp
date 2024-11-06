#include <iostream>
using namespace std;
#include <cmath>

// Function declarations
double areaTriangle( double, double );
double areaRectangle( double, double );
double areaCircle( double );

int main()
{
	// Continue if not done
	bool done = false;
	while( !done )
	{
		// Display the menu
		cout << endl;
		cout << "======================" << endl;
		cout << "Shape areas calculator" << endl;
		cout << "======================" << endl;
		cout << "Please select an option from the menu below" << endl;
		cout << "1) Compute the area of a triangle" << endl;
		cout << "2) Compute the area of a rectangle" << endl;
		cout << "3) Compute the area of a circle" << endl;
		cout << "4) Quit the program" << endl;

		// Input menu selection
		int menuItem;
		cin >> menuItem;

		// Declare variables
		double base, height;
		double length, width;
		double radius;
		double result;

		// Process menu item selection
		switch(menuItem)
		{
		case 1:			// Area of a triangle
			cout << "Enter base and height separated by a space: ";
			cin >> base >> height;
			result = areaTriangle( base, height );
			cout << "  Area of triangle: " << result << endl;
			break;

		case 2:			// Area of a rectangle
			cout << "Enter length and width separated by a space: ";
			cin >> length >> width;
			result = areaRectangle( length, width );
			cout << "  Area of rectangle: " << result << endl;
			break;

		case 3:			// Area of a circle
			cout << "Enter radius: ";
			cin >> radius;
			result = areaCircle( radius );
			cout << "  Area of circle: " << result << endl;
			break;

		case 4:			// Quit the program
			done = true;
			break;

		default:		// Incorrect menu item
			cout << "Incorrect menu selection, please try again" << endl;
		}

	}

	return 0;
}


// Function definition for area of a triangle
double areaTriangle( double base, double height )
{
	return (0.5 * base * height);
}

// Function definition for area of a rectangle
double areaRectangle( double length, double width )
{
	return (length * width);
}

// Function definition for area of a circle
double areaCircle( double radius )
{
	return ( M_PI * pow(radius,2) );
}


