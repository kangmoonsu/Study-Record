
#include <iostream>
using namespace std;

int main()
{
	// Consider the example in the slides
	//
	// Condition in if statements are boolean expressions.
	// In other words, it must evaluate to either true or false.
	// Below, the condition is "are hours greater than 40?"
	// If it is true, the flow of control goes to the statements
	// under the if statement.
	// If it is false, the flow of control goes to the statements
	// under the else statement.
	// Note that hours must be GREATER than 40
	// to resolve to true. The condition will resolve
	// to false if it is LESS THAN OR EQUAL to 40
	int hours = 41;

	// If hours are greater than 40
	if(hours > 40)
	{
		cout << "Hours are greater than 40" << endl;
	}

	// If hours are less than or equal to 40
	if(hours < 40)
	{
		cout << "Hours are less than or equal to 40" << endl;
	}

	// We can combine the two statements into an
	// if-else branch to choose between one of the statements
	if(hours > 40)
	{
		cout << "Hours are greater than 40" << endl;
	}
	else
	{
		cout << "Hours are less than or equal to 40" << endl;
	}

	// We can also use if-else statements within if-else statements.
	// We call this nested if-else statements.
	int valueX = 10;
	if( valueX > 5 )
	{
		int valueY = 20;
		cout << "valueX is greater than 5" << endl;
		if( valueY > 20 )
		{
			cout << "valueY is greater than 20" << endl;
		}
		else
		{
			cout << "valueY is less than or equal to 20" << endl;
		}
	}
	else
	{
		cout << "valueX is less than or equal to 5" << endl;
	}

	// Be aware of precedence when using multiple conditions.
	//
	// Note in following example that the arithmetic
	// expression is evaluated first, then the conditions
	// from left to right. This can be read as:
	// "if total is less than (hours+5) AND found is false (or NOT found is true)"
	int total = 5;
	bool found = false;
	if(total < hours+5 && !found)
	{
		cout << "total, hours+5, found, !found: " << total << ", " << (hours+5) << ", " << found << ", " << !found << endl;
	}

	// Logical operators
	//
	// Boolean variables are useful for testing and indicating
	// some state in your code. For example, you might want to
	// use a boolean variable as a type of flag to indicate when
	// some process has been completed. You can use the boolean
	// variable combined with the logical NOT operator as shown
	// below to indicate the completion. You can read the 'if'
	// statement as "If the file read is NOT done, then..."
	bool fileRead = false;
	if(!fileRead)
	{
		cout << "File has not been read" << endl;
	}
	else
	{
		cout << "File has been read" << endl;

		// If the file has been read, indicate this by
		// setting the boolean variable to true
		fileRead = true;
	}

	// Multiple booleans in an expression with an OR operator
	// and logical NOT operator
	//
	// Statement will NOT execute if f is false and d is true
	// this results in (0 OR 0) which results in false
	bool f = false;
	bool d = true;
	if(f || !d)
	{
		cout << "The condition (f || !d) is true" << endl;
	}
	else
	{
		cout << "The condition (f || !d) is false" << endl;
	}


	// while loop
	//
	// One example of using a while loop is for gathering user commands.
	// Consider a menu prompting a user to choose from various tasks until
	// they select the task to indicate they are done.
	bool done = false;
	while( !done )
	{
		cout << "===========" << endl;
		cout << "1) Continue" << endl;
		cout << "2) Quit" << endl;
		cout << "===========" << endl;
		cout << "Enter your selection: " << endl;
		int value;
		cin >> value;
		if(value == 1)
		{
			cout << "you want to continue" << endl;
		}
		else
		{
			cout << "you want to quit" << endl;

			// We set the boolean variable to true
			// so that the next time we process the
			// condition in the while loop, the
			// condition will result in false and
			// terminate the loop.
			done = true;
		}
	}


	// do-while loop
	//
	// The "do-while" statement is typically used when you
	// need to execute the statement(s) in a while loop once
	// at the beginning before you begin testing the condition
	// in the "while" loop. Upon a true condition in the while loop,
	// these same statements will then continue. Consider the following
	// example. NOTE that unlike the single "while" statement we
	// looked at previously, the while statement has an ending semi-colon!
	int test = -1;
	do
	{
		cout << "In do statement, test is: " << test << endl;
		++test;
	}
	while(test >= 0 && test < 3);
	cout << "test: " << test << endl;


	// Increment and decrement operators add and subtract
	// by 1 and are typically used with integers as a way
	// of keeping count. We'll see later that these are
	// very useful when repeating some operation a certain
	// number of times
	int count = 10;
	count++;
	count++;
	cout << "count: " << count << endl;
	count--;
	count--;
	cout << "count: " << count << endl;

	// We can also use them before or after the variable
	// Before the variable is called "prefix"
	// After the variable is called "postfix"

	// Postfix is applied after an expression
	count = 15;
	total = count++;
	cout << "total, count: " << total << ", " << count << endl;

	// Prefix is applied before an expression
	count = 15;
	total = ++count;
	cout << "total, count: " << total << ", " << count << endl;


	// Infinite loops
	//
	// Care should be taken when using loops to avoid the case
	// where we never end the looping statement such as the example
	// in the slide. If this occurs in Eclipse, we can select the red
	// square button in the Console to end the program
/*

	count = 1;
	while( count <= 25 )
	{
		cout << "count: " << count << endl;
		count = count - 1;
	}
*/


	return 0;
}



