#pragma once
#include <string>
#include "DishDB.h"

using namespace std;
class Dish {
private:
	string name_;
	double price_;

public:
	Dish();
	Dish(const string& name, const double& price);

	string getName() const;
	void setName(const string& name);
	double getPrice() const;
	void setPrice(const double& price);

	bool operator==(const Dish& dish) const;
};