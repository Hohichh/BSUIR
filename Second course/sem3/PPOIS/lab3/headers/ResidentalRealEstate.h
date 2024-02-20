#pragma once
#include "RealEstate.h"


struct ResidentalConditions {
	double buildSquare;
	double sorroundAreaSquare;
	string builtDate;
	string lastOverHaulDate;
	string condition;
	bool hasParkingLot;
	bool hasYard;
};

class ResidentalRealEstate : public RealEstate{
private:
	double buildSquare_;
	double sorroundAreaSquare_;
	string builtDate_;
	string lastOverHaulDate_;
	string condition_;
	bool hasParkingLot_;
	bool hasYard_;

public:
	ResidentalRealEstate(const BaseConditions& baseConditions,
		const ResidentalConditions& residentalConditions);
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