#include <iostream>
#include <cmath>

using namespace std;

double triangleArea(double base, double height);
double rectangleArea(double width, double height);
double circleArea(double radius);

int main()
{

    bool run = true;
    int user_choose;

    while (run)
    {
        cout << "======================" << endl;
        cout << "Shape areas calculator" << endl;
        cout << "======================" << endl;
        cout << "Please select an option from the menu below" << endl;
        cout << "1) Compute the area of a triangle" << endl;
        cout << "2) Compute the area of a rectangle" << endl;
        cout << "3) Compute the area of a circle" << endl;
        cout << "4) Quit the program" << endl;

        cin >> user_choose;

        switch (user_choose)
        {
        case 1:
        {
            double base, height;
            cout << "Enter base and height separated by a space: ";
            cin >> base >> height;
            cout << "  Area of triangle: " << triangleArea(base, height) << endl;
            break;
        }
        case 2:
        {
            double width, height;
            cout << "Enter length and width separated by a space: ";
            cin >> width >> height;
            cout << "  Area of rectangle: " << rectangleArea(width, height) << endl;
            break;
        }
        case 3:
        {
            double radius;
            cout << "Enter radius: ";
            cin >> radius;
            cout << "  Area of circle: " << circleArea(radius) << endl;
            break;
        }
        case 4:
        {
            run = false;
            break;
        }
        default:
            cout << "Incorrect menu selection, please try again" << endl;
        }
    }

    return 0;
}

double triangleArea(double base, double height)
{
    double area = (base * height) / 2;
    return area;
}

double rectangleArea(double width, double height)
{
    double area = width * height;
    return area;
}

double circleArea(double radius)
{
    double area = M_PI * pow(radius, 2);
    return area;
}