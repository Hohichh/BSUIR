#pragma once

#include <iostream>
#include <string>
#include "Dish.h"
#include "Order.h"


using namespace std;
class DeliveryService;
class Restaurant;
class Client {
private:
	string name_;
	string address_;
	string number_;
	vector<Dish>dishes;

	//Restaurant* ChooseRestaurant(DeliveryService& delServ, size_t i);
public:
	Client();
	Client(const string& name, const string& address, const string& number);

	string getName() const;
	void setName(const string& name);

	string getAddress() const;
	void setAddress(const string& address);

	string getNumber() const;
	void setNumber(const string& number);

	void takeDish(const Dish& dish);

	void placeAnOrder(DeliveryService& delServ, bool manual);
}; 