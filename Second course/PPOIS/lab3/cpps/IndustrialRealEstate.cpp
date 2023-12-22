#include "IndustrialRealEstate.h"


	IndustrialRealEstate::IndustrialRealEstate(): RealEstate(),
		buildSquare_(0),
	hasWarehouse_(false),
	isHazardous_(false),
	sanEpidemRate_(0),
	isIndustrialPark_(false),
	powerSupply_("---"),
	waterSupply_("---"),
	accessToTransportation_("---"),
	zoningRestrictions_("---") {}

	IndustrialRealEstate::IndustrialRealEstate(const string& name,
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
		const string& zoningRestrictions): RealEstate(name,
			access,
			 owner,
			renter,
			 address,
			isStateProperty),
		buildSquare_(buildSquare),
		hasWarehouse_(hasWarehouse),
		isHazardous_(isHazardous),
		sanEpidemRate_(sanEpidemRate),
		isIndustrialPark_(isIndustrialPark),
		powerSupply_(powerSupply),
		waterSupply_(waterSupply),
		accessToTransportation_(accessToTransportation),
		zoningRestrictions_(zoningRestrictions)
	{}

	double IndustrialRealEstate::getBuildSquare() const { return buildSquare_; }
	void IndustrialRealEstate::setBuildSquare(double buildSquare) { buildSquare_ = buildSquare; }

	bool IndustrialRealEstate::getHasWarehouse() const { return hasWarehouse_; }
	void IndustrialRealEstate::setHasWarehouse(bool hasWarehouse) { hasWarehouse_ = hasWarehouse; }

	bool IndustrialRealEstate::getIsHazardous() const { return isHazardous_; }
	void IndustrialRealEstate::setIsHazardous(bool isHazardous) { isHazardous_ = isHazardous; }

	float IndustrialRealEstate::getSanEpidemRate() const { return sanEpidemRate_; }
	void IndustrialRealEstate::setSanEpidemRate(float sanEpidemRate) { sanEpidemRate_ = sanEpidemRate; }

	bool IndustrialRealEstate::getIsIndustrialPark() const { return isIndustrialPark_; }
	void IndustrialRealEstate::setIsIndustrialPark(bool isIndustrialPark) { isIndustrialPark_ = isIndustrialPark; }

	string IndustrialRealEstate::getPowerSupply() const { return powerSupply_; }
	void IndustrialRealEstate::setPowerSupply(const string& powerSupply) { powerSupply_ = powerSupply; }

	string IndustrialRealEstate::getWaterSupply() const { return waterSupply_; }
	void IndustrialRealEstate::setWaterSupply(const string& waterSupply) { waterSupply_ = waterSupply; }

	string IndustrialRealEstate::getAccessToTransportation() const { return accessToTransportation_; }
	void IndustrialRealEstate::setAccessToTransportation(const string& accessToTransportation) { accessToTransportation_ = accessToTransportation; }

	string IndustrialRealEstate::getZoningRestrictions() const { return zoningRestrictions_; }
	void IndustrialRealEstate::setZoningRestrictions(const string& zoningRestrictions) { zoningRestrictions_ = zoningRestrictions; }

	void IndustrialRealEstate::showInfo() const {
		RealEstate::showInfo();
		cout << "Build square: " << buildSquare_ << endl;
		cout << "Has warehouse: " << (hasWarehouse_ ? "Yes" : "No") << endl;
		cout << "Is hazardous: " << (isHazardous_ ? "Yes" : "No") << endl;
		cout << "San epidem rate: " << sanEpidemRate_ << endl;
		cout << "Is industrial park: " << (isIndustrialPark_ ? "Yes" : "No") << endl;
		cout << "Power supply: " << powerSupply_ << endl;
		cout << "Water supply: " << waterSupply_ << endl;
		cout << "Access to transportation: " << accessToTransportation_ << endl;
		cout << "Zoning restrictions: " << zoningRestrictions_ << endl;
	}