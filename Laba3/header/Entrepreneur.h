#pragma once
#include "Human.h"
#include "TaxPaymentList.h"
#include <string>

class Entrepreneur : public virtual Human {
private:
    int licenseNumber = 1;
    std::string regAddress = "Minsk";
    int taxID = 1;
    TaxPaymentList taxPayments; 

public:
    Entrepreneur();
    Entrepreneur(const Entrepreneur& other);
    Entrepreneur& operator=(const Entrepreneur& other);
    ~Entrepreneur();

    int getLicenseNumber() const;
    std::string getRegAddress() const;
    int getTaxID() const;
    int getTaxPaymentSize() const; 

    void setLicenseNumber(int lnumb);
    void setRegAddress(std::string_view regadd);
    void setTaxID(int taxid);

    void editLicense();
    void editRegAddress();
    void editTaxID();
    void editTaxPayments();
    void editTaxPaymentEdit();
    void editTaxPaymentAdd();
    void editTaxPaymentDelete();
    void editEntrepreneurDetails();

    void editTaxPayment(int index, std::string_view date, float amount);
    taxPayment getTaxPayment(int index) const;

    void AddTaxPayment(std::string_view date, float amount);
    void removeTaxPayment(int index);

    void display() const override;
    void input() override;
};