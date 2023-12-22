#include "ServiceRealEstate.h"


ServiceRealEstate::ServiceRealEstate(const string& name,
	const Accessibility& access,
	const Entity* owner,
	const Entity* renter,
	const string& address,
	bool isStateProperty,
	const string& serviceCategory,
	const string& bulidingCategory, 
	bool hasParkingLot, 
	float sanEpidemRate, 
	double buildSquare, 
	bool accesibleInviroment):
	RealEstate(name,
		access,
		owner,
		renter,
		address,
		isStateProperty ),
	serviceCategory_(serviceCategory), 
	bulidingCategory_(bulidingCategory),
	hasParkingLot_(hasParkingLot), 
	sanEpidemRate_(sanEpidemRate), 
	buildSquare_(buildSquare),
	accesibleInviroment_(accesibleInviroment) {}

ServiceRealEstate::ServiceRealEstate(): RealEstate(),
	serviceCategory_("---"), 
	bulidingCategory_("---"),
	hasParkingLot_(false), 
	sanEpidemRate_(0), 
	buildSquare_(0), 
	accesibleInviroment_(false) {}

string ServiceRealEstate::getServiceCategory() const { 
	return serviceCategory_;
}
void ServiceRealEstate::setServiceCategory(const string& serviceCategory) { 
	serviceCategory_ = serviceCategory;
}

string ServiceRealEstate::getBulidingCategory() const { 
	return bulidingCategory_;
}
void ServiceRealEstate::setBulidingCategory(const string& bulidingCategory) { 
	bulidingCategory_ = bulidingCategory;
}

bool ServiceRealEstate::getHasParkingLot() const { 
	return hasParkingLot_;
}
void ServiceRealEstate::setHasParkingLot(bool hasParkingLot) { 
	hasParkingLot_ = hasParkingLot;
}

float ServiceRealEstate::getSanEpidemRate() const { 
	return sanEpidemRate_; 
}
void ServiceRealEstate::setSanEpidemRate(float sanEpidemRate) { 
	sanEpidemRate_ = sanEpidemRate;
}

double ServiceRealEstate::getBuildSquare() const { 
	return buildSquare_;
}
void ServiceRealEstate::setBuildSquare(double buildSquare) { 
	buildSquare_ = buildSquare; 
}

bool ServiceRealEstate::getAccesibleInviroment() const {
	return accesibleInviroment_;
}
void ServiceRealEstate::setAccesibleInviroment(bool accesibleInviroment) { 
	accesibleInviroment_ = accesibleInviroment;
}

// Метод showInfo
void  ServiceRealEstate::showInfo() const {
	RealEstate::showInfo(); 
	cout << "Service category: " << serviceCategory_ << endl;
	cout << "Building category: " << bulidingCategory_ << endl;
	cout << "Has parking lot: " << (hasParkingLot_ ? "Yes" : "No") << endl;
	cout << "San epidem rate: " << sanEpidemRate_ << endl;
	cout << "Build square: " << buildSquare_ << endl;
	cout << "Accessible environment: " << (accesibleInviroment_ ? "Yes" : "No") << endl;
}
