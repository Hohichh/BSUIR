#pragma once

#include "Restaurant.h"

#define MROT 500

using namespace std;


class DeliveryService {
private:
	string name_;
	vector<Restaurant*> restaurants;
	vector<Employee*> couriers;

public:
	DeliveryService();
	DeliveryService(const string& name);

	string getName() const;
	void setName(const string& name);

	vector<Restaurant*> getRestaurants();
	void addRestaurant(Restaurant& restaurant);

	void addAnEmployee(Courier& courier);
	vector<Employee*>& getCouriers();

	void sentInRestaurant(size_t index, Order& order);
};