#pragma once
#include <string>

struct taxPayment {
    std::string taxDate;
    float taxAmount;
};

class TaxPaymentList {
private:
    taxPayment* tax = nullptr;
    int size = 0;
    int capacity = 3;

public:
    TaxPaymentList();
    TaxPaymentList(const TaxPaymentList& other);
    TaxPaymentList& operator=(const TaxPaymentList& other);
    ~TaxPaymentList();

    int getSize() const;
    int getCapacity() const;

    void editTaxPayment(int index, std::string_view date, float amount);
    taxPayment getTaxPayment(int index) const;

    void AddTaxPayment(std::string_view date, float amount);
    void removeTaxPayment(int index);
    void resizeTaxArray();
};