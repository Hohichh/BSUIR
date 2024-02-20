#pragma once
#include <string>
#include <vector>
#include "RealEstate.h"


using namespace std;

class SaleContract;
class RentalContract;

struct ContactInfo {
	string phoneNumber_;
	string email_;
};

class Entity abstract{
private:

	string type_;
	vector <RealEstate*> ownership;
	vector <const RealEstate*> rentship;

	vector <const SaleContract*> saleContracts;
	vector <const RentalContract*> rentalContracts;
public:
	Entity(const string& type);

	string getType() const;
	void setType(const string& type);

	vector <RealEstate*> getOwnership() const;
	void setOwnership(vector <RealEstate*> ownership);
	void addOwnObj(RealEstate* ownObj);
	void delOwnObj(RealEstate* ownObj);
	void delOwnObj(int index);

	vector <const RealEstate*> getRentship() const;
	void setRentship(vector <const RealEstate*> rentship);
	void addRentObj(const RealEstate* rentObj);
	void delRentObj(const RealEstate* rentObj);
	void delRentObj(int index);

	const vector<const SaleContract*>& getSaleContracts() const;
	void setSaleContracts(const vector<const SaleContract*>& newContracts);
	void addSaleContract(const SaleContract* contract);
	void removeSaleContract(const SaleContract* contract);
	void removeSaleContract(int index);

	const vector<const RentalContract*>& getRentalContracts() const;
	void setRentalContracts(const vector<const RentalContract*>& newContracts);
	void addRentalContract(const RentalContract* contract);
	void removeRentalContract(const RentalContract* contract);
	void removeRentalContract(int index);

	virtual void showInfo() const = 0;
};