#include "TaxPaymentList.h"
#include <iostream>
using namespace std;

TaxPaymentList::TaxPaymentList() {
    tax = new taxPayment[capacity];
}

TaxPaymentList::TaxPaymentList(const TaxPaymentList& other)
    : size(other.size), capacity(other.capacity) {
    tax = new taxPayment[capacity];
    for (int i = 0; i < size; i++) {
        tax[i] = other.tax[i];
    }
}

TaxPaymentList& TaxPaymentList::operator=(const TaxPaymentList& other) {
    if (this != &other) {
        size = other.size;
        capacity = other.capacity;

        delete[] tax;
        tax = new taxPayment[capacity];
        for (int i = 0; i < size; i++) {
            tax[i] = other.tax[i];
        }
    }
    return *this;
}

TaxPaymentList::~TaxPaymentList() {
    delete[] tax;
}

int TaxPaymentList::getSize() const { return size; }
int TaxPaymentList::getCapacity() const { return capacity; }

void TaxPaymentList::editTaxPayment(int index, string_view date, float amount) {
    if (index >= 0 && index < size) {
        tax[index].taxDate = date;
        tax[index].taxAmount = amount;
    }
}

taxPayment TaxPaymentList::getTaxPayment(int index) const {
    if (index >= 0 && index < size) {
        return tax[index];
    }
    return taxPayment();
}

void TaxPaymentList::AddTaxPayment(string_view date, float amount) {
    if (size >= capacity) {
        resizeTaxArray();
    }
    tax[size].taxDate = date;
    tax[size].taxAmount = amount;
    size++;
}

void TaxPaymentList::removeTaxPayment(int index) {
    if (index < 0 || index >= size) return;

    for (int i = index; i < size - 1; i++) {
        tax[i] = tax[i + 1];
    }
    size--;
}

void TaxPaymentList::resizeTaxArray() {
    int newCapacity = (capacity == 0) ? 3 : capacity * 2;
    auto newTax = new taxPayment[newCapacity];

    if (tax != nullptr && size > 0) {
        for (int i = 0; i < size; i++) {
            newTax[i] = tax[i];
        }
        delete[] tax;
    }

    tax = newTax;
    capacity = newCapacity;
}