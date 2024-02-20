#include "Deal.h"
#include <algorithm>

Deal::Deal(): dealNumber_(counter_++) {}


size_t Deal::getDealNumber() const {
	return dealNumber_;
}
void Deal::setDealNumber(size_t dealNumber) {
	dealNumber_ = dealNumber;
}


vector<SaleContract> Deal::getSaleContracts() const {
	return saleContracts;
}
void Deal::setSaleContracts(const vector<SaleContract>& otherSaleContracts) {
	saleContracts = otherSaleContracts;
}


vector<RentalContract> Deal::getRentalContracts() const {
	return rentalContracts;
}
void Deal::setRentalContracts(const vector<RentalContract>& otherRentalContracts) {
	rentalContracts = otherRentalContracts;
}


SaleContract* Deal::createSaleContract(Entity* owner, Entity* buyer, RealEstate* realEstate) {
	SaleContract contract(realEstate, owner, buyer);
	saleContracts.emplace_back(contract);
	SaleContract* contractPtr = &saleContracts.back();
	owner->addSaleContract(contractPtr);
	buyer->addSaleContract(contractPtr);
	return contractPtr;
}
RentalContract* Deal::createRentalContract(Entity* owner, Entity* renter, RealEstate* realEstate){
	RentalContract contract(realEstate, owner, renter);
	rentalContracts.emplace_back(contract);
	RentalContract* contractPtr = &rentalContracts.back();
	owner->addRentalContract(contractPtr);
	renter->addRentalContract(contractPtr);
	return contractPtr;
}

void Deal::setConditions(double salePrice, const string& saleConditions, SaleContract& contract) {
	for (auto& contractIt : saleContracts) {
		if (&contractIt == &contract) {
			contractIt.setSalePrice(salePrice);
			contractIt.setSaleConditions(saleConditions);
		}
	}
}
void Deal::setConditions(double rent, const string& rentPeriod,
	const string& rentalConditions, const string& restrictions, RentalContract& contract) {
	for (auto& contractIt : rentalContracts) {
		if (&contractIt == &contract) {
			contractIt.setRent(rent);
			contractIt.setRentPeriod(rentPeriod);
			contractIt.setRentalConditions(rentalConditions);
			contractIt.setRestrictions(restrictions);
		}
	}
}

void Deal::signContract(SaleContract& contract) {
	for (auto& contractIt : saleContracts) {
		if (&contractIt == &contract) {
			contract.setOwnerSign(true);
			contract.setBuyerSign(true);
			contract.getBuyer()->addOwnObj(contract.getRealEsateObject());
			contract.getOwner()->delOwnObj(contract.getRealEsateObject());
		}
	}
}
void Deal::signContract(RentalContract& contract) {
	for (auto& contractIt : rentalContracts) {
		if (&contractIt == &contract) {
			contract.setOwnerSign(true);
			contract.setRenterSign(true);
			contract.getRenter()->addRentObj(contract.getRealEsateObject());
		}
	}
}



size_t Deal::counter_ = 0;