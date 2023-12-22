#pragma once
#include "Entity.h"
#include <unordered_map>


	struct FullName {
		string firstName_;
		string middleName_;
		string surname_;
	};

	struct PhysicalEntityContactInfo : ContactInfo {
		unordered_map<string, string>socialMediaLinks_;
	};

	class PhysicalEntity : public Entity {
	public:
		static size_t idCounter_;
		FullName fullName_;
		size_t id_;
		string documentType_;
		string documentId_;
		PhysicalEntityContactInfo contactInfo_;

		bool containsOnlyLetters(const string& str);

		bool checkName(const string& name);
		bool checkPhoneNumber(const string& number);
		bool checkEmail(const string& email);
	public:

		PhysicalEntity(const FullName& fullName,
			const PhysicalEntityContactInfo& contactInfo,
			string documentType,
			const string& documentId);
		PhysicalEntity();

		FullName getFullName() const;
		void setFullName(const FullName& fullName);

		string getFirstName() const;
		void setFirstName(const string& firstName);
		string getMiddleName() const;
		void setMiddleName(const string& middleName);
		string getSurname() const;
		void setSurname(const string& surname);

		size_t getId() const;
		void setId(size_t id);

		string getDocumentType() const;
		void setDocumentType(string documentType);

		string getDocumentId() const;
		void setDocumentId(const string& documentId);

		PhysicalEntityContactInfo getContactInfo() const;
		void setContactInfo(const PhysicalEntityContactInfo& contactInfo);

		string getPhoneNumber() const;
		void setPhoneNumber(const string& phoneNumber);
		string getEmail() const;
		void setEmail(const string& email);
		unordered_map<string, string> getSocialMediaLinks() const;
		void setSocialMediaLinks(const string& key, const string& value);

		void showInfo() const override;
	};

