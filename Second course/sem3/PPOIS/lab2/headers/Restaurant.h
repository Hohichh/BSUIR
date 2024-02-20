#pragma once

#include "Menu.h"
#include "Cook.h"
#include "Courier.h"


#define MROT 500

using namespace std;

class Restaurant {
private:
	string name_;
	float rating_;
	Menu menu_;
	double capital_;

	vector<Employee*> cooks;
	vector<Order>orders;

	bool checkOrderMatch(Employee* cook, Employee* courier);
public:
	Restaurant();
	Restaurant(string name, Menu menu, double capital, size_t rating);

	string getName() const;
	void setName(const string& name);

	float getRating() const;
	void setRating(const float& rating);

	Menu getMenu() const;
	void setMenu(const Menu& menu);

	double getCapital()const;
	void setCapital(const double& capital);

	vector<Employee*>& getCooks();

	void revieveAnOrder(const Order& Order);

	void addAnEmployee(Cook& cook);

	void orderDistribution();

	void dishTransfer(vector<Employee*>& couriers);

	void showInfo()const;
};