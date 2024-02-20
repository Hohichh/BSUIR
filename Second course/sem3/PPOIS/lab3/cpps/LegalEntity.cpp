#include "LegalEntity.h"
#include <regex>


bool LegalEntity::containsOnlyLetters(const string& str) {
	return all_of(str.begin(), str.end(), [](unsigned char c) {
		return isalpha(c);
		});
}

LegalEntity::LegalEntity(const string& name,
	const LegalEntityContactInfo& contactInfo,
	const string& legalForm, 
	const string& registrationNumber)
	: Entity("LegalEntity"), name_(name),
	contactInfo_(contactInfo), 
	legalForm_(legalForm), 
	registrationNumber_(registrationNumber),
	id_(idCounter_++) {}

LegalEntity::LegalEntity() :Entity("LegalEntity"), name_("---"), legalForm_("---"),
registrationNumber_("---"), id_(idCounter_++) {
	contactInfo_.address_ = "---";
	contactInfo_.email_ = "---";
	contactInfo_.phoneNumber_ = "---";
}

string LegalEntity::getName() const { 
	return name_;
}
void LegalEntity::setName(const string& name) {
	name_ = name; 
}

LegalEntityContactInfo LegalEntity::getContactInfo() const {
	return contactInfo_; 
}
void LegalEntity::setContactInfo(const LegalEntityContactInfo& contactInfo) {
	contactInfo_ = contactInfo; 
}

string LegalEntity::getPhoneNumber() const {
	return contactInfo_.phoneNumber_;
}
void LegalEntity::setPhoneNumber(const string& phoneNumber) {
	if (checkPhoneNumber(phoneNumber)) contactInfo_.phoneNumber_ = phoneNumber;
}
string LegalEntity::getEmail() const {
	return contactInfo_.email_;
}
void LegalEntity::setEmail(const string& email) {
	if (checkEmail(email)) contactInfo_.email_ = email;
}
string LegalEntity::getAddress() const{
	return contactInfo_.address_;
}
void LegalEntity::setAddress(const string& address){
	if (checkAddress(address)) contactInfo_.address_ = address;
}


string LegalEntity::getLegalForm() const {
	return legalForm_; 
}
void LegalEntity::setLegalForm(const string& legalForm) {
	legalForm_ = legalForm; 
}

string LegalEntity::getRegistrationNumber() const {
	return registrationNumber_; 
}
void LegalEntity::setRegistrationNumber(const string& registrationNumber) {
	registrationNumber_ = registrationNumber;
}
;
size_t LegalEntity::getId() const {
	return id_;
}
void LegalEntity::setId(size_t id) {
	id_ = id; 
}

void LegalEntity::showInfo() const{
	cout << "\n____" << name_ << "____\n";
	cout << contactInfo_.address_ << "\n" <<
		contactInfo_.email_ << "\n" <<
		contactInfo_.phoneNumber_;
	cout << "\n Legal form: " << legalForm_;
	cout << "\n Registration number: " << registrationNumber_;
	cout << "\n Id: " << id_;
}


bool LegalEntity::checkPhoneNumber(const string& number) {
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
bool LegalEntity::checkEmail(const string& email) {
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
bool LegalEntity::checkAddress(const string& address) {
	regex addressRegex("^St\. [A-Za-z\s]+, \d+$");
		try {
			if (!regex_match(address, addressRegex)) {
				throw invalid_argument("Invalid input");
			}
			return true;
		}
		catch (invalid_argument& arg) {
			cout << "\n" << arg.what() << "\n";
			return false;
		}
}


size_t LegalEntity::idCounter_ = 0;