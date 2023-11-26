
/**
 * @file DishDataBase.cpp
 * @brief File containing the implementation of the DishDataBase class.
 * @author Verkovich.E.V.
 * @date November 26, 2023
 */

#include "DishDB.h"
#include <random>
#include <ctime>
 /**
  * @brief Constructor of the DishDataBase class.
  *
  * The constructor initializes the vector dishNames with dish names and selects a random dish.
  */
DishDataBase::DishDataBase() {
      dishNames = {
        "Borsch",
        "Meat dumplings",
        "Ceasar salad",
        "Pizza",
        "Sushi",
        "Steak",
        "Pasta",
        "Harcho soup",
        "French fries",
        "Pirozshok"
    };
    
      randomDishIndex = rand() % dishNames.size();
      randomDish = dishNames[randomDishIndex];
};
/**
 * @brief Get a random dish.
 *
 * @return A string containing the name of the random dish.
 */
std::string DishDataBase::getRandomDish() {
    return randomDish;
}
