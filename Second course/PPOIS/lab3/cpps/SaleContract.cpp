#include "SaleContract.h"
#include "PhysicalEntity.h"
#include "LegalEntity.h"


SaleContract::SaleContract()
    : contractNumber_(counter_++),
    realEsateObject_(nullptr),
    owner_(nullptr),
    buyer_(nullptr), 
    salePrice_(0), 
    saleConditions_("---"),
    ownerSign_(false),
    buyerSign_(false) {}

SaleContract::SaleContract(RealEstate* realEsateObject,
    Entity* owner,
    Entity* buyer, 
    double salePrice, 
    const string& saleConditions,
    bool ownerSign,
    bool buyerSign):
    contractNumber_(counter_++),
    realEsateObject_(realEsateObject),
    owner_(owner), 
    buyer_(buyer), 
    salePrice_(salePrice), 
    saleConditions_(saleConditions),
    ownerSign_(ownerSign),
    buyerSign_(buyerSign) {}


size_t SaleContract::getContractNumber() const {
    return contractNumber_;
}

RealEstate* SaleContract::getRealEsateObject() const {
    return realEsateObject_;
}
void SaleContract::setRealEsateObject(RealEstate* realEsateObject) {
    realEsateObject_ = realEsateObject;
}

Entity* SaleContract::getOwner() const { 
    return owner_; 
}
void SaleContract::setOwner(Entity* owner) {
    owner_ = owner; 
}

Entity* SaleContract::getBuyer() const { 
    return buyer_; 
}
void SaleContract::setBuyer(Entity* buyer) { 
    buyer_ = buyer;
}

double SaleContract::getSalePrice() const {
    return salePrice_; 
}
void SaleContract::setSalePrice(double salePrice) { 
    salePrice_ = salePrice;
}

string SaleContract::getSaleConditions() const { 
    return saleConditions_;
}
void SaleContract::setSaleConditions(const string& saleConditions) {
    saleConditions_ = saleConditions;
}

bool SaleContract::getOwnerSign() const {
    return ownerSign_;
}
void SaleContract::setOwnerSign(bool ownerSign) {
    ownerSign_ = ownerSign;
}

bool SaleContract::getBuyerSign() const {
    return buyerSign_;
}
void SaleContract::setBuyerSign(bool buyerSign) {
    buyerSign_ = buyerSign;
}

void SaleContract::showInfo() const {
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
    if (PhysicalEntity* buyerPhysicalEntity = dynamic_cast<PhysicalEntity*>(buyer_)) {
        cout << buyerPhysicalEntity->getFirstName() << " " <<
            buyerPhysicalEntity->getMiddleName() << " " <<
            buyerPhysicalEntity->getSurname() << endl;
    }
    else if (LegalEntity* buyerLegalEntity = dynamic_cast<LegalEntity*>(buyer_)) {
        cout << buyerLegalEntity->getName() << endl;
    }
    cout << "Sale price: " << salePrice_ << 
        "\nSale conditions: " << saleConditions_ << endl;
}

bool SaleContract::operator==(const SaleContract& other) const{
    return contractNumber_ == other.contractNumber_;
}

size_t SaleContract::counter_ = 0;
