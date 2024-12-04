// no public only private
// use swtich case
// more general
// use push_back
// output witdh format
// lenght of the txt list is not fixed, can change
// make constructor with all a
// setter getter // and contructer sperate


#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

class Food {
private:
    string name;
    string foodGroup;
    int calories;
    double dailyPercentage;

public:
    Food();
    Food(string, string, int, double);

    void setName(string);
    void setFoodGroup(string);
    void setCalories(int);
    void setDailyPercentage(double);

    string getName();
    string getFoodGroup();
    int getCalories();
    double getDailyPercentage();
};

void listFoods(vector<Food>);
void calorieFoods(vector<Food>);
void calorieList(vector<Food>);

int main() {
    vector<Food> foodList;

    ifstream file("foods.txt");
    if (!file) {
        cerr << "Error: Could not open the file!" << endl;
        return 1;
    }

    string name, foodGroup;
    int calories;
    double dailyPercentage;

    while (file >> name >> foodGroup >> calories >> dailyPercentage) {
        foodList.push_back(Food(name, foodGroup, calories, dailyPercentage));
    }
    file.close();

    int choice;
    bool run = true;

    while (run) {
        cout << endl;
        cout << "--------------" << endl;
        cout << "Food list menu" << endl;
        cout << "--------------" << endl;
        cout << "1) List food items" << endl;
        cout << "2) Compute total calories of all foods" << endl;
        cout << "3) List foods above an input calorie limit" << endl;
        cout << "4) Exit" << endl;
        cout << "Please enter a selection: ";
        cin >> choice;

        switch (choice) {
            case 1:
                listFoods(foodList);
                break;
            case 2:
                calorieFoods(foodList);
                break;
            case 3:
                calorieList(foodList);
                break;
            case 4:
                run = false;
                break;
        }
    }
    return 0;
}

Food::Food(){}

Food::Food(string n, string fg, int c, double dp) {
    name = n;
    foodGroup = fg;
    calories = c;
    dailyPercentage = dp;
}

void Food::setName(string n) {
    name = n;
}

void Food::setFoodGroup(string fg) {
    foodGroup = fg;
}

void Food::setCalories(int c) {
    calories = c;
}

void Food::setDailyPercentage(double dp) {
    dailyPercentage = dp;
}

string Food::getName() {
    return name;
}

string Food::getFoodGroup() {
    return foodGroup;
}

int Food::getCalories() {
    return calories;
}

double Food::getDailyPercentage() {
    return dailyPercentage;
}

void listFoods(vector<Food> list) {
    cout << "============================================================================" << endl;
    cout << setw(20) << left << "Name"
         << setw(15) << "Food Group"
         << setw(10) << "Calories"
         << "Daily Percentage" << endl;
    cout << "============================================================================" << endl;
    for (int i = 0; i < list.size(); ++i) {
        Food food = list[i];
        cout << setw(20) << left << food.getName()
             << setw(15) << food.getFoodGroup()
             << setw(10) << food.getCalories()
             << setw(10) << food.getDailyPercentage() << endl;
    }
}

void calorieFoods(vector<Food> list) {
    int totalCalories = 0;
    for (int i = 0; i < list.size(); ++i) {
        totalCalories += list[i].getCalories();
    }
    cout << "Total calories of all foods: " << totalCalories << endl;
}

void calorieList(vector<Food> list) {
    int calorieLimit;
    cout << "Enter calorie limit: ";
    cin >> calorieLimit;

    cout << "Foods above calorie limit: " << calorieLimit << endl;
    cout << "============================================================================" << endl;
    cout << setw(20) << left << "Name"
         << setw(15) << "Food Group"
         << setw(10) << "Calories"
         << "Daily Percentage" << endl;
    cout << "============================================================================" << endl;
    for (int i = 0; i < list.size(); ++i) {
        if (list[i].getCalories() > calorieLimit) {
            Food food = list[i];
            cout << setw(20) << left << food.getName()
                 << setw(15) << food.getFoodGroup()
                 << setw(10) << food.getCalories()
                 << food.getDailyPercentage() << endl;
        }
    }
}