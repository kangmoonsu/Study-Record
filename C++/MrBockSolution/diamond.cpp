
#include <iostream>
using namespace std;

int main()
{
	/* Prompt the user to enter a whole number between 0 and 9 */
	cout << "Please enter a whole number between 0 and 9: ";

	/* Declare a variable to store the number */
	int num;

	/* Get the number and store it in the variable */
	cin >> num;

	/* Design a diamond shape with the number in the middle row */
	cout << endl;
	cout << "    +    " << endl;
	cout << "   ***   " << endl;
	cout << "  #####  " << endl;
	cout << " ******* " << endl;
	cout << num << num << num << num << num << num << num << num << num << endl;
	cout << " ******* " << endl;
	cout << "  #####  " << endl;
	cout << "   ***   " << endl;
	cout << "    +    " << endl;

	return 0;
}


