/* Example program to input and output information.
 * Note how we name this file using the file extension (.cpp)
 * to denote that this file contains source code instructions
 * for the C++ language. Use this convention for all of your
 * assignments. */

#include <iostream>
using namespace std;

int main()
{
	/* Let's output some information to the Console
	 * Note the Console is the window below that displays the output
	 * Below we are using cout to print text and symbols.
	 * Note how we are using endl as discussed in the slide notes
	 * to output a new-line instead of using '\n'
	 */
	cout << "------------------" << endl;
	cout << "Welcome to CSC 123" << endl;
	cout << "------------------" << endl;

	/* We can also use spaces to arrange our output.
	 * Note also how we can create new-lines without any text */
	cout << "==========================" << endl;
	cout << endl;
	cout << "||   Welcome to CSC 123 ||" << endl;
	cout << endl;
	cout << "==========================" << endl;

	/* Let's ask the user to input some information.
	 * Notice how we are not using a new-line below.
	 * This way, when the user enters a number, it will
	 * appear immediately after the colon.
	 */
	cout << "Please enter a whole number between 1 and 10: ";

	/* Now will get the number from the user and store
	 * it in what we call a variable. We'll discuss variables
	 * more in-depth in upcoming topics. Below we first create
	 * a variable (named count) and then input the number
	 * and store it in this variable all using cin.
	 */
	int count;
	cin >> count;

	/* To make sure we input and stored the information correctly,
	 * we'll print it back out using the variable name.
	 */
	cout << "You entered the number: " << count << endl;

	return 0;
}




