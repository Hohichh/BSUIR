#pragma once

#include <vector>
#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#include <memory>
#include "Employee.h"

#define MROT 500

using namespace std;

class Cook : public Employee {
private:
	const size_t maxOrderQuantity_ = 10;
	vector<Dish>preparedDishes;

public:
	Cook();
	Cook(const string& name, const double& salary, const string& position);

	void recieveAnOrder(Order& order) override;
	void toWork() override;

	vector <Dish> passOnDishes();
};