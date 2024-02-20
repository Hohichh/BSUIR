#include "Entity.h"
#include "SaleContract.h"
#include "RentalContract.h"


Entity::Entity(const string& type): type_(type) {}


string Entity::getType() const{
	return type_;
}
void Entity::setType(const string& type){
	type_ = type;
}

vector <RealEstate*> Entity::getOwnership() const{
	return ownership;
}
void Entity::setOwnership(vector <RealEstate*> ownership){
	this->ownership = ownership;
}
void Entity::addOwnObj(RealEstate* ownObj){
	ownership.emplace_back(ownObj);
}
void Entity::delOwnObj(RealEstate* ownObj){
	ownership.erase(remove_if(ownership.begin(), ownership.end(),[ownObj](RealEstate* currentObj){
		return currentObj == ownObj;
		}), ownership.end());
}
void Entity::delOwnObj(int index){
	if (index > -1 && index < ownership.size()) {
		ownership.erase(ownership.begin() + index);
	}
}

vector <const RealEstate*> Entity::getRentship() const{
	return rentship;
}
void Entity::setRentship(vector <const RealEstate*> rentship){
	this->rentship = rentship;
}
void Entity::addRentObj(const RealEstate* rentObj){
	rentship.emplace_back(rentObj);
}
void Entity::delRentObj(const RealEstate* rentObj){
	rentship.erase(remove_if(rentship.begin(), rentship.end(), [rentObj](const RealEstate* currentObj) {
		return currentObj == rentObj;
		}), rentship.end());
}
void Entity::delRentObj(int index){
	if (index > -1 && index < rentship.size()) {
		rentship.erase(rentship.begin() + index);
	}
}

const vector<const SaleContract*>& Entity::getSaleContracts() const {
	return saleContracts;
}
void Entity::setSaleContracts(const vector<const SaleContract*>& newContracts) {
	saleContracts = newContracts;
}
void Entity::addSaleContract(const SaleContract* contract) {
	saleContracts.push_back(contract);
}
void Entity::removeSaleContract(const SaleContract* contract) {
	saleContracts.erase(std::remove(saleContracts.begin(), saleContracts.end(), contract), saleContracts.end());
}
void Entity::removeSaleContract(int index) {
	if (index > -1 && index < saleContracts.size()) {
		saleContracts.erase(saleContracts.begin() + index);
	}
}

const vector<const RentalContract*>& Entity::getRentalContracts() const {
	return rentalContracts;
}
void Entity::setRentalContracts(const vector<const RentalContract*>& newContracts) {
	rentalContracts = newContracts;
}
void Entity::addRentalContract(const RentalContract* contract) {
	rentalContracts.push_back(contract);
}
void Entity::removeRentalContract(const RentalContract* contract) {
	rentalContracts.erase(std::remove(rentalContracts.begin(),
		rentalContracts.end(), contract), rentalContracts.end());
}
void Entity::removeRentalContract(int index) {
	if (index > -1 && index < rentalContracts.size()) {
		rentalContracts.erase(rentalContracts.begin() + index);
	}
}