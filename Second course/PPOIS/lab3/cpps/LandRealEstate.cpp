#include "LandRealEstate.h"


	LandRealEstate::LandRealEstate(): RealEstate(),
	landSquare_(0),
	powerSupply_("---"),
	waterSupply_("---"),
	accessToTransportation_("---"),
	isAgricultureSuitable_(false),
	isBuildSuitable_(false),
	soilType_("---") {}

	LandRealEstate::LandRealEstate(const string& name,
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
		const string& soilType): RealEstate(name,
			access,
			owner,
			renter,
			address,
			isStateProperty),
		landSquare_(landSquare),
		powerSupply_(powerSupply),
		waterSupply_(waterSupply),
		accessToTransportation_(accessToTransportation),
		isAgricultureSuitable_(isAgricultureSuitable),
		isBuildSuitable_(isBuildSuitable),
		soilType_(soilType) {}

	double LandRealEstate::getLandSquare() const { return landSquare_; }
	void LandRealEstate::setLandSquare(double landSquare) { landSquare_ = landSquare; }

	string LandRealEstate::getPowerSupply() const { return powerSupply_; }
	void LandRealEstate::setPowerSupply(const string& powerSupply) { powerSupply_ = powerSupply; }

	string LandRealEstate::getWaterSupply() const { return waterSupply_; }
	void LandRealEstate::setWaterSupply(const string& waterSupply) { waterSupply_ = waterSupply; }

	string LandRealEstate::getAccessToTransportation() const { return accessToTransportation_; }
	void LandRealEstate::setAccessToTransportation(const string& accessToTransportation) { accessToTransportation_ = accessToTransportation; }

	bool LandRealEstate::getIsAgricultureSuitable() const { return isAgricultureSuitable_; }
	void LandRealEstate::setIsAgricultureSuitable(bool isAgricultureSuitable) { isAgricultureSuitable_ = isAgricultureSuitable; }

	bool LandRealEstate::getIsBuildSuitable() const { return isBuildSuitable_; }
	void LandRealEstate::setIsBuildSuitable(bool isBuildSuitable) { isBuildSuitable_ = isBuildSuitable; }

	string LandRealEstate::getSoilType() const { return soilType_; }
	void LandRealEstate::setSoilType(const string& soilType) { soilType_ = soilType; }


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