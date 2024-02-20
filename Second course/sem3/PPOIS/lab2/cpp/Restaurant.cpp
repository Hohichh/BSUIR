/**
 * @file Restaurant.cpp
 * @brief File containing the implementation of the Restaurant class.
 * @author Your Name
 * @date November 26, 2023
 */
#include "Restaurant.h"
 /**
 * @brief Check if the orders match between the cook and the courier.
 *
 * Checks if the orders match between the cook and the courier.
 *
 * @param cook The cook.
 * @param courier The courier.
 * @return Returns true if the orders match, otherwise false.
 */
	bool Restaurant::checkOrderMatch(Employee* cook, Employee* courier) {
		if (!cook->getBusy() && !courier->getBusy())
			return cook->getOrders() == courier->getOrders();
	}
	/**
	 * @brief Default constructor of the Restaurant class.
	 *
	 * The default constructor initializes a Restaurant object with a default name, menu, capital, and rating.
	 */
	Restaurant::Restaurant() : name_(""), rating_(0), capital_(10000) {};
	/**
	 * @brief Constructor of the Restaurant class.
	 *
	 * The constructor initializes a Restaurant object with a given name, menu, capital, and rating.
	 *
	 * @param name The restaurant's name.
	 * @param menu The restaurant's menu.
	 * @param capital The restaurant's capital.
	 * @param rating The restaurant's rating.
	 */
	Restaurant::Restaurant(string name, Menu menu, double capital, size_t rating = 0) {
		cout << "Restaurant \"" << name << "\" has started!";
		name_ = name;
		rating_ = rating;
		menu_ = menu;
		capital_ = capital;
	}
	/**
 * @brief Get the restaurant's name.
 *
 * @return The restaurant's name.
 */
	string Restaurant::getName() const {
		return name_;
	}

	/**
	 * @brief Set the restaurant's name.
	 *
	 * @param name The new name of the restaurant.
	 */
	void Restaurant::setName(const string& name) {
		name_ = name;
	}
	/**
	 * @brief Get the restaurant's rating.
	 *
	 * @return The restaurant's rating.
	 */
	float Restaurant::getRating() const {
		return rating_;
	}
	/**
	 * @brief Set the restaurant's rating.
	 *
	 * @param rating The new rating of the restaurant.
	 */
	void Restaurant::setRating(const float& rating) {
		rating_ = rating;
	}
	/**
	 * @brief Get the restaurant's menu.
	 *
	 * @return The restaurant's menu.
	 */
	Menu Restaurant::getMenu() const {
		return menu_;
	}
	/**
	 * @brief Set the restaurant's menu.
	 *
	 * @param menu The new menu of the restaurant.
	 */
	void Restaurant::setMenu(const Menu& menu) {
		menu_ = menu;
	}
	/**
	 * @brief Get the restaurant's capital.
	 *
	 * @return The restaurant's capital.
	 */
	double Restaurant::getCapital()const {
		return capital_;
	}

	/**
	 * @brief Set the restaurant's capital.
	 *
	 * @param capital The new capital of the restaurant.
	 */
	void Restaurant::setCapital(const double& capital) {
		capital_ = capital;
	}
	/**
	 * @brief Get the list of cooks.
	 *
	 * @return The list of cooks.
	 */
	vector<Employee*>& Restaurant::getCooks() {
		return cooks;
	}
	/**
 * @brief Receive an order.
 *
 * Adds an order to the list of orders.
 *
 * @param order The order to receive.
 */
	void Restaurant::revieveAnOrder(const Order& order) {
		orders.emplace_back(order);
	}
	/**
 * @brief Distribute orders.
 *
 * Distributes orders among cooks.
 */
	void Restaurant::orderDistribution() {
		for (int i = 0; i < orders.size(); i++) {
			for (int j = 0; j < cooks.size(); j++) {
				if (!cooks[j]->getBusy()) {
					cooks[j]->recieveAnOrder(orders[i]);
				}
			}
		}
	}
	/**
 * @brief Transfer dishes to couriers.
 *
 * Transfers prepared dishes to couriers.
 *
 * @param couriers The couriers.
 */
	void Restaurant::dishTransfer(vector<Employee*>& couriers) {

		for (int i = 0; i < cooks.size(); i++) {
			for (int j = 0; j < couriers.size(); j++) {
				if (checkOrderMatch(cooks[i], couriers[j])) {
					dynamic_cast<Courier*>(couriers[j])->putInDishes(dynamic_cast<Cook*>(cooks[i])->passOnDishes());
				}
			}
			cooks[i]->getOrders().clear();
		}
	}
	/**
	 * @brief Show restaurant information.
	 *
	 * Outputs information about the restaurant.
	 */

	void Restaurant::showInfo() const {
		cout << "\n" << getName() << "\n";
		cout << "-------------\n";
		cout <<"Rating: " << getRating() << "\n";
	}
	/**
	 * @brief Add an employee to the restaurant.
	 *
	 * Adds cooks to the restaurant.
	 *
	 * @param cook The cook.
	 */
	void Restaurant::addAnEmployee(Cook& cook){
		cooks.emplace_back(&cook);
	}