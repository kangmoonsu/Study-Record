#include <iostream>
using namespace std;

int main() {
    double money;
    cout << "Enter floating point value: ";
    cin >> money;
    
    // Convert dollars to cents(double into int).
    int cents = money * 100;

    int ten_dollars = cents / 1000;
    cents %= 1000;

    int five_dollars = cents / 500;
    cents %= 500;

    int one_dollar = cents / 100;
    cents %= 100;

    int quarters = cents / 25;
    cents %= 25;

    int dimes = cents / 10;
    cents %= 10;

    int nickels = cents / 5;
    cents %= 5;

    int pennies = cents;

    // Result
    cout << ten_dollars << " ten-dollar bill(s)" << endl;
    cout << five_dollars << " five-dollar bill(s)" << endl;
    cout << one_dollar << " one-dollar bill(s)" << endl;
    cout << quarters << " quarter(s)" << endl;
    cout << dimes << " dime(s)" << endl;
    cout << nickels << " nickel(s)" << endl;
    cout << pennies << " pennies(s)" << endl;

    return 0;
}