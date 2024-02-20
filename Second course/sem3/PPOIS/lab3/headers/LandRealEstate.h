#pragma once
#include "RealEstate.h"


struct LandConditions {
	double landSquare;
	string powerSupply;
	string waterSupply;
	string accessToTransportation;
	bool isAgricultureSuitable;
	bool isBuildSuitable;
	string soilType;
};

class LandRealEstate : public RealEstate {
private:
	double landSquare_;
	string powerSupply_;
	string waterSupply_;
	string accessToTransportation_;
	bool isAgricultureSuitable_;
	bool isBuildSuitable_;
	string soilType_;

public:

	LandRealEstate();
	LandRealEstate(const BaseConditions& baseConditions,
		const LandConditions& landConditions);

	double getLandSquare() const;
	void setLandSquare(double landSquare);

	string getPowerSupply() const;
	void setPowerSupply(const string& powerSupply);

	string getWaterSupply() const;
	void setWaterSupply(const string& waterSupply);

	string getAccessToTransportation() const;
	void setAccessToTransportation(const string& accessToTransportation);

	bool getIsAgricultureSuitable() const;
	void setIsAgricultureSuitable(bool isAgricultureSuitable);

	bool getIsBuildSuitable() const;
	void setIsBuildSuitable(bool isBuildSuitable);

	string getSoilType() const;
	void setSoilType(const string& soilType);

	void showInfo() const;
};