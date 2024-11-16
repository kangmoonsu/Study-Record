#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


class Salary {
private:
    double base;       
    double bonus;      
    double deduction; 
    double net_salary; 

public:
    Salary();
    Salary(double b, double bon, double ded);

    void computeNet();      
    void printSalary(); 

    void setBase(double b);
    void setBonus(double bon);
    void setDeduction(double ded);
};


int main() {
    

    const int ARRAY_SIZE = 10;

    Salary sal[ARRAY_SIZE];

    char fileName[20] = "payroll.txt";
    ifstream inputFile;
    inputFile.open(fileName);

    if (inputFile.fail()) {
        cout << "Error: Could not open the file!" << endl;
        exit(1);
    }

    
    for (int i = 0; i < 10; i++) {       
        double base, bonus, deduction;

        inputFile >> base >> bonus >> deduction;

        sal[i].setBase(base);
        sal[i].setBonus(bonus);
        sal[i].setDeduction(deduction);

        sal[i].computeNet();
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        sal[i].printSalary();
    }

    inputFile.close();
    
    return 0;
}


Salary::Salary(){
    base = 0;
    bonus = 0;
    deduction = 0;
    net_salary = 0;
}

Salary::Salary(double b, double bon, double ded){
    base = b;
    bonus = bon;
    deduction = ded;
    net_salary = 0;
}
    
void Salary::computeNet() {
    double total_deduction = (base + bonus) * deduction;
    net_salary = (base + bonus) - total_deduction;
}

void Salary::printSalary() {
    cout << "Base, Bonus, Deduction, Net Salary: ";
    cout.setf(ios::fixed);

    cout.precision(0);
    cout << setw(7) << base << "  " << setw(5) << bonus << "  ";

    cout.precision(2);
    cout << setw(3) << deduction << "  " << setw(10) << net_salary << endl;

    cout.unsetf(ios::fixed);
}

void Salary::setBase(double b) {
    base = b;
}

void Salary::setBonus(double bon) {
    bonus = bon;
}

void Salary::setDeduction(double ded) {
    deduction = ded;
}
