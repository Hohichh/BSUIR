#pragma once
#include "Dish.h"
#include <iostream>
#include <vector>
using namespace std;

class Menu {
private:
	vector<pair<size_t, Dish>> dishes;
	bool isSameInMenu(const Dish& dish);

public:
	Menu();
	Menu(const size_t& size);

	Dish getDish(size_t i) const;

	void addDish(const Dish& dish);
	void addDish(const string& name, const double& price);
	void delDish(const Dish& dish);
	void delDish(const string& name);
	void delDish(const size_t& number);

	void show();
};