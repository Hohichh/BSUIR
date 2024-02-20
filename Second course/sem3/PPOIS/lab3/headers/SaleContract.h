#pragma once
#include "Entity.h"
#include<string>
using namespace std;

class SaleContract {
private:
    static size_t counter_;
    size_t contractNumber_;
    RealEstate* realEsateObject_;
    Entity* owner_;
    Entity* buyer_;
    double salePrice_;
    string saleConditions_;
    bool ownerSign_;
    bool buyerSign_;

public:
  
    SaleContract();
    SaleContract(RealEstate* realEsateObject,
        Entity* owner,
        Entity* buyer,
        double salePrice = 0,
        const string& saleConditions = "---",
        bool ownerSign = false,
        bool buyerSign = false);

    size_t getContractNumber() const;

    RealEstate* getRealEsateObject() const;
    void setRealEsateObject(RealEstate* realEsateObject);

    Entity* getOwner() const;
    void setOwner(Entity* owner);

    Entity* getBuyer() const;
    void setBuyer(Entity* buyer);

    double getSalePrice() const;
    void setSalePrice(double salePrice);

    string getSaleConditions() const;
    void setSaleConditions(const string& saleConditions);

    bool getOwnerSign() const;
    void setOwnerSign(bool ownerSign);

    bool getBuyerSign() const;
    void setBuyerSign(bool buyerSign);

    void showInfo() const;

    bool operator==(const SaleContract& other) const;
};