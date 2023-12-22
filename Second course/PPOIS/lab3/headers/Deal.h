#pragma once
#include "LegalEntity.h"
#include "PhysicalEntity.h"
#include "RealEstate.h"
#include "SaleContract.h"
#include "RentalContract.h"

using namespace std;

class Deal {
public:
	static size_t counter_;
	size_t dealNumber_;
	vector <SaleContract> saleContracts;
	vector <RentalContract> rentalContracts;

public: 
	Deal();

	size_t getDealNumber() const;
	void setDealNumber(size_t dealNumber);

	vector<SaleContract> getSaleContracts() const;
	void setSaleContracts(const vector<SaleContract>& saleContracts);

	vector<RentalContract> getRentalContracts() const;
	void setRentalContracts(const vector<RentalContract>& rentalContracts);


	void createSaleContract(Entity* owner, Entity* buyer, RealEstate* realEstate);
	void createRentalContract(Entity* owner, Entity* renter, RealEstate* realEstate);

	void setConditions(double salePrice, const string& saleConditions, SaleContract& contract);
	void setConditions(double rent, const string& rentPeriod, 
		const string& rentalConditions,const string& restrictions, RentalContract& contract);

	void signContract(SaleContract& contract);
	void signContract(RentalContract& contract);
};