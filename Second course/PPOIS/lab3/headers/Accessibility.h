#pragma once
#include <string>
#include <vector>
#include "Schedule.h"

using namespace std;



class Accessibility {
public:
	bool isLimited_;
	string limitationType_;
	string accessConditions_;
	string accessRestrictions_;
	Schedule schedule_;

public:
	Accessibility();
	Accessibility(bool isLimited, string limitationType, string accessConditions,
	string accessRestrictions);

	bool getIsLimited() const;
	void setIsLimited(bool isLimited);

	string getLimitationType() const;
	void setLimitationType(const string& limitationType);

	string getAccessConditions() const;
	void setAccessConditions(const string& accessConditions);

	string getAccessRestrictions() const;
	void setAccessRestrictions(const string& accessRestrictions);
	
	Schedule getSchedule();
	void setSchedule(const Schedule& schedule);

	void showInfo() const;

	bool operator==(const Accessibility& other) const;
};
