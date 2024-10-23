#include <iostream>
using namespace std;

int lee(int x){
    int last = 10;
    while(x) {
        if (x % 10 > last)
        {
            return 0;           
        }
        last = x % 10;
        x /= 10;
    }
    return 1;
}

int main() {
    cout << lee(654321) + lee(123345) + lee(442211) + lee(202104);
}