#pragma once
#include "RealEstate.h"


class ServiceRealEstate : public RealEstate {
public:
	string serviceCategory_;
	string bulidingCategory_;
	bool hasParkingLot_;
	float sanEpidemRate_;
	double buildSquare_;
	bool accesibleInviroment_;

public:
	ServiceRealEstate(const string& name,
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
		bool accesibleInviroment);
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