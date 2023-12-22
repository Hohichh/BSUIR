#pragma once
#include <iostream>
#include <string>
#include "Accessibility.h"

using namespace std;

class Entity;
class RealEstate abstract{
public:
	string name_;
	Accessibility access_;
	const Entity* owner_;
	const Entity* renter_;
	string address_;
	bool isStateProperty_;

public:
	RealEstate(const string& name, 
		const Accessibility& access, 
		const Entity* owner,
		const Entity* renter,
		const string& address, 
		bool isStateProperty);
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