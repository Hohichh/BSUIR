#pragma once
#include "Entity.h"


	struct LegalEntityContactInfo : ContactInfo {
		string address_;
	};

	class LegalEntity : public Entity {
	private:
		static size_t idCounter_;
		string name_;
		LegalEntityContactInfo contactInfo_;
		string legalForm_;
		string registrationNumber_;
		size_t id_;

		bool containsOnlyLetters(const string& str);

		bool checkPhoneNumber(const string& number);
		bool checkEmail(const string& email);
		bool checkAddress(const string& address);


	public:
		LegalEntity(const string& name,
			const LegalEntityContactInfo& contactInfo,
			const string& legalForm,
			const string& registrationNumber);
		LegalEntity();

		string getName() const;
		void setName(const string& name);

		LegalEntityContactInfo getContactInfo() const;
		void setContactInfo(const LegalEntityContactInfo& contactInfo);

		string getPhoneNumber() const;
		void setPhoneNumber(const string& phoneNumber);
		string getEmail() const;
		void setEmail(const string& email);
		string getAddress() const;
		void setAddress(const string& address);

		string getLegalForm() const;
		void setLegalForm(const string& legalForm);

		string getRegistrationNumber() const;
		void setRegistrationNumber(const string& registrationNumber);

		size_t getId() const;
		void setId(size_t id);

		void showInfo() const override;
	};
