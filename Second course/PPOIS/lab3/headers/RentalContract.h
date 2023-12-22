#pragma once
#include<string>
using namespace std;


class Entity;
class RealEstate;

class RentalContract {
public:
    static size_t counter_;
    size_t contractNumber_;
    RealEstate* realEsateObject_;
    Entity* owner_;
    Entity* renter_;
    double rent_;
    string rentPeriod_;
    string rentalConditions_;
    string restrictions_;
    bool ownerSign_;
    bool renterSign_;
public:
    RentalContract(RealEstate* realEsateObject,
        Entity* owner,
        Entity* renter,
        double rent = 0,
        const string& rentPeriod = "---",
        const string& rentalConditions = "---",
        const string& restrictions = "---",
        bool ownerSign = false,
        bool renterSign = false);
    RentalContract();

    size_t getContractNumber() const;

    RealEstate* getRealEsateObject() const;
    void setRealEsateObject(RealEstate* realEsateObject);
      
    Entity* getOwner() const;
    void setOwner(Entity* owner);

    Entity* getRenter() const;
    void setRenter(Entity* renter);

    double getRent() const;
    void setRent(double rent);

    string getRentPeriod() const;
    void setRentPeriod(const string& rentPeriod);

    string getRentalConditions() const;
    void setRentalConditions(const string& rentalConditions);

    string getRestrictions() const;
    void setRestrictions(const string& restrictions);

    bool getOwnerSign() const;
    void setOwnerSign(bool ownerSign);

    bool getRenterSign() const;
    void setRenterSign(bool renterSign);

    void showInfo() const;

    bool operator==(const RentalContract& other)const;
};