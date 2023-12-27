#include "LandRealEstate.h"


	LandRealEstate::LandRealEstate(): RealEstate(),
	landSquare_(0),
	powerSupply_("---"),
	waterSupply_("---"),
	accessToTransportation_("---"),
	isAgricultureSuitable_(false),
	isBuildSuitable_(false),
	soilType_("---") {}

	LandRealEstate::LandRealEstate(const BaseConditions& baseConditions,
		const LandConditions& landConditions): RealEstate(baseConditions),
		landSquare_(landConditions.landSquare),
		powerSupply_(landConditions.powerSupply),
		waterSupply_(landConditions.waterSupply),
		accessToTransportation_(landConditions.accessToTransportation),
		isAgricultureSuitable_(landConditions.isAgricultureSuitable),
		isBuildSuitable_(landConditions.isBuildSuitable),
		soilType_(landConditions.soilType) {}

	double LandRealEstate::getLandSquare() const { 
		return landSquare_; 
	}
	void LandRealEstate::setLandSquare(double landSquare) {
		landSquare_ = landSquare;
	}

	string LandRealEstate::getPowerSupply() const {
		return powerSupply_; 
	}
	void LandRealEstate::setPowerSupply(const string& powerSupply) {
		powerSupply_ = powerSupply; 
	}

	string LandRealEstate::getWaterSupply() const {
		return waterSupply_;
	}
	void LandRealEstate::setWaterSupply(const string& waterSupply) {
		waterSupply_ = waterSupply;
	}

	string LandRealEstate::getAccessToTransportation() const { 
		return accessToTransportation_;
	}
	void LandRealEstate::setAccessToTransportation(const string& accessToTransportation) {
		accessToTransportation_ = accessToTransportation; 
	}

	bool LandRealEstate::getIsAgricultureSuitable() const {
		return isAgricultureSuitable_; 
	}
	void LandRealEstate::setIsAgricultureSuitable(bool isAgricultureSuitable) { 
		isAgricultureSuitable_ = isAgricultureSuitable;
	}

	bool LandRealEstate::getIsBuildSuitable() const { 
		return isBuildSuitable_;
	}
	void LandRealEstate::setIsBuildSuitable(bool isBuildSuitable) {
		isBuildSuitable_ = isBuildSuitable; 
	}

	string LandRealEstate::getSoilType() const { 
		return soilType_;
	}
	void LandRealEstate::setSoilType(const string& soilType) {
		soilType_ = soilType;
	}


	void LandRealEstate::showInfo() const {
		RealEstate::showInfo(); 
		cout << "Land square: " << landSquare_ << endl;
		cout << "Power supply: " << powerSupply_ << endl;
		cout << "Water supply: " << waterSupply_ << endl;
		cout << "Access to transportation: " << accessToTransportation_ << endl;
		cout << "Is agriculture suitable: " << (isAgricultureSuitable_ ? "Yes" : "No") << endl;
		cout << "Is build suitable: " << (isBuildSuitable_ ? "Yes" : "No") << endl;
		cout << "Soil type: " << soilType_ << endl;
	}