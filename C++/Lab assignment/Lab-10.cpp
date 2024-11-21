// array is static;
// On average, a linear search will look through half the numberof elements in the list before a match is found.

/*

5 5 multi array is static
int array[5][5];

[][여기는 선언 꼭 해야함]
먼저 0을 집어넣어서 initialze

값을 compute하라고?

use classes / design class
do not missaround with public and private

out of bound 면 바로 바로 no

1  2  3  4   5
2  4  6  8  10
3  6  9 12  15
4  8 12 16  20
5 10 15 20 25

int min[0][0]
int max[4][4]
*/

#include <iostream>

class Table{
    private:
        int arr[5][5];
        int max_value;
        int min_value;
};

using namespace std;

int main() {

    return 0;
}