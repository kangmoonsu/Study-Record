#include <iostream>
using namespace std;

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