#pragma once

#include "Employee.h"
#include "Order.h"
#include "Client.h"
#include <memory>

#define MROT 500

using namespace std;

class Courier : public Employee {
private:
	const size_t maxOrderQuantity_ = 10;
	const size_t bagSize_ = 10;
	vector<Dish>bag;


	bool findDish(const Dish& dish) const;
	Dish takeOut(const Dish& dish);

public:
	Courier();
	Courier(const string& name, const double& salary, const string& position);
	
	void recieveAnOrder(Order& order) override;

	void putInDishes(const vector<Dish>& preparedDishes);

	void toWork() override;
};