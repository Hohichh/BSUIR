/**
 * @file Order.cpp
 * @brief File containing the implementation of the Order class.
 * @author Verkovich E.V.
 * @date November 26, 2023
 */
#include "Order.h"
#include "Client.h"
 /**
 * @brief Constructor of the Order class.
 *
 * The constructor initializes an Order object with a given client.
 *
 * @param client The client for whom the order is created.
 */
Order::Order(Client& client) : status_(0), number_(currentNumber_++), client_(&client) {}

/**
 * @brief Get the status of the order.
 *
 * @return Order status.
 */
bool Order::getStatus() const {
	return status_;
}

/**
 * @brief Set the status of the order.
 *
 * @param status New order status.
 */
void Order::setStatus(bool status) {
	status_ = status;
}
/**
 * @brief Get the order number.
 *
 * @return Order number.
 */
size_t Order::getNumber() const {
	return number_;
}
/**
 * @brief Get the client for whom the order was created.
 *
 * @return The client for whom the order was created.
 */
Client* Order::getClient() const {
	return client_;
}
/**
 * @brief Get all dishes in the order.
 *
 * @return A vector containing all the dishes in the order.
 */
vector<Dish> Order::getDishes() {
	return dishes;
}
/**
 * @brief Add a dish to the order.
 *
 * @param dish The dish to add to the order.
 */
void Order::addDish(const Dish& dish) {
	dishes.emplace_back(dish);
}
/**
 * @brief Remove a dish from the order.
 *
 * @param dish The dish to remove from the order.
 */
void Order::delDish(const Dish& dish) {
	dishes.erase(remove_if(dishes.begin(), dishes.end(), [&](const Dish& currentDish) {
		return currentDish == dish;
		}), dishes.end());
}
/**
 * @brief Comparison operator for two Order objects.
 *
 * The operator compares the numbers of two Order objects.
 *
 * @param other Order object to compare.
 * @return Returns true if the numbers match, otherwise returns false.
 */
bool Order::operator==(const Order& other) const {
	return (number_ == other.number_);
}

/**
 * @brief Current order number.
 */
size_t Order::currentNumber_ = 1;