#include <iostream>
using namespace std;

int main() {
    int num;

    cout << "Please enter a whole number between 0 and 9: ";
    cin >> num;
    cout << "    +" << endl;
    cout << "   ***" << endl;
    cout << "  #####" << endl;
    cout << " *******" << endl;
    cout << num << num << num << num << num << num << num << num << num << endl;
    cout << " *******" << endl;
    cout << "  #####" << endl;
    cout << "   ***" << endl;
    cout << "    +" << endl;
    return 0;
}


/*
    +   
   ***  
  ##### 
 *******
777777777
 *******
  ##### 
   ***  
    +   */