#pragma once
#include "Human.h"
#include <string>

struct taxPayment {
    string taxDate;
    float taxAmount;
};

class Entrepreneur : public Human {
private:
    int licenseNumber = 1;
    string regAddress = "Minsk";
    int taxID = 1;
    taxPayment* tax = nullptr;
    int size = 0;
    int capacity = 3;


public:
    Entrepreneur();
    Entrepreneur(const Entrepreneur& other);
    Entrepreneur& operator=(const Entrepreneur& other);
    ~Entrepreneur();

    int getLicenseNumber() const;
    string getRegAddress() const;
    int getTaxID() const;
    int getSize() const;
    int getCapacity() const;

    void setLicenseNumber(int lnumb);
    void setRegAddress(string_view regadd);
    void setTaxID(int taxid);

    void editTaxPayment(int index, string_view date, float amount);
    taxPayment getTaxPayment(int index) const;

    void AddTaxPayment(string_view date, float amount);
    void removeTaxPayment(int index);
    void resizeTaxArray();
    void displayEntrepreneur() const;
    void inputEntrepreneur();
};