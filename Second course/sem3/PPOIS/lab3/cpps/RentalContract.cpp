#include "RentalContract.h"
#include "PhysicalEntity.h"
#include "LegalEntity.h"

RentalContract::RentalContract(RealEstate* realEsateObject,
    Entity* owner,
    Entity* renter,
    double rent, 
    const string& rentPeriod,
    const string& rentalConditions,
    const string& restrictions,
    bool ownerSign,
    bool renterSign)
    : contractNumber_(counter_++),
    realEsateObject_(realEsateObject),
    owner_(owner),
    renter_(renter), 
    rent_(rent),
    rentPeriod_(rentPeriod), 
    rentalConditions_(rentalConditions), 
    restrictions_(restrictions),
    ownerSign_(ownerSign),
    renterSign_(renterSign) {}

RentalContract::RentalContract():contractNumber_(counter_++),
    realEsateObject_(nullptr),
    owner_(nullptr),
    renter_(nullptr),
    rent_(0),
    rentPeriod_("---"),
    rentalConditions_("---"),
    restrictions_("---"),
    ownerSign_(false),
    renterSign_(false) {}

size_t RentalContract::getContractNumber() const {
    return contractNumber_;
}

RealEstate* RentalContract::getRealEsateObject() const {
    return realEsateObject_;
}
void RentalContract::setRealEsateObject(RealEstate* realEsateObject) {
    realEsateObject_ = realEsateObject;
}


Entity* RentalContract::getOwner() const {
    return owner_; 
}
void RentalContract::setOwner(Entity* owner) {
    owner_ = owner; 
}

Entity* RentalContract::getRenter() const { 
    return renter_; 
}
void RentalContract::setRenter(Entity* renter) {
    renter_ = renter; 
}

double RentalContract::getRent() const { 
    return rent_; 
}
void RentalContract::setRent(double rent) {
    rent_ = rent;
}

string RentalContract::getRentPeriod() const {
    return rentPeriod_; 
}
void RentalContract::setRentPeriod(const string& rentPeriod) {
    rentPeriod_ = rentPeriod; 
}

string RentalContract::getRentalConditions() const { 
    return rentalConditions_; 
}
void RentalContract::setRentalConditions(const string& rentalConditions) {
    rentalConditions_ = rentalConditions; 
}

string RentalContract::getRestrictions() const {
    return restrictions_; 
}
void RentalContract::setRestrictions(const string& restrictions) { 
    restrictions_ = restrictions; 
}

bool RentalContract::getOwnerSign() const {
    return ownerSign_;
}
void RentalContract::setOwnerSign(bool ownerSign) {
    ownerSign_ = ownerSign;
}

bool RentalContract::getRenterSign() const {
    return ownerSign_;
}
void RentalContract::setRenterSign(bool renterSign) {
    renterSign_ = renterSign;
}

void RentalContract::showInfo() const {
    cout << "Owner: ";
    if (PhysicalEntity* ownerPhysicalEntity = dynamic_cast<PhysicalEntity*>(owner_)) {
        cout << ownerPhysicalEntity->getFirstName() << " " <<
            ownerPhysicalEntity->getMiddleName() << " " <<
            ownerPhysicalEntity->getSurname() << endl;
    }
    else if (LegalEntity* ownerLegalEntity = dynamic_cast<LegalEntity*>(owner_)) {
        cout << ownerLegalEntity->getName() << endl;
    }
    cout << "Buyer: ";
    if (PhysicalEntity* renterPhysicalEntity = dynamic_cast<PhysicalEntity*>(renter_)) {
        cout << renterPhysicalEntity->getFirstName() << " " <<
            renterPhysicalEntity->getMiddleName() << " " <<
            renterPhysicalEntity->getSurname() << endl;
    }
    else if (LegalEntity* renterLegalEntity = dynamic_cast<LegalEntity*>(renter_)) {
        cout << renterLegalEntity->getName() << endl;
    }
    cout << "Rent: " << rent_ << 
        "\nRent period: " << rentPeriod_ << 
        "\nRental conditions: " << rentalConditions_ << 
        "\nRestrictions: " << restrictions_ << endl;
}

bool RentalContract::operator==(const RentalContract& other) const{
    return contractNumber_ == other.contractNumber_;
}

size_t RentalContract::counter_ = 0;
