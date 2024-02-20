/**
 * @file Courier.cpp
 * @brief File containing the implementation of the Courier class.
 * @author Verkovich E.V.
 * @date November 26, 2023
 */
#include "Courier.h"
#include "DeliveryService.h"

 /**
 * @brief Find a dish in the courier's bag.
 *
 * Checks if a dish is in the courier's bag.
 *
 * @param dish The dish to find.
 * @return Returns true if the dish is found, otherwise false.
 */
bool Courier::findDish(const Dish& dish) const {
	bool find = 0;
	for (int i = 0; i < bag.size(); i++) {
		if (bag[i] == dish) find = 1;
	}
	return find;
}
/**
 * @brief Take out a dish from the courier's bag.
 *
 * Takes out a dish from the courier's bag and removes it from the bag.
 *
 * @param dish The dish to take out.
 * @return Returns the dish if it is found and taken out, otherwise returns the original dish.
 */
Dish Courier::takeOut(const Dish& dish) {
	for (int i = 0; i < bag.size(); i++) {
		if (bag[i] == dish) {
			Dish takenDish = bag[i];
			bag.erase(bag.begin() + i);
			return takenDish;
		}
	}
	return dish;
}
/**
 * @brief Constructor of the Courier class.
 *
 * The default constructor initializes a Courier object with a given name, position, and salary.
 */
Courier::Courier() : Employee("Noname", "Courier", MROT) {}

/**
 * @brief Constructor of the Courier class.
 *
 * The constructor initializes a Courier object with a given name, position, and salary.
 *
 * @param name The courier's name.
 * @param salary The courier's salary.
 * @param position The courier's position.
 */
Courier::Courier(const string& name, const double& salary, const string& position = "Courier")
		: Employee(name, position, salary) {
		cout << "\nHi! I am a courier " << name << "!\n";
}


/**
 * @brief Receive an order for delivery.
 *
 * If the number of orders is less than the maximum and the number of dishes in the order does not exceed the remaining space in the bag,
 * then the order is added to the list of orders.
 * Otherwise, a message is displayed that the courier's bag is full or the courier has received the maximum number of orders.
 *
 * @param order The order to deliver.
 */
void Courier::recieveAnOrder(Order& order) {
	if (orders.size() < maxOrderQuantity_) {
		if (order.getDishes().size() <= (bagSize_ - bag.size())) {//проверяем, что количество блюд в заказе <= чем оставшегося места в сумке
			order.setStatus(2);
			orders.emplace_back(order);
		}
		else {
			cout << "Courier's bag is full! There is no space for dishes from current order\n";
			setBusy(1);
			return;
		}
	}
	else {
		cout << "Courier have recieved maximum quantity of orders!\n";
		setBusy(1);
		return;
	}
}
/**
 * @brief Put dishes in the courier's bag.
 *
 * Adds dishes to the courier's bag.
 *
 * @param preparedDishes The dishes to add to the bag.
 */
void Courier::putInDishes(const vector<Dish>& preparedDishes) {
	for (int i = 0; i < preparedDishes.size(); i++) {
		bag.emplace_back(preparedDishes[i]);
	}
}
/**
 * @brief Start working on delivering orders.
 *
 * The courier starts delivering dishes for each order in the list of orders.
 * After delivering each dish, the order status is set to "delivered",
 * and a message is displayed about the order delivery.
 * After delivering all dishes for all orders, the courier's busy status is set to "not busy".
 */
void Courier::toWork() {
	cout << "Courier's on the way\n";
	for (int i = 0; i < orders.size(); i++) {
		for (int j = 0; j < orders[i].getDishes().size(); j++) {
			if (findDish(orders[i].getDishes().at(j))) {
				orders[i].getClient()->takeDish(takeOut(orders[i].getDishes().at(j)));
			}
		}
		orders[i].setStatus(3);
		cout << "Courier has delivered order number " << orders[i].getNumber()
			<< " to the " << orders[i].getClient()->getAddress() << "\n";
	}
	orders.clear();
	setBusy(0);
}