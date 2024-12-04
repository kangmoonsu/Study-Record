while (file >> name >> foodGroup >> calories >> dailyPercentage) {
        foodList.push_back(Food(name, foodGroup, calories, dailyPercentage));
    }