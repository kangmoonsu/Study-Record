
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

void computeNet(Salary &);
void printSalary(Salary);

int main() {
    char fileName[20] = "payroll.txt";
    ifstream inputFile;
    inputFile.open(fileName);

    if (inputFile.fail()) {
        cout << "Error: Could not open the file!" << endl;
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

// void printSalary(Salary sal) {
//     cout << "Base, Bonus, Deduction, NetSalary: "
//          << setw(7) << fixed << setprecision(0) << sal.base << "  "
//          << setw(5) << sal.bonus << "  "
//          << setw(3) << setprecision(2) << sal.deduction << "  "
//          << setw(10) << sal.net_salary << endl;
// }

void printSalary(Salary sal){
    cout << "Base, Bonus, Deduction, NetSalary: ";
    cout.setf(ios::fixed); // fixed 형식 설정
    cout.precision(0);
    cout << setw(7) << sal.base << "  "
         << setw(5) << sal.bonus << "  ";

    cout.setf(ios::fixed); // fixed 형식 설정
    cout.precision(2);
    cout << setw(3) << sal.deduction << "  ";

    cout << setw(10) << sal.net_salary << endl;
    cout.unsetf(ios::fixed);
    
}