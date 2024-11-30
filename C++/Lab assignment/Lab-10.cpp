/*

5 5 multi array is static
int array[5][5];


use classes / design class
do not missaround with public and private

if:out of bound -> no

int min[0][0]
int max[4][4]
*/

#include <iostream>
using namespace std;

const int ROWS = 5;
const int COLS = 5;

class MultiplicationTable {
private:
    int table[ROWS][COLS];
    int minValue;
    int maxValue;

public:
    MultiplicationTable();
    void fillTable();
    void setMinMax();
    void printTable();
    void setValueAt(int row, int col, int value);
    int getValueAt(int row, int col);
};

void findMatch(MultiplicationTable mt, int valueToFind);

int main() {
    MultiplicationTable mt;
    mt.printTable();

    int valueToFind;
    cout << "Enter a value in the multiplication table: ";
    cin >> valueToFind;

    findMatch(mt, valueToFind);

    return 0;
}

MultiplicationTable::MultiplicationTable() {
    fillTable();
    setMinMax();
}

void MultiplicationTable::fillTable() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            table[i][j] = (i + 1) * (j + 1);
        }
    }
}

void MultiplicationTable::setMinMax() {
    minValue = table[0][0];
    maxValue = table[ROWS - 1][COLS - 1];
}

void MultiplicationTable::printTable() {
    cout << "Multiplication Table: " << endl;
    cout << "  minimum value: " << minValue << endl;
    cout << "  maximum value: " << maxValue << "\n\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << table[i][j] << "\t";
        }
        cout << endl;
    }
}

void MultiplicationTable::setValueAt(int row, int col, int value) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        table[row][col] = value;
    } else {
        cout << "Index out of bounds." << endl;
    }
}

int MultiplicationTable::getValueAt(int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        return table[row][col];
    } else {
        cout << "Index out of bounds." << endl;
        return -1;
    }
}


void findMatch(MultiplicationTable mt, int valueToFind) {
    bool found = false;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (mt.getValueAt(i, j) == valueToFind) {
                cout << valueToFind << " found in table at row, col: " << i << ", " << j << endl;
                found = true;
            }
        }
    }
    if (!found) {
        cout << valueToFind << " not found in table" << endl;
    }
}