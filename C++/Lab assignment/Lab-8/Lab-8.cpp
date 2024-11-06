
#include <iostream>
#include <fstream>
#include <iomanip>
//#include <cstdlib>


// double base, bonus, deduction;
// same directory
// for loop 
// use .struct. name : Salary -> double base, bonus, deduction, net salary
// void computeNet(Salary &)
// void printSalary(Salary)
// output same as reference
// refresh object 가능
// 10번 반복되는걸 가정하고

// struct Salary {
//     double base;
//     double deduction;
//     double bonus;
//     double netSalary;
// }

using namespace std;

void printFile( ofstream & );

int main()
{
	ifstream inFile;

	char fileName[20] = "payroll.txt";
	inFile.open( fileName );

	
	if( inFile.fail() )
	{
		cout << "Error opening file" << endl;
		exit(1);
	}
	else
	{
		cout << "Success opening file" << endl;
	}

	float val1, val2, val3;
	inFile >> val1 >> val2 >> val3;
	cout << "Values read from the file: " << val1 << ", " << val2 << ", " << val3 << endl;

	inFile.close();

	cout << "Default formatting of decimal values above: " << val1 << ", " << val2 << ", " << val3 << endl;

	// setf w/ fixed and scientific
	//
	cout << endl;
	cout.setf(ios::fixed);
	cout << "setf(ios::fixed): " << val1 << ", " << val2 << endl;
	// Note how we can unset formatting
	// In this case we return to the default
	cout.unsetf(ios::fixed);
	cout << "Back to default: " << val1 << ", " << val2 << endl;

	// precision
	//
	// We can experiment with the precision
	// member function (Note that this function
	// changes its output based on the setf flags)
	// Applies to total number of digits
	cout << endl;
	cout.precision(2);
	cout << "precision(2) without setf(ios::fixed): " << val1 << ", " << val2 << endl;
	// Used with setf(ios::fixed)
	// Applies to number of digits after decimal point
	cout.setf(ios::fixed);
	cout << "precision(2) with setf(ios::fixed): " << val1 << ", " << val2 << endl;
	// Scientific notation
	cout.unsetf(ios::fixed);
	cout.setf(ios::scientific);
	cout << "precision(2) with setf(ios::scientific): " << val1 << ", " << val2 << endl;
	cout.precision(6);
	cout << "precision(6) with setf(ios::scientific): " << val1 << ", " << val2 << endl;


	cout << endl;
	cout.unsetf(ios::fixed);
	cout.unsetf(ios::scientific);
	cout.precision(6);
	cout << "Back to default: " << val1 << ", " << val2 << endl;
	cout.setf(ios::showpoint);
	cout << "setf(ios::showpoint): " << val1 << ", " << val2 << endl;
	cout.setf(ios::fixed);
	cout.precision(3);
	cout << "fixed, precision(3), showpoint: " << val1 << ", " << val2 << endl;

	// setf w/ showpos
	//
	cout << endl;
	cout.precision(6);
	cout.unsetf(ios::fixed);
	cout.unsetf(ios::scientific);
	cout.unsetf(ios::showpoint);
	cout << "Back to default: " << val1 << ", " << val2 << endl;
	cout.setf(ios::showpos);
	cout << "setf(ios::showpos): " << val1 << ", " << val2 << endl;

	cout.unsetf(ios::fixed);
	cout.unsetf(ios::scientific);
	cout.unsetf(ios::showpos);
	cout.precision(6);
	cout << "Back to default: " << val1 << ", " << val2 << endl;

	// width
	//
	// Note that this applies ONLY
	// to the next item printed and
	// does not stay active as the other
	// formatting methods above
	for( int i = 0; i < 10; ++i )
	{
		cout << "formatting val1 with width(" << i << ")" << endl;
		cout.width(i);
		cout << val1 << endl;
	}

	// Manipulators
	//
	// We can accomplish many of the same types
	// of formatting above using manipulator
	// functions instead of stream member functions
	// Below we look at the manipulator function
	// to format width and precision
	// Note that to use manipulators, you must
	// include the #include <iomanip> header file
	// shown at the top of this file
	for( int i = 0; i < 10; ++i )
	{
		cout << "formatting val1 with setw(" << i << ")" << endl;
		cout << setw(i) << val1 << endl;
	}
	// We can add a manipulator to specify
	// left or right justification
	for( int i = 0; i < 10; ++i )
	{
		cout << "formatting val1 with setw(" << i << ")" << endl;
		cout << setw(i) << val1 << endl;
	}
	// We can use flags to specify where
	// value is specified with padding left or right
	cout << "Two stays on left, padding on right" << endl;
	for( int i = 5; i < 10; ++i )
	{
		cout << "One" << " " << setw(i) << std::left << "Two" << " " << "Three" << endl;
	}
	cout << "Two stays on right, padding on left" << endl;
	for( int i = 5; i < 10; ++i )
	{
		cout << "One" << " " << setw(i) << std::right << "Two" << " " << "Three" << endl;
	}
	for( int i = 4; i < 16; ++i )
	{
		cout << "formatting val2 with setprecision(" << i << ")" << endl;
		cout << setprecision(i) << val2 << endl;
	}


	// Stream variables as input arguments
	//
	// Note that input stream parameters
	// must be specified via call-by-reference
	// Let's open a file, check it's success,
	// then send the output file stream object
	// to a function that will print a line
	// of integers to the file, then close the file.
	// To check your result after running this
	// program, be sure to select your project
	// and refresh to see the
	// file created in the directory under your project.
	cout << "Enter a file name: ";
	cin >> fileName;
	ofstream outFile;
	outFile.open( fileName );
	if( outFile.fail() )
	{
		cout << "Error opening output file: " << fileName << endl;
		exit(1);
	}
	printFile( outFile );
	outFile.close();


	// Now let's read the file we just created
	// using the technique from the textbook
	// that shows how to read the file of values
	// until there are no more to read
	ifstream readFile( fileName );
	if( readFile.fail() )
	{
		cout << "Error opening output file: " << fileName << endl;
		exit(1);
	}
	cout << "Values in the file: ";
	int ival;
	while( readFile >> ival )
	{
		cout << ival << " ";
	}
	cout << endl;
	readFile.close();


	// get member function for keyboard input
	//
	// Prompt for a single character input
	cout << "Enter a single character and press return: ";
	//
	// Get the character (or symbol)
	// Note the input parameter is called by reference (see slides)
	// Try entering a alphanumeric value (character or number)
	// Try just pressing return as the character and note the result
	// Although a new-line character can't be output, it has an ASCII code
	//
	// See: https://en.cppreference.com/w/cpp/language/ascii
	//
	// Note how we convert the character to its integer code
	//    static_cast<int>(nextSymbol)
	//

	// Since a newline character remains in the input 
	// buffer from our previous tests above, we instruct
	// the input stream to ignore it before asking the 
	// user to input a character. Without this statement,
	// the stream will read the previous newline character
	// and appear to "skip" over the get function below.
	cin.ignore();
	char nextSymbol;
	cin.get( nextSymbol );
	cout << "You typed the character: " << nextSymbol << endl;
	cout << "The integer code of this character is: " << static_cast<int>(nextSymbol) << endl;


	// get member function for file input
	//
	// Create a new text file by selecting
	// File->New File in the project you are
	// working in. Name the file "data2.txt"
	// to indicate a text file to store data.
	// Inside the file specify some characters
	// on two lines as
	// ab
	// cd
	// and save the file
	//
	// Open a file for input
	cout << endl;
	char fileName2[20] = "data2.txt";
	cout << "Opening file for input" << endl;
	ifstream inFile2( fileName2 );
	if( inFile2.fail() )
	{
		cout << "Opening input file: " << fileName2 << " fail" << endl;
		exit(1);
	}
	//
	// Get the character (or symbol)
	inFile2.get( nextSymbol );
	cout << "You read the character: " << nextSymbol << endl;
	cout << "The integer code of this character is: " << (int)nextSymbol << endl;
	// Read more characters (or symbols)
	// Note the output of c3 shows a new-line since
	// it is considered a character (symbol) read
	char c2, c3, c4, c5;
	inFile2.get( c2 );
	inFile2.get( c3 );
	inFile2.get( c4 );
	inFile2.get( c5 );
	cout << "c2: " << c2 << ", integer code: " << (int)c2 << endl;
	cout << "c3: " << c3 << ", integer code: " << (int)c3 << endl;
	cout << "c4: " << c4 << ", integer code: " << (int)c4 << endl;
	cout << "c5: " << c5 << ", integer code: " << (int)c5 << endl;
	inFile2.close();

	// put member function for screen output
	//
	// Outputs a single character to the screen
	nextSymbol = 'S';
	cout << endl;
	cout << "Outputting value of a single character: ";
	cout.put( nextSymbol );
	cout << endl;

	// cin and cin.get problem with new-line example
	//
	// Note how the character stored in the
	// symbol variable is actually a new-line.
	cout << "Enter a number: " << endl;
	// cin below reads up to the new-line
	// The new-line character remains on the input stream
	int number;
	cin >> number;
	cout << "number: " << number << endl;
	// cin.get reads the input stream which has the
	// new-line from cin above still on it!
	cout << "Now enter a letter: " << endl;
	char symbol;
	cin.ignore();
	cin.get(symbol);
	cout << "symbol: " << symbol << endl;

	// We can fix this without using cin.get
	cout << "Enter a number: " << endl;
	cin >> number;
	cout << "number: " << number << endl;
	cout << "Now enter a letter: " << endl;
	cin >> symbol;
	cout << "symbol: " << symbol << endl;

	// Reading a file until its end
	//
	// We can use the member function eof
	// to help read a file until finished
	// Let's re-open our file named "data.txt" from above
	cout << endl;
	inFile.open( fileName );
	if( inFile.fail() )
	{
		cout << "Opening input file: " << fileName << " fail" << endl;
		exit(1);
	}
	// Read the first character
	char next;
	inFile.get(next);
	// Now we'll read until there are no more characters
	// to read. Note since eof returns false when end
	// of file is reached, we test the inverse
	// "while the end is NOT reached"
	//while( !inFile.eof()  )
	while( inFile.get(next) )
	{
		cout << "next: " << next << endl;
		//inFile.get(next);
	}
	inFile.close();

	// Predefined character functions
	//
	// C++ provides functions (not part of a class)
	// that operate on characters. As discussed in the
	// textbook, below are a few examples.
	// Convert between lower and upper case.
	// Note that toupper returns the integer ASCII
	// code of the character. As a result, we must
	// convert it to a character variable using
	// the static_cast as we saw previously
	char ch1 = 'a';
	char ch2 = static_cast<char>(toupper(ch1));
	cout << "Character " << ch1 << " converted to uppercase: " << ch2 << endl;
	// These functions return boolean indicators (true/false)
	// that perform tests on the character.
	cout << "The character " << ch2 << " is a letter of the alphabet: " << isalpha(ch2) << endl;
	cout << "The character " << ch2 << " is a digit: " << isdigit(ch2) << endl;



	return 0;
}

// Function definition to print a line
// of integers to an output file stream object
void printFile( ofstream &out )
{
	// Print a series of integers in the file
	for(int i = 0; i < 20; ++i)
		out << i << " ";
	out << endl;
}

