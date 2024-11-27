
#include <iostream>
using namespace std;
#include <cstring>

// Note that for some compilation systems
// the following string class header file
// is not necessary.
#include <string>

// Function declaration to print each character
// and corresponding ASCII table integer of an
// input C-string given the input array size
void printCstring(char[], int);

int main()
{
	// Character arrays - C-strings
	//
	// C-strings are a method of storing
	// a sequence of characters in an array.
	// The end of the sequence is indicated using
	// a special character, '/0', called a null
	// character occupying the position in the
	// array after the last character.
	// This method was developed as
	// part of the original C language before
	// the C++ class was developed and is still
	// in use today especially in older software.
	//
	// We can initialize a character array
	// with a sequence in double quotes which
	// represents our string. Below we use
	// an array one size larger than the number
	// of characters. This is to accommodate space
	// for the null character.
	char carray1[8] = "CSC 123";

	// The null character '/0' is added
	// automatically after the last character
	// when using this method of initialization.
	// We can verify this by printing out the integer
	// equivalent of each character. Note that the last
	// character is 0 which corresponds to the value
	// of the null character in the ASCII table.
	// https://en.cppreference.com/w/cpp/language/ascii
	printCstring(carray1,8);

	// Note we can allocate an array of a maximum
	// size and fill it with strings less than the
	// maximum. The characters up to the null character
	// will be used.
	char carray1_1[25] = "This is fun";
	cout << "carray1_1: " << carray1_1 << endl;
	// The array positions after the null character
	// are ignored, but we can print them out to examine
	// their contents. In this case they are initialized
	// to null as well, although this may not be the
	// case depending on the compiler used.
	printCstring(carray1_1,25);

	// We can also initialize without an array size.
	// In this case, an array 1 more than the number
	// of characters is created for us. Note the null
	// character added automatically.
	char carray2[] = "Hello";
	printCstring(carray2,6);

	// If we wanted to build a string character by
	// character, we cannot initialize as below
	// since the null character will NOT be added
	//char carray3[4] = { 'c', 's', 's' };

	// Instead, we could fill the array manually
	// inserting the null character in the last position.
	char carray3[4];
	carray3[0] = 'c';
	carray3[1] = 's';
	carray3[2] = 'c';
	carray3[3] = '\0';
	printCstring(carray3,4);

	// Oftentimes we'd like to assign a string to
	// an existing character array after it has been
	// declared.
	char carray4[9];

	// We cannot use this since this is an assignment
	// statement operation. An array doesn't know how
	// to handle this assignment.
	//carray4 = "Hi there";

	// Instead we use predefined functions designed
	// to work with C-strings. One of these functions
	// copies characters from one C-string to another.
	// http://www.cplusplus.com/reference/cstring/
	// Note to use this we must include its function
	// declaration which is included with other C-string
	// functions in the header file "cstring" specified
	// at the beginning of our program above. This
	// function also inserts the null character at
	// the end of the array copied.
	strcpy(carray4, "Hi there");
	printCstring(carray4,9);

	// Another useful predefined C-string function
	// is one used to compare C-strings.
	// This function returns 
	//		- 0 if the strings match,
	//		- a negative value if the first string is "less than" the second
	//		- a positive number if the first string is "greater than" the second
	// Note that "less than and greater than" refer to comparisons in
	// lexographic order (e.g. alphabetic).
	char cmp1[] = "BBBB";
	char cmp2[] = "AAAA";
	int retVal = strcmp(cmp1,cmp2);
	if(retVal < 0)
	{
		cout << cmp1 << " is less to " << cmp2 << endl;
	}
	else if(retVal > 0)
	{
		cout << cmp1 << " is greater to " << cmp2 << endl;
	}
	else
	{
		cout << cmp1 << " is equal to " << cmp2 << endl;
	}

	// Other Cstring functions returns the length (strlen)
	// and concatenate one string with another (strcat)
	char carray5[] = " 123";
	cout << "Length of carray5: " << strlen(carray5) << endl;
	char carray6[25] = "Chicago";
	char carray7[] = " Cubs";
	strcat(carray6,carray7);
	cout << "carray6: " << carray6 << endl;

	// We've been using cout with C-strings above.
	// We can also assign strings using cin.
	char carray8[10];
	cout << "Enter yes or no: ";
	cin >> carray8;
	cin.ignore();			// ignores the extra line created when pressig "Enter"
	cout << "You entered: " << carray8 << endl;

	// The stream member function getline
	// can be used with C-strings to read lines
	char line[100];
	// Before we test getline, we need to be aware
	// that there was a cin statement used previously.
	// Remember that cin will read until it sees a
	// newline character. It then stops and leaves
	// this newline character sitting in the input
	// stream buffer. A newline character is entered
	// above after the user enters yes or no.
	// As a result, this newline character will
	// be the first thing read if cin is used again.
	// Note that if we try to use cin.getline below
	// It seems to skip the user input. What is happening
	// is cin read the newline that was sitting in
	// the input buffer from above. After reading this
	// cin terminates. What we need to do is to use
	// the stream function ignore commented below to
	// first ignore this newline character before
	// attempting to read the next input.
	//cin.ignore();
	cout << "Enter your first and last name:";
	cin.getline(line,100);
	cout << "You entered: " << line << endl;

	// A very useful function converts C-strings
	// into number values. This is useful
	// in general purpose programs where all
	// information might be read in as C-strings.
	// If some of the C-strings are actual number
	// values, these functions can be used.
	//
	// Convert a C-string to an integer
	char ci[] = "77";
	int ival = atoi(ci);
	cout << "ci converted to an integer: " << ival << endl;

	// Convert a C-string to an float
	char cf[] = "77.76";
	float fval = atof(cf);
	cout << "cf converted to an float: " << fval << endl;


	// C++ class representing a string
	// http://www.cplusplus.com/reference/string/string/
	string s1;

	// Assignment
	s1 = "Hello";
	cout << "s1: " << s1 << endl;

	// Concatentation
	string s2 = " there	";
	cout << "s2: " << s2 << endl;
	string s3 = s1 + s2;
	cout << "s3: " << s3 << endl;

	// Initialization
	// method 1
	string s4 = "Initialized with assignment";
	cout << "s4: " << s4 << endl;
	// method 2, using string constructor
	string s5("Initialized using constructor");
	cout << "s5: " << s5 << endl;

	// Input
	// Note cin reads up to whitespace
	string s6;
	cout << "Enter yes or no: ";
	cin >> s6;
	cout << "You entered: " << s6 << endl;

	// Input
	// To enter more than one string
	// we can use getline with a C++ string.
	// Note, as in our previous study with
	// C-strings, we first need to ignore
	// the new-line character sitting in the
	// input stream buffer when the user pressed
	// Enter from the previous entry above.
	cin.ignore();
	string s7;
	cout << "Enter first and last name: ";
	getline(cin,s7);
	cout << "You entered: " << s7 << endl;

	// Accessing characters in a C++ string class.
	// Notice we can use a member function length()
	// to return the length of a C++ string.
	// Not that since this function returns an unsigned integer,
	// some compilers may require that we first type cast it into 
	// an integer to use with our for loop below. Other compilers
	// can accept a signed integer.
	//int len = static_cast<unsigned int>(s7.length());
	int len = s7.length();
	for( int i = 0; i < len; ++i)
	{
		cout << "s7[" << i << "]: " << s7[i] << endl;
	}

	// As an alternative, we can also use the member
	// function at() in the same manner.
	for( int i = 0; i < len; ++i)
	{
		cout << "s7[" << i << "]: " << s7.at(i) << endl;
	}

	// Lexographic string comparison
	string s8 = "BBBB";
	string s9 = "AAAA";
	cout << "s8, s9: " << s8 << ", " << s9 << endl;
	if( s8 == s9 )
	{
		cout << "s8 is equal to s9" << endl;
	}
	else if( s8 < s9 )
	{
		cout << "s8 is less than s9" << endl;
	}
	else if( s8 > s9 )
	{
		cout << "s8 is greater than s9" << endl;
	}

	// Extract a sub-string from within a string
	// using a member function substr()
	string s10 = "hello there";
	// Extract the string at between and including
	// index 6 to the end of the string.
	string s11 = s10.substr(6, s10.length()-1);
	cout << "s10: " << s10 << endl;
	cout << "s11: " << s11 << endl;

	// Convert C-string to C++ class
	char cstr[] = "I'm a C-string";
	string s12 = cstr;
	cout << "s12: " << s12 << endl;


	return 0;
}

// Function to print each character and corresponding
// ASCII table integer of an input C-string given
// the input array size
void printCstring(char cstring[], int size)
{
	cout << "cstring: " << cstring << endl;
	for( int i = 0; i < size; ++i)
	{
		cout << "cstring[" << i << "]: " << cstring[i] << " " << static_cast<int>(cstring[i]) << endl;
	}
}




