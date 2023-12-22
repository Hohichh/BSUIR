#include "RealEstate.h"
#include "Entity.h"

RealEstate::RealEstate(const string& name, 
	const Accessibility& access, 
	const Entity* owner, 
	const Entity* renter, 
	const string& address, 
	bool isStateProperty):
	name_(name),
	access_(access), 
	owner_(owner),
	renter_(renter),
	address_(address),
	isStateProperty_(isStateProperty){}

RealEstate::RealEstate():name_("---"),
	owner_(nullptr),
	renter_(nullptr), 
	address_("---"), 
	isStateProperty_(false)
	{}

string RealEstate::getName() const{
	return name_;
}
void RealEstate::setName(const string& name){
	name_ = name;
}

Accessibility RealEstate::getAccess() const{
	return access_;
}
void RealEstate::setAccess(const Accessibility& access){
	access_ = access;
}

const Entity* RealEstate::getOwner() const{
	return owner_;
}
void RealEstate::setOwner(const Entity* owner){
		owner_ = owner;
}

const Entity* RealEstate::getRenter() const{
	return renter_;
}
void  RealEstate::setRenter(const Entity* renter){
	renter_ = renter;
}

string RealEstate::getAddress() const{
	return address_;
}
void  RealEstate::setAddress(const string& address){
	address_ = address;
}

bool  RealEstate::getIsStateProperty() const {
	return isStateProperty_;
}
void  RealEstate::setIsStateProperty(bool IsStateProperty) {
	isStateProperty_ = IsStateProperty;
}


void RealEstate::showInfo() const{
	cout << "\n" << name_ << "\n";
	access_.showInfo();
	owner_->showInfo();
	renter_->showInfo();
	cout << "\n" << address_ << "\n";
}
