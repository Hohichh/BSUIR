#include "CulturalRealEstate.h"


CulturalRealEstate::CulturalRealEstate():RealEstate(),
buildSquare_(0),
	sorroundAreaSquare_(0),
	isMuseam_(false),
	condition_("---"),
	historicalSignificance_("---"),
	culturalHeritageProtection_("---"){}

CulturalRealEstate::CulturalRealEstate(const BaseConditions& baseConditions,
	const CulturalConditions& culturalConditions): RealEstate(baseConditions),
	buildSquare_(culturalConditions.buildSquare),
	sorroundAreaSquare_(culturalConditions.sorroundAreaSquare),
	isMuseam_(culturalConditions.isMuseam),
	condition_(culturalConditions.condition),
	historicalSignificance_(culturalConditions.historicalSignificance),
	culturalHeritageProtection_(culturalConditions.culturalHeritageProtection) {}

double CulturalRealEstate::getBuildSquare() const 
{ return buildSquare_;
}
void CulturalRealEstate::setBuildSquare(double buildSquare) { 
	buildSquare_ = buildSquare;
}

double CulturalRealEstate::getSorroundAreaSquare() const { 
	return sorroundAreaSquare_;
}
void CulturalRealEstate::setSorroundAreaSquare(double sorroundAreaSquare) { 
	sorroundAreaSquare_ = sorroundAreaSquare;
}

bool CulturalRealEstate::getIsMuseam() const { 
	return isMuseam_; 
}
void CulturalRealEstate::setIsMuseam(bool isMuseam) {
	isMuseam_ = isMuseam;
}

string CulturalRealEstate::getCondition() const {
	return condition_; 
}
void CulturalRealEstate::setCondition(const string& condition) {
	condition_ = condition;
}

string CulturalRealEstate::getHistoricalSignificance() const {
	return historicalSignificance_; 
}
void CulturalRealEstate::setHistoricalSignificance(const string& historicalSignificance) { 
	historicalSignificance_ = historicalSignificance; 
}

string CulturalRealEstate::getCulturalHeritageProtection() const { 
	return culturalHeritageProtection_;
}
void CulturalRealEstate::setCulturalHeritageProtection(const string& culturalHeritageProtection) { 
	culturalHeritageProtection_ = culturalHeritageProtection; 
}

void CulturalRealEstate::showInfo() const {
	RealEstate::showInfo(); 
	cout << "Build square: " << buildSquare_ << endl;
	cout << "Surround area square: " << sorroundAreaSquare_ << endl;
	cout << "Is museum: " << (isMuseam_ ? "Yes" : "No") << endl;
	cout << "Condition: " << condition_ << endl;
	cout << "Historical significance: " << historicalSignificance_ << endl;
	cout << "Cultural heritage protection: " << culturalHeritageProtection_ << endl;
}