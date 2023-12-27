#pragma once
#include <iostream>
#include <string>
#include "Accessibility.h"

using namespace std;



class Entity;

struct BaseConditions {
	string name;
	Accessibility access;
	const Entity* owner;
	const Entity* renter;
	string address;
	bool isStateProperty;
};

class RealEstate abstract{
private:
	string name_;
	Accessibility access_;
	const Entity* owner_;
	const Entity* renter_;
	string address_;
	bool isStateProperty_;

public:
	RealEstate(const BaseConditions& baseConditions);
	RealEstate();

	string getName() const;
	void setName(const string& name);

	Accessibility getAccess() const;
	void setAccess(const Accessibility& access);

	const Entity* getOwner() const;
	void setOwner(const Entity* owner);

	const Entity* getRenter() const;
	void  setRenter(const Entity* renter);

	string getAddress() const;
	void setAddress(const string& address);

	bool getIsStateProperty() const;
	void setIsStateProperty(bool IsStateProperty);

	void showInfo() const;

};