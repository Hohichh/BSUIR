#pragma once
#include "RealEstate.h"

class IndustrialRealEstate : public RealEstate{
public:
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
	IndustrialRealEstate(const string& name,
		const Accessibility& access,
		const Entity* owner,
		const Entity* renter,
		const string& address,
		bool isStateProperty,
		double buildSquare,
	bool hasWarehouse,
	bool isHazardous,
	float sanEpidemRate,
	bool  isIndustrialPark,
	const string& powerSupply,
	const string& waterSupply,
	const string& accessToTransportation,
	const string& zoningRestrictions);
	
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