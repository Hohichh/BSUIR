#include "ResidentalRealEstate.h"



ResidentalRealEstate::ResidentalRealEstate(const string& name,
	const Accessibility& access,
	const Entity* owner,
	const Entity* renter,
	const string& address,
	bool isStateProperty,
	double buildSquare,
	double sorroundAreaSquare,
	const string& builtDate, 
	const string& lastOverHaulDate, 
	const string& condition, 
	bool hasParkingLot, 
	bool hasYard): RealEstate(name,
		 access,
		 owner,
		 renter,
		 address,
		 isStateProperty),
	buildSquare_(buildSquare), 
	sorroundAreaSquare_(sorroundAreaSquare),
	builtDate_(builtDate), 
	lastOverHaulDate_(lastOverHaulDate), 
	condition_(condition),
	hasParkingLot_(hasParkingLot), 
	hasYard_(hasYard) {}

ResidentalRealEstate::ResidentalRealEstate(): RealEstate(),
	buildSquare_(0), 
	sorroundAreaSquare_(0), 
	builtDate_("---"), 
	lastOverHaulDate_("---"), 
	condition_("---"), 
	hasParkingLot_(false),
	hasYard_(false) {}

double ResidentalRealEstate::getBuildSquare() const { 
	return buildSquare_;
}
void ResidentalRealEstate::setBuildSquare(double buildSquare) { 
	buildSquare_ = buildSquare; 
}

double ResidentalRealEstate::getSorroundAreaSquare() const { 
	return sorroundAreaSquare_; 
}
void ResidentalRealEstate::setSorroundAreaSquare(double sorroundAreaSquare) { 
	sorroundAreaSquare_ = sorroundAreaSquare;
}

string ResidentalRealEstate::getBuiltDate() const { 
	return builtDate_; 
}
void ResidentalRealEstate::setBuiltDate(const string& builtDate) { 
	builtDate_ = builtDate; 
}

string ResidentalRealEstate::getLastOverHaulDate() const {
	return lastOverHaulDate_;
}
void ResidentalRealEstate::setLastOverHaulDate(const string& lastOverHaulDate) { 
	lastOverHaulDate_ = lastOverHaulDate;
}

string ResidentalRealEstate::getCondition() const {
	return condition_;
}
void ResidentalRealEstate::setCondition(const string& condition) { 
	condition_ = condition;
}

bool ResidentalRealEstate::getHasParkingLot() const { 
	return hasParkingLot_;
}
void ResidentalRealEstate::setHasParkingLot(bool hasParkingLot) { 
	hasParkingLot_ = hasParkingLot; 
}

bool ResidentalRealEstate::getHasYard() const { 
	return hasYard_; 
}
void ResidentalRealEstate::setHasYard(bool hasYard) { 
	hasYard_ = hasYard;
}

void ResidentalRealEstate::showInfo() const {
	RealEstate::showInfo();
	cout << "Build square: " << buildSquare_ << endl;
	cout << "Surround area square: " << sorroundAreaSquare_ << endl;
	cout << "Built date: " << builtDate_ << endl;
	cout << "Last overhaul date: " << lastOverHaulDate_ << endl;
	cout << "Condition: " << condition_ << endl;
	cout << "Has parking lot: " << (hasParkingLot_ ? "Yes" : "No") << endl;
	cout << "Has yard: " << (hasYard_ ? "Yes" : "No") << endl;
}