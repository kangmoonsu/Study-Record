#include <iostream>
using namespace std;

/*
Write an application that prompts the user for a positive integer value and determines whether it is an even or odd number
(consider zero an even number for this application). Continue prompting until the user quits by entering a negative integer value. 
Print the number of even and odd integers entered after the user quits as shown below in a sample session.
*/
int main() {

    int num;
    int even = 0; 
    int odd = 0;  

    cout << "Enter a positive integer (or negative integer to quit): ";
    cin >> num;

    while(num >= 0){ 
        if(num % 2 == 0){
            even++;
        } else {
            odd++;
        }
        
        cout << "Enter a positive integer (or negative integer to quit): ";
        cin >> num; 
    }

    cout << "Number of even numbers entered: " << even << endl;
    cout << "Number of odd numbers entered: " << odd << endl;
    
    return 0;
}