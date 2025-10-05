#pragma once
#include "Entrepreneur.h"
#include "Tourist.h"
#include <string>
using namespace std;

class Canoe : public Entrepreneur, public Tourist {
private:
    string* shopAddress;
    int shopSize;
    int shopCapacity;

    void editEntrepreneurName();
    void editEntrepreneurSurname();
    void editEntrepreneurPatronymic();
    void editEntrepreneurBirthYear();
    void editEntrepreneurLicense();
    void editEntrepreneurRegAddress();
    void editEntrepreneurTaxID();
    void editEntrepreneurTaxPayments();
    void editEntrepreneurTaxPaymentEdit();
    void editEntrepreneurTaxPaymentAdd();
    void editEntrepreneurTaxPaymentDelete();
    void editEntrepreneurDetails();

    void editTouristName();
    void editTouristSurname();
    void editTouristPatronymic();
    void editTouristBirthYear();
    void editTouristPassport();
    void editTouristBorderCrossings();
    void editTouristBorderCrossingEdit();
    void editTouristBorderCrossingAdd();
    void editTouristBorderCrossingDelete();
    void editTouristDetails();

    void editShopAddressAdd();
    void editShopAddressDelete();
    void editShopAddresses();

public:
    Canoe();
    Canoe(const Canoe& other);
    Canoe& operator=(const Canoe& other);
    ~Canoe();

    int getShopSize() const;
    int getShopCapacity() const;

    void AddShopAddress(const string& Address);
    void resizeShopArray();
    void displayCanoe();
    void inputCanoe();
    void edit(int number); 
};