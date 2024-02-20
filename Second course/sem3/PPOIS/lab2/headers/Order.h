#pragma once

#include <iostream>
#include <memory>
#include <algorithm>
#include "Dish.h"

using namespace std;

class Client;
class Order {
private:
	static size_t currentNumber_;
	size_t number_;
	bool status_;    //0 -- оформлен(дефолт), 1 -- готов, 2 -- в пути, 3 -- доставлен
	vector <Dish> dishes;
	Client*client_;

public:
	Order(Client& client);
	bool getStatus() const;
	void setStatus(bool status);

	size_t getNumber() const;

	Client* getClient() const;

	vector<Dish> getDishes();

	void addDish(const Dish& dish);
	void delDish(const Dish& dish);

	bool operator==(const Order& other)const;
};
