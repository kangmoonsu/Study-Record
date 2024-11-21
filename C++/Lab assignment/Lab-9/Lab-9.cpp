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
    Salary(double b, double bon, double ded, double net);

    void computeNet();      
    void printSalary(); 

    void setBase(double b);
    double getBase();
    void setBonus(double bon);
    double getBonus();
    void setDeduction(double ded);
    double getDeduction();
    void setNetSalary(double net);
    double getNetSalary();
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
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
        double base, bonus, deduction;

        inputFile >> base >> bonus >> deduction;

        sal[i].setBase(base);
        sal[i].setBonus(bonus);
        sal[i].setDeduction(deduction);        
    }

    inputFile.close();

    for(int i = 0; i < ARRAY_SIZE; i++){
        sal[i].computeNet();
        sal[i].printSalary();
    }

    return 0;
}

Salary::Salary(){};

Salary::Salary(double b, double bon, double ded, double net){
    base = b;
    bonus = bon;
    deduction = ded;
    net_salary = net;
};    

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

double Salary::getBase(){
    return base;
}

void Salary::setBonus(double bon) {
    bonus = bon;
}

double Salary::getBonus(){
    return bonus;
}

void Salary::setDeduction(double ded) {
    deduction = ded;
}

double Salary::getDeduction(){
    return deduction;
}

void Salary::setNetSalary(double net){
    net_salary = net;
}

double Salary::getNetSalary(){
    return net_salary;
}