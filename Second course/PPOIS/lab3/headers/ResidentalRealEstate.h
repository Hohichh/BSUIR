#pragma once
#include "RealEstate.h"

class ResidentalRealEstate : public RealEstate{
public:
	double buildSquare_;
	double sorroundAreaSquare_;
	string builtDate_;
	string lastOverHaulDate_;
	string condition_;
	bool hasParkingLot_;
	bool hasYard_;

public:
	ResidentalRealEstate(const string& name,
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
		bool hasYard);
	ResidentalRealEstate();

	double getBuildSquare() const;
	void setBuildSquare(double buildSquare);

	double getSorroundAreaSquare() const;
	void setSorroundAreaSquare(double sorroundAreaSquare);

	string getBuiltDate() const;
	void setBuiltDate(const string& builtDate);

	string getLastOverHaulDate() const;
	void setLastOverHaulDate(const string& lastOverHaulDate);

	string getCondition() const;
	void setCondition(const string& condition);

	bool getHasParkingLot() const;
	void setHasParkingLot(bool hasParkingLot);

	bool getHasYard() const;
	void setHasYard(bool hasYard);

	void showInfo() const;
};