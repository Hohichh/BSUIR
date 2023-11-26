/**
 * @file Dish.cpp
 * @brief File containing the implementation of the Dish class.
 * @author Verkovich.E.V.
 * @date November 26, 2023
 */
#include "Dish.h"
 /**
  * @brief Constructor of the Dish class.
  *
  * The constructor initializes a DishDataBase object and gets a random dish from the database.
  * It also sets the dish price to 10.
  */
Dish::Dish() {
	DishDataBase dishdb_;
	name_ = dishdb_.getRandomDish();
	price_ = 10;
}
/**
 * @brief Constructor of the Dish class.
 *
 * The constructor initializes a Dish object with a given name and price.
 *
 * @param name Name of the dish.
 * @param price Price of the dish.
 */
Dish::Dish(const string& name, const double& price) : name_(name), price_(price) {}
/**
 * @brief Get the name of the dish.
 *
 * @return A string containing the name of the dish.
 */
string Dish::getName() const {
	return name_;
}
/**
 * @brief Set the name of the dish.
 *
 * @param name Name of the dish.
 */
void Dish::setName(const string& name) {
	name_ = name;
}
/**
 * @brief Get the price of the dish.
 *
 * @return Price of the dish.
 */
double Dish::getPrice() const {
	return price_;
}
/**
 * @brief Set the price of the dish.
 *
 * @param price Price of the dish.
 */
void Dish::setPrice(const double& price) {
	price_ = price;
}
/**
 * @brief Comparison operator for two Dish objects.
 *
 * The operator compares the names of the dishes of two Dish objects.
 *
 * @param dish Dish object to compare.
 * @return Returns true if the dish names match, otherwise returns false.
 */
bool Dish::operator==(const Dish& dish) const {
	return name_ == dish.name_;
}