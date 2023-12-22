#include "Accessibility.h"
#include <iostream>

Accessibility::Accessibility(): isLimited_(1), limitationType_("Full limited"), accessConditions_("---"),
accessRestrictions_("---") {}
Accessibility::Accessibility(bool isLimited, string limitationType, string accessConditions,
	string accessRestrictions): isLimited_(isLimited), limitationType_(limitationType), 
	accessConditions_(limitationType), accessRestrictions_(accessConditions) {}

bool Accessibility::getIsLimited() const{
	return isLimited_;
}
void Accessibility::setIsLimited(bool isLimited){
	isLimited_ = isLimited;
}

string Accessibility::getLimitationType() const{
	return limitationType_;
}
void Accessibility::setLimitationType(const string& limitationType){
	limitationType_ = limitationType;
}

string Accessibility::getAccessConditions() const{
	return accessConditions_;
}
void Accessibility::setAccessConditions(const string& accessConditions){
	accessConditions_ = accessConditions;
}

string Accessibility::getAccessRestrictions() const{
	return accessRestrictions_;
}
void Accessibility::setAccessRestrictions(const string& accessRestrictions){
	accessRestrictions_ = accessRestrictions;
}

Schedule Accessibility::getSchedule(){
	return schedule_;
}
void Accessibility::setSchedule(const Schedule& schedule){
	schedule_ = schedule;
}

void Accessibility::showInfo() const{
	cout << "\nAccess info:\n";
	cout << "Limitation: " << isLimited_ << "\n";
	cout << "Limitation type: " << limitationType_ << "\n";
	cout << "Access conditions: " << accessConditions_ << "\n";
	cout << "Access restrictions: " << accessRestrictions_ << "\n";
	schedule_.showSchedule();
}


bool Accessibility::operator==(const Accessibility& other) const{
	return (isLimited_ == other.isLimited_ &&
		limitationType_ == other.limitationType_ &&
		accessConditions_ == other.accessConditions_ &&
		accessRestrictions_ == other.accessConditions_ &&
		schedule_ == other.schedule_);
}