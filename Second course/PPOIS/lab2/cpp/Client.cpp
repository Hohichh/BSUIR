/**
 * @file Client.cpp
 * @brief File containing the implementation of the Client class.
 * @author Verkovich E.V.
 * @date November 26, 2023
 */

#include "Client.h"
#include "DeliveryService.h"

 /**
  * @brief Default constructor of the Client class.
  *
  * The default constructor initializes a Client object with a default name, address, and phone number.
  */
Client::Client() :name_("Noname"), address_("Somewhere st. 000"), number_("+000000000000") {}
/**
 * @brief Constructor of the Client class.
 *
 * The constructor initializes a Client object with a given name, address, and phone number.
 *
 * @param name The client's name.
 * @param address The client's address.
 * @param number The client's phone number.
 */
Client::Client(const string& name, const string& address, const string& number) {
	name_ = name;
	address_ = address;
	number_ = number;
}
/**
 * @brief Get the client's name.
 *
 * @return The client's name.
 */
string Client::getName() const {
	return name_;
}
/**
 * @brief Set the client's name.
 *
 * @param name The new name of the client.
 */
void Client::setName(const string& name) {
	name_ = name;
}
/**
 * @brief Get the client's address.
 *
 * @return The client's address.
 */
string Client::getAddress() const {
	return address_;
}
/**
 * @brief Set the client's address.
 *
 * @param address The new address of the client.
 */
void Client::setAddress(const string& address) {
	address_ = address;
}
/**
 * @brief Get the client's phone number.
 *
 * @return The client's phone number.
 */
string Client::getNumber() const {
	return number_;
}
/**
 * @brief Set the client's phone number.
 *
 * @param number The new phone number of the client.
 */
void Client::setNumber(const string& number) {
	number_ = number;
}
/**
 * @brief Take a dish.
 *
 * Adds a dish to the client's dishes.
 *
 * @param dish The dish to take.
 */
void Client::takeDish(const Dish& dish) {
	dishes.emplace_back(dish);
}
/**
 * @brief Place an order.
 *
 * Places an order with a delivery service.
 * If the order is manual, the client is asked to choose a restaurant and dishes.
 * If the order is not manual, a dish is chosen from the first restaurant's menu.
 *
 * @param delServ The delivery service.
 * @param manual Whether the order is manual.
 */
void Client::placeAnOrder(DeliveryService& delServ, bool manual) {
	Order order(*this);
	if (manual) {
		cout << "\nChoose a restaurant: \n";
		for (int i = 0; i < delServ.getRestaurants().size(); i++) {
			cout << i+1 << ". ";
			delServ.getRestaurants().at(i)->showInfo();
			cout << "\n";
		}

		size_t choiseRstrn;
		cout << "Input number of restaurant: ";
		cin >> choiseRstrn;
		delServ.getRestaurants().at(choiseRstrn-1)->getMenu().show();

		char choise = 'y';
		cout << "Choose a dish from menu.\n";
		while (choise == 'y' || choise == 'Y') {
			cout << "Input number: \n";
			size_t choiseDish;
			cin >> choiseDish;
			order.addDish(delServ.getRestaurants().at(choiseRstrn-1)->getMenu().getDish(choiseDish));
			cout << "\nAdd more? (y/n)" << endl;
			cin >> choise;
		}
		delServ.sentInRestaurant(choiseRstrn-1, order);
	}
	else {
		order.addDish(delServ.getRestaurants().at(0)->getMenu().getDish(1));
		delServ.sentInRestaurant(0, order);
	}
	
}