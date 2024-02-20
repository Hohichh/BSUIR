#pragma once
#include "RealEstate.h"

struct CulturalConditions {
	double buildSquare;
	double sorroundAreaSquare;
	bool isMuseam;
	string condition;
	string historicalSignificance;
	string culturalHeritageProtection;
};

class CulturalRealEstate : public RealEstate {
private:
	double buildSquare_;
	double sorroundAreaSquare_;
	bool isMuseam_;
	string condition_;
	string historicalSignificance_;
	string culturalHeritageProtection_;

public:

	CulturalRealEstate();
	CulturalRealEstate(const BaseConditions& baseConditions,
		const CulturalConditions& culturalConditions);

	double getBuildSquare() const;
	void setBuildSquare(double buildSquare);

	double getSorroundAreaSquare() const;
	void setSorroundAreaSquare(double sorroundAreaSquare);

	bool getIsMuseam() const;
	void setIsMuseam(bool isMuseam);

	string getCondition() const;
	void setCondition(const string& condition);

	string getHistoricalSignificance() const;
	void setHistoricalSignificance(const string& historicalSignificance);

	string getCulturalHeritageProtection() const;
	void setCulturalHeritageProtection(const string& culturalHeritageProtection);

	void showInfo() const;
};