
/**
 * @file Cook.cpp
 * @brief File containing the implementation of the Cook class.
 * @author Verkovich E.V.
 * @date November 26, 2023
 */
#include "Cook.h"
 /**
  * @brief Constructor of the Cook class.
  *
  * The default constructor initializes a Cook object with a given name, position, and salary.
  */
Cook::Cook() : Employee("Noname", "Cook", MROT) {}
/**
 * @brief Constructor of the Cook class.
 *
 * The constructor initializes a Cook object with a given name, position, and salary.
 *
 * @param name The cook's name.
 * @param salary The cook's salary.
 * @param position The cook's position.
 */
Cook::Cook(const string& name, const double& salary, const string& position = "Cook")
	: Employee(name, position, salary) {
	cout << "\nHi! I am a cook " << name << "!\n";
}
/**
 * @brief Receive an order for preparation.
 *
 * If the number of orders is less than the maximum, then the order is added to the list of orders.
 * Otherwise, a message is displayed that the cook has received the maximum number of orders.
 *
 * @param order The order to prepare.
 */
void Cook::recieveAnOrder(Order& order) {
	if (orders.size() < maxOrderQuantity_) {
		orders.emplace_back(order);
	}
	else {
		cout << "Cook have recieved maximum quantity of orders!\n";
		setBusy(1);
		return;
	}
}
/**
 * @brief Start working on orders.
 *
 * The cook starts preparing dishes for each order in the list of orders.
 * After completing the preparation of each order, the order status is set to "ready",
 * and a message is displayed about the order readiness.
 * After completing work on all orders, the cook's busy status is set to "not busy".
 */
void Cook::toWork() {

	for (int i = 0; i < orders.size(); i++) {
		for (int j = 0; j < orders[i].getDishes().size(); j++) {
			preparedDishes.emplace_back(orders[i].getDishes().at(j));
		}
		orders[i].setStatus(1);
		cout << "Order number " << orders[i].getNumber() << " is ready\n";
	}
	setBusy(0);
}
/**
 * @brief Pass on prepared dishes.
 *
 * Returns a vector containing all prepared dishes.
 *
 * @return A vector containing all prepared dishes.
 */
vector <Dish> Cook::passOnDishes() {
	return preparedDishes;
}