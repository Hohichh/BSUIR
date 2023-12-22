#pragma once
#include "RealEstate.h"

class CulturalRealEstate : public RealEstate {
public:
	double buildSquare_;
	double sorroundAreaSquare_;
	bool isMuseam_;
	string condition_;
	string historicalSignificance_;
	string culturalHeritageProtection_;

public:

	CulturalRealEstate();
	CulturalRealEstate(const string& name,
		const Accessibility& access,
		const Entity* owner,
		const Entity* renter,
		const string& address,
		bool isStateProperty,
		double buildSquare,
	double sorroundAreaSquare,
	bool isMuseam,
	const string& condition,
	const string& historicalSignificance,
	const string& culturalHeritageProtection);

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