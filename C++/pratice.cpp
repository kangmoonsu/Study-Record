#include <iostream>

using namespace std;

int main()
{
    
    for (int i = 2; i <= 9; i++) 
    {
        cout << i << "times" << endl;
        for (int j = 1; j <= 9; j++) 
        {
            cout << i << " * " << j << " = " << i * j << endl;
        }
        cout << endl;
    }

    return 0;
}