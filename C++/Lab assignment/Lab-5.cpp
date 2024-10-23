#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    bool running = true;
    int user_choose;
    const double RADIANS_TO_DEGREES = 180.0 / M_PI;
    const double DEGREES_TO_RADIANS = M_PI / 180.0;

    while (running)
    {
        cout << endl;
        cout << "===========================" << endl;
        cout << "Right Triangle Calculator" << endl;
        cout << "===========================" << endl;
        cout << "Please select an option from the menu below" << endl;
        cout << "1) Input the lengths of side a and b of a right triangle" << endl;
        cout << "2) Input the length of side a and angle alpha of a right triangle" << endl;
        cout << "3) Quit the program" << endl;

        cin >> user_choose;

        switch (user_choose)
        {
        case 1:
        {
            double a, b;
            cout << "Enter length of side a: ";
            cin >> a;
            cout << "Enter length of side b: ";
            cin >> b;

            double c = sqrt(pow(a, 2) + pow(b, 2));

            double alpha = atan(a / b) * RADIANS_TO_DEGREES;
            double beta = 90.0 - alpha;

            cout << "  Length of hypotenuse (c): " << c << endl;
            cout << "  Angle of alpha in degrees: " << alpha << endl;
            cout << "  Angle of beta in degrees: " << beta << endl;
            break;
        }
        case 2:
        {
            double a, alpha;
            cout << "Enter length of side a: ";
            cin >> a;
            cout << "Enter angle for alpha (in degrees): ";
            cin >> alpha;

            double alphaRad = alpha * DEGREES_TO_RADIANS;

            double b = a / tan(alphaRad);
            double c = a / sin(alphaRad);
            double beta = 90.0 - alpha;

            cout << "  Length of side b: " << b << endl;
            cout << "  Length of hypotenuse (c): " << c << endl;
            cout << "  Angle of beta in degrees: " << beta << endl;
            break;
        }
        case 3:
        {
            running = false;
            break;
        }
        default:
        {
            cout << "Incorrect menu selection, please try again." << endl;
        }
        }
    }

    return 0;
}