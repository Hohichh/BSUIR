#pragma once
#include "RealEstate.h"


class LandRealEstate : public RealEstate {
public:
	double landSquare_;
	string powerSupply_;
	string waterSupply_;
	string accessToTransportation_;
	bool isAgricultureSuitable_;
	bool isBuildSuitable_;
	string soilType_;

public:

	LandRealEstate();
	LandRealEstate(const string& name,
		const Accessibility& access,
		const Entity* owner,
		const Entity* renter,
		const string& address,
		bool isStateProperty,
		double landSquare,
	const string& powerSupply,
	const string& waterSupply,
	const string& accessToTransportation,
	bool isAgricultureSuitable,
	bool isBuildSuitable,
	const string& soilType);

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