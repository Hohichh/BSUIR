#pragma once
#include "RealEstate.h"

struct IndustrialConditions {
	double buildSquare;
	bool hasWarehouse;
	bool isHazardous;
	float sanEpidemRate;
	bool  isIndustrialPark;
	string powerSupply;
	string waterSupply;
	string accessToTransportation;
	string zoningRestrictions;
};

class IndustrialRealEstate : public RealEstate{
private:
	double buildSquare_;
	bool hasWarehouse_;
	bool isHazardous_;
	float sanEpidemRate_;
	bool  isIndustrialPark_;
	string powerSupply_;
	string waterSupply_;
	string accessToTransportation_;
	string zoningRestrictions_;

public: 
	IndustrialRealEstate();
	IndustrialRealEstate(const BaseConditions& baseConditions,
		const IndustrialConditions& industrialConditions);
	
	double getBuildSquare() const;
	void setBuildSquare(double buildSquare);

	bool getHasWarehouse() const;
	void setHasWarehouse(bool hasWarehouse);

	bool getIsHazardous() const;
	void setIsHazardous(bool isHazardous);

	float getSanEpidemRate() const;
	void setSanEpidemRate(float sanEpidemRate);

	bool getIsIndustrialPark() const;
	void setIsIndustrialPark(bool isIndustrialPark);

	string getPowerSupply() const;
	void setPowerSupply(const string& powerSupply);

	string getWaterSupply() const;
	void setWaterSupply(const string& waterSupply);

	string getAccessToTransportation() const;
	void setAccessToTransportation(const string& accessToTransportation);

	string getZoningRestrictions() const;
	void setZoningRestrictions(const string& zoningRestrictions);

	void showInfo() const;

};