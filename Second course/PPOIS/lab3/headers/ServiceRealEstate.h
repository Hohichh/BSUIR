#pragma once
#include "RealEstate.h"


struct ServiceConditions {
	string serviceCategory;
	string bulidingCategory;
	bool hasParkingLot;
	float sanEpidemRate;
	double buildSquare;
	bool accesibleInviroment;
};

class ServiceRealEstate : public RealEstate {
private:
	string serviceCategory_;
	string bulidingCategory_;
	bool hasParkingLot_;
	float sanEpidemRate_;
	double buildSquare_;
	bool accesibleInviroment_;

public:
	ServiceRealEstate(const BaseConditions& baseConditions,
		const ServiceConditions& serviceConditions);
	ServiceRealEstate();

	string getServiceCategory() const;
	void setServiceCategory(const string& serviceCategory);

	string getBulidingCategory() const;
	void setBulidingCategory(const string& bulidingCategory);

	bool getHasParkingLot() const;
	void setHasParkingLot(bool hasParkingLot);

	float getSanEpidemRate() const;
	void setSanEpidemRate(float sanEpidemRate);

	double getBuildSquare() const;
	void setBuildSquare(double buildSquare);

	bool getAccesibleInviroment() const;
	void setAccesibleInviroment(bool accesibleInviroment);

	void showInfo() const;
};