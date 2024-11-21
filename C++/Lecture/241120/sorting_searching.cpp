#include <iostream>
using namespace std;

// Function declarations
void printArray( const int[], int);
void selectionSort( int[], int );
bool linearSearch(int[], int, int );
bool binarySearch(int[], int, int );

int main()
{
    // Create array of integers
    const int size = 5;
    int iarray[size];

    //
    // Selection example - selection sort
    //
    // Assign values
    iarray[0] = 3;
    iarray[1] = 9;
    iarray[2] = 6;
    iarray[3] = 1;
    iarray[4] = 2;

    cout << endl;
    cout << "Array before selection sort:" << endl;
    printArray(iarray, size);
    selectionSort(iarray, size);
    cout << "Array after selection sort:" << endl;
    printArray(iarray, size);

    //
    // Searching example - linear search
    //
    // Assign values
    iarray[0] = 23;
    iarray[1] = 5;
    iarray[2] = 68;
    iarray[3] = 99;
    iarray[4] = 3;

    // Target value to search in array
    int target = 68;
    cout << endl;
    cout << "Array before linear search:" << endl;
    printArray(iarray, size);
    cout << "Searching for target: " << target << endl;
    bool found = linearSearch(iarray, size, target);
    if(found)
        cout << "Target " << target << " was found in the array" << endl;
    else
        cout << "Target " << target << " was not found in the array" << endl;

    //
    // Searching example - binary search
    //
    // Assign values
    iarray[0] = 23;
    iarray[1] = 5;
    iarray[2] = 68;
    iarray[3] = 99;
    iarray[4] = 3;

    // Target value to search in array
    target = 99;
    cout << endl;
    cout << "Array before binary search:" << endl;
    printArray(iarray, size);
    cout << "Array after required sort:" << endl;
    selectionSort(iarray, size);
    printArray(iarray, size);
    cout << "Searching for target: " << target << endl;
    found = binarySearch(iarray, size, target);
    if(found)
        cout << "Target " << target << " was found in the array" << endl;
    else
        cout << "Target " << target << " was not found in the array" << endl;
    cout << endl;

    
    return 0;
}

// Print the array elements, const keyword assures that 
// the function won't change the values in the array
void printArray( const int array[], int size )
{
	for(int i = 0; i < size; ++i)
	{
		cout << "array[" << i << "]: " << array[i] << endl;
	}
}

// Sort the elements in the array using the selection sort
// algorithm. Note that since we are changing the values,
// we do not use the const keyword on the array
void selectionSort(int items[], int size)
{
    int min, temp;
    for (int i = 0; i < size; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (items[j] < items[min])
                min = j;
        }

        // Swap the values
        temp = items[min];
        items[min] = items[i];
        items[i] = temp;
    }
}

// Searches the array for an integer using a linear search
// algorithm. Function returns boolean value (true) if the 
// target was found or (false) if the target was not found.
// Note that since we are changing the values, we do not 
// use the const keyword on the array.
bool linearSearch(int items[], int size, int target)
{
    int index = 0;
    bool found = false;

    while (!found && index < size)
    {
        if (items[index] == target)
            found = true;
        else
            index++;
    }

    // Return result
    return found;
}

// Searches the array for an integer using a binary search
// algorithm. Algorithm requires input array to be sorted
// beforehand. Function returns boolean value (true) if the 
// target was found or (false) if the target was not found.
// Note that since we are changing the values, we do not 
// use the const keyword on the array.
bool binarySearch(int items[], int size, int target)
{
    int min = 0;
    int max = size;
    int mid = 0;
    bool found = false;

    while (!found && min <= max)
    {
        mid = (min + max) / 2;
        if (items[mid] == target)
            found = true;
        else
        {
            if (target < items[mid])
                max = mid - 1;
            else
                min = mid + 1;
        }
    }

    // Return result
    return found;
}
