#include "PhysicalEntity.h"
#include <algorithm>
#include <regex>
#include <iterator>

using namespace std;

bool PhysicalEntity::containsOnlyLetters(const string& str) {
	return all_of(str.begin(), str.end(), [](unsigned char c) {
		return isalpha(c);
		});
}

PhysicalEntity::PhysicalEntity(const FullName& fullName, 
	const PhysicalEntityContactInfo& contactInfo,
	string documentType, 
	const string& documentId)
	:Entity("PhysicalEntity"),
	fullName_(fullName),
	contactInfo_(contactInfo), 
	documentType_(documentType), 
	documentId_(documentId), 
	id_(idCounter_++) {}

PhysicalEntity::PhysicalEntity() :Entity("PhysicalEntity"), id_(idCounter_++), documentType_("passport"), documentId_("---") {
	fullName_.firstName_ = "---";
	fullName_.middleName_ = "---";
	fullName_.surname_ = "---";
	contactInfo_.email_ = "---";
	contactInfo_.phoneNumber_ = "---";
	contactInfo_.socialMediaLinks_ = {
		{"telegram","---"},
		{"vk","---"},
		{"instagram","---"},
		{"facebook","---"},
		{"linkedin","---"},
	};
};

FullName PhysicalEntity::getFullName() const{ 
	return fullName_; 
}
void PhysicalEntity::setFullName(const FullName& fullName) {
	fullName_ = fullName; 
}

string PhysicalEntity::getFirstName() const{
	return fullName_.firstName_;
}
void PhysicalEntity::setFirstName(const string& firstName){
	if (checkName(firstName)) fullName_.firstName_ = firstName;
}
string PhysicalEntity::getMiddleName() const{
	return fullName_.middleName_;
}
void PhysicalEntity::setMiddleName(const string& middleName){
	if (checkName(middleName)) fullName_.middleName_ = middleName;
}
string PhysicalEntity::getSurname() const{
	return fullName_.surname_;
}
void PhysicalEntity::setSurname(const string& surname){
	if (checkName(surname)) fullName_.surname_ = surname;
}

size_t PhysicalEntity::getId() const { 
	return id_;
}
void PhysicalEntity::setId(size_t id) { 
	id_ = id; 
}

string PhysicalEntity::getDocumentType() const { 
	return documentType_; 
}
void PhysicalEntity::setDocumentType(string documentType) { 
	documentType_ = documentType; 
}

string PhysicalEntity::getDocumentId() const {
	return documentId_; 
}
void PhysicalEntity::setDocumentId(const string& documentId) { 
	documentId_ = documentId; 
}

PhysicalEntityContactInfo PhysicalEntity::getContactInfo() const {
	return contactInfo_;
}
void PhysicalEntity::setContactInfo(const PhysicalEntityContactInfo& contactInfo){
	contactInfo_ = contactInfo; 
}


string PhysicalEntity::getPhoneNumber() const{
	return contactInfo_.phoneNumber_;
}
void PhysicalEntity::setPhoneNumber(const string& phoneNumber){
	if (checkPhoneNumber(phoneNumber)) contactInfo_.phoneNumber_ = phoneNumber;
}
string PhysicalEntity::getEmail() const{
	return contactInfo_.email_;
}
void PhysicalEntity::setEmail(const string& email){
	if (checkEmail(email)) contactInfo_.email_ = email;
}
unordered_map<string, string>  PhysicalEntity::getSocialMediaLinks() const{
	return contactInfo_.socialMediaLinks_;
}
void  PhysicalEntity::setSocialMediaLinks(const string& key,const string& value){
	auto it = contactInfo_.socialMediaLinks_.find(key);
	if (it != contactInfo_.socialMediaLinks_.end()) {
		contactInfo_.socialMediaLinks_[key] = value;
	}
}


void PhysicalEntity::showInfo() const{
	cout << "\n____" << fullName_.firstName_ << " " << fullName_.middleName_ << " " <<
		fullName_.surname_ << "____\n";
	cout << "\n Id: " << id_;
	cout << "\n Document type: " << documentType_;
	cout << "\n Document id: " << documentId_;
	cout << "\n Contact info: \n" << contactInfo_.email_ << "\n" <<
		contactInfo_.phoneNumber_ << "\n";
	for (auto const& pair : contactInfo_.socialMediaLinks_) {
		std::cout << pair.first << ": " << pair.second << std::endl;
	}
}

size_t PhysicalEntity::idCounter_ = 0;

bool PhysicalEntity::checkName(const string& name) {
		try {
			if (!containsOnlyLetters(name)) {
				throw invalid_argument("Invalid input. Name can only consist of letters");
			}
			else if (name.empty()) {
				throw invalid_argument("Empty field");
			}
			return true;
		}
		catch (invalid_argument& arg) {
			cout << "\n" << arg.what() << "\n";
			return false;
		}
}
bool PhysicalEntity::checkPhoneNumber(const string& number) {
	regex phoneRegex("\\+[0-9]{12}");
		try {
			if (!regex_match(number, phoneRegex)) {
				throw invalid_argument("Invalid input");
			}
			else if (number.empty()) {
				throw invalid_argument("Empty field");
			}
			return true;
		}
		catch (invalid_argument& arg) {
			cout << "\n" << arg.what() << "\n";
			return false;
		}
}
bool PhysicalEntity::checkEmail(const string& email){
	regex emailRegex("^[a-zA-Z0-9._%+-]+@gmail\\.com$");
		try {
			if (!regex_match(email, emailRegex)) {
				throw invalid_argument("Invalid input");
			}
			else if (email.empty()) {
				throw invalid_argument("Empty field");
			}
			return true;
		}
		catch (invalid_argument& arg) {
			cout << "\n" << arg.what() << "\n";
			return false;
		}
}

