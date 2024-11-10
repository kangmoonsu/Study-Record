
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Salary {
    double base;
    double bonus;
    double deduction;
    double net_salary;
};
void computeNet(Salary &sal);
void printSalary(Salary sal);

int main() {
    ifstream inputFile("payroll.txt");
    if (!inputFile) {
        cerr << "Error: Could not open the file!" << endl;
        exit(1);
    }

    
    for (int i = 0; i < 10; i++) {
		Salary sal;
        inputFile >> sal.base >> sal.bonus >> sal.deduction;
        computeNet(sal);
        printSalary(sal);
    }

    inputFile.close();
    return 0;
}
void computeNet(Salary &sal) {
    double deduction = (sal.base + sal.bonus) * sal.deduction;
    sal.net_salary = (sal.base + sal.bonus) - deduction;
}

void printSalary(Salary sal) {
    cout << "Base, Bonus, Deduction, NetSalary: "
         << setw(10) << fixed << setprecision(0) << sal.base << "  "
         << setw(6) << sal.bonus << "  "
         << setw(5) << setprecision(2) << sal.deduction << "  "
         << setw(10) << sal.net_salary << endl;
}