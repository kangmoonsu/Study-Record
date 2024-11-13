
#include <iostream>
#include <fstream>
#include <iomanip>

/*
    use class 
    private 에 변수 넣고
    public 안에 함수 넣고

    write definition after the class

    assume loop 10 times

    make a salary array


*/

using namespace std;

struct Salary {
    double base;
    double bonus;
    double deduction;
    double net_salary;
};

void computeNet(Salary &);
void printSalary(Salary);

int main() {
    
}

void computeNet(Salary &sal) {
    double deduction = (sal.base + sal.bonus) * sal.deduction;
    sal.net_salary = (sal.base + sal.bonus) - deduction;
}


void printSalary(Salary sal){
    cout << "Base, Bonus, Deduction, NetSalary: ";
    cout.setf(ios::fixed);

    cout.precision(0);
    cout << setw(7) << sal.base << "  " << setw(5) << sal.bonus << "  ";

    cout.precision(2);
    cout << setw(3) << sal.deduction << "  " << setw(10) << sal.net_salary << endl;
    
    cout.unsetf(ios::fixed);
}