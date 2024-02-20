#pragma once

#include "Order.h"

using namespace std;

class Employee abstract {
protected:
	string name_;
	string position_;
	double salary_;
	bool busy_; //0 -- не занят, 1 -- занят
	vector<Order>orders;
public:
	Employee(const string& name, const string& position, const double& salary);

	string getName() const;
	void setName(const string& name);

	string getPosition() const;
	void setPosition(const string& position);

	double getSalary() const;
	void setSalary(const double& salary);

	bool getBusy()const;
	void setBusy(const int& busy);

	vector<Order>& getOrders();

	virtual void recieveAnOrder(Order& order) = 0;
	virtual void toWork() = 0;
};