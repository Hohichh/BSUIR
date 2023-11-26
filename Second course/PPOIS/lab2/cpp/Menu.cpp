/**
 * @file Menu.cpp
 * @brief File containing the implementation of the Menu class.
 * @author Verkovic E.V.
 * @date November 26, 2023
 */
#include "Menu.h"
#include <iostream>
#include <vector>
 /**
  * @brief Check if a dish is in the menu.
  *
  * @param dish The dish to check.
  * @return Returns true if the dish is in the menu, otherwise returns false.
  */
bool Menu::isSameInMenu(const Dish& dish) {
	for (const auto& pair : dishes) {
		if (pair.second == dish) {
			return true;
		}
	}
	return false;
}
/**
 * @brief Constructor of the Menu class.
 *
 * Default constructor.
 */
Menu::Menu() = default;
/**
 * @brief Constructor of the Menu class.
 *
 * The constructor initializes a menu of a given size.
 *
 * @param size Size of the menu.
 */
Menu::Menu(const size_t& size) {
	for (int i = 1; i <= size; i++) {
		Dish dish;
		if (!isSameInMenu(dish)) {
			dishes.emplace_back(i, dish);
		}
	}
}
/**
 * @brief Get a dish by index.
 *
 * @param i Index of the dish.
 * @return The dish at the given index.
 */
Dish Menu::getDish(size_t i) const {
	return dishes.at(i-1).second;
}
/**
 * @brief Add a dish to the menu.
 *
 * @param dish The dish to add.
 */
void Menu::addDish(const Dish& dish) {
	dishes.emplace_back(dishes.size() + 1, dish);
}
/**
 * @brief Add a dish to the menu.
 *
 * @param name Name of the dish.
 * @param price Price of the dish.
 */
void Menu::addDish(const string& name, const double& price = 10) {
	Dish dish;
	dish.setName(name);
	dish.setPrice(price);
	dishes.emplace_back(dishes.size() + 1, dish);
}
/**
 * @brief Remove a dish from the menu.
 *
 * @param dish The dish to remove.
 */
void Menu::delDish(const Dish& dish) {
	dishes.erase(remove_if(dishes.begin(), dishes.end(),
		[dish](const pair<size_t, Dish>& position) {
			return position.second == dish; }),
		dishes.end());
}
/**
 * @brief Remove a dish from the menu.
 *
 * @param name Name of the dish to remove.
 */
void Menu::delDish(const string& name) {
	dishes.erase(remove_if(dishes.begin(), dishes.end(),
		[name](const pair<size_t, Dish>& position) {
			return position.second.getName() == name; }),
		dishes.end());
}
/**
 * @brief Remove a dish from the menu.
 *
 * @param number Number of the dish to remove.
 */
void Menu::delDish(const size_t& number) {
	dishes.erase(remove_if(dishes.begin(), dishes.end(),
		[number](const pair<size_t, Dish>& position) {
			return position.first == number; }),
		dishes.end());
}
/**
 * @brief Display the menu.
 *
 * Displays all the dishes in the menu.
 */
void Menu::show() {
	cout << "\n_______Menu_______\n";
	for (int i = 0; i < dishes.size(); i++) {
		cout << dishes[i].first << ". " << dishes[i].second.getName()
			<< "   " << dishes[i].second.getPrice() << "\n";
	}
}