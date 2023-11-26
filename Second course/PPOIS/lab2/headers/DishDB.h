#pragma once

#include <string>
#include<vector>

class DishDataBase {
public:
    DishDataBase();
    std::string getRandomDish();

private:
    std::vector<std::string> dishNames;
    size_t randomDishIndex;
    std::string randomDish;
};

