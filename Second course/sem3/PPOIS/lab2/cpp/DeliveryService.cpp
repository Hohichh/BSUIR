/**
 * @file DeliveryService.cpp
 * @brief File containing the implementation of the DeliveryService class.
 * @author Verkovich E.V.
 * @date November 26, 2023
 */
#include "DeliveryService.h"
 /**
  * @brief Default constructor of the DeliveryService class.
  *
  * The default constructor initializes a DeliveryService object with a default name.
  */
DeliveryService::DeliveryService() :name_("Noname") {};
/**
 * @brief Constructor of the DeliveryService class.
 *
 * The constructor initializes a DeliveryService object with a given name.
 *
 * @param name The delivery service's name.
 */
DeliveryService::DeliveryService(const string& name) :name_(name) {};

/**
 * @brief Get the delivery service's name.
 *
 * @return The delivery service's name.
 */
string DeliveryService::getName() const {
	return name_;
}
/**
 * @brief Set the delivery service's name.
 *
 * @param name The new name of the delivery service.
 */
void DeliveryService::setName(const string& name) {
	name_ = name;
}
/**
 * @brief Get the list of restaurants.
 *
 * @return The list of restaurants.
 */
vector<Restaurant*> DeliveryService::getRestaurants() {
	return restaurants;
}
/**
 * @brief Add a restaurant to the delivery service.
 *
 * Adds a restaurant to the list of restaurants of the delivery service.
 *
 * @param restaurant The restaurant to add.
 */
void DeliveryService::addRestaurant(Restaurant& restaurant) {
	restaurants.emplace_back(&restaurant);
}
/**
 * @brief Get the list of couriers.
 *
 * @return The list of couriers.
 */
vector<Employee*>& DeliveryService::getCouriers() {
	return couriers;
};
/**
 * @brief Add a courier to the delivery service.
 *
 * Adds a courier to the list of couriers of the delivery service.
 *
 * @param courier The courier to add.
 */
void DeliveryService::addAnEmployee(Courier& courier) {
	couriers.emplace_back(&courier);
}
/**
 * @brief Send an order to the restaurant.
 *
 * Sends an order to the restaurant and adds it to the courier's list of orders.
 *
 * @param index The index of the restaurant.
 * @param order The order to send.
 */
void DeliveryService::sentInRestaurant(size_t index, Order& order) {
	restaurants[index]->revieveAnOrder(order);
	
	for (int i = 0; i < couriers.size(); i++) {
		if (couriers[i]->getBusy() == 0) {
			couriers[i]->recieveAnOrder(order);
			break;
		}
	}

}







