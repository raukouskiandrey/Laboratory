#include "Entrepreneur.h"
#include"Utilities.h"
#include <iostream>
using namespace std;

Entrepreneur::Entrepreneur() {
    tax = new taxPayment[capacity];
}

Entrepreneur::Entrepreneur(const Entrepreneur& other) : Human(other), licenseNumber(other.licenseNumber), regAddress(other.regAddress), taxID(other.taxID), size(other.size), capacity(other.capacity) {
    tax = new taxPayment[capacity];
    for (int i = 0; i < size; i++) {
        tax[i] = other.tax[i];
    }
}

Entrepreneur& Entrepreneur::operator=(const Entrepreneur& other) {
    if (this != &other) {
        Human::operator=(other);
        licenseNumber = other.licenseNumber;
        regAddress = other.regAddress;
        taxID = other.taxID;
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

Entrepreneur::~Entrepreneur() {
    delete[] tax;
}

int Entrepreneur::getLicenseNumber() const { return licenseNumber; }
string Entrepreneur::getRegAddress() const { return regAddress; }
int Entrepreneur::getTaxID() const { return taxID; }
int Entrepreneur::getSize() const { return size; }
int Entrepreneur::getCapacity() const { return capacity; }

void Entrepreneur::setLicenseNumber(int lnumb) { licenseNumber = lnumb; }
void Entrepreneur::setRegAddress(string_view regadd) { regAddress = regadd; }
void Entrepreneur::setTaxID(int taxid) { taxID = taxid; }

void Entrepreneur::editTaxPayment(int index, string_view date, float amount) {
    if (index >= 0 && index < size) {
        tax[index].taxDate = date;
        tax[index].taxAmount = amount;
    }
}

taxPayment Entrepreneur::getTaxPayment(int index) const {
    if (index >= 0 && index < size) {
        return tax[index];
    }
    return taxPayment();
}

void Entrepreneur::AddTaxPayment(string_view date, float amount) {
    if (size >= capacity) {
        resizeTaxArray();
    }
    tax[size].taxDate = date;
    tax[size].taxAmount = amount;
    size++;
}

void Entrepreneur::resizeTaxArray() {
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

void Entrepreneur::displayEntrepreneur() const {
    cout << "\n Entrepreneur information " << endl;
    displayHuman();
    cout << "License number: " << licenseNumber << endl
        << "Registration address: " << regAddress << endl
        << "Tax ID: " << taxID << endl;

    if (size > 0 && tax != nullptr) {
        cout << "Tax payments:" << endl;
        for (int i = 0; i < size; i++) {
            cout << "  Date: " << tax[i].taxDate
                << ", Amount: " << tax[i].taxAmount << endl;
        }
    }
    else {
        cout << "Tax payments: none" << endl;
    }
}

void Entrepreneur::inputEntrepreneur() {
    cout << "Enter entrepreneur data:" << endl;
    inputHuman();
    cout << "Enter license number: ";
    cin >> licenseNumber;
    cout << "Enter registration address: ";
    cin.ignore();
    getline(cin, regAddress);
    cout << "Enter tax ID: ";
    cin >> taxID;

    int count;
    cout << "How many tax payments do you want to add? ";
    cin >> count;
    cin.ignore();
    for (int i = 0; i < count; ++i) {
        string date;
        cout << "Payment " << i + 1 << ":\n";
        cout << "  Date: ";
        getline(cin, date);

        float amount = safePositiveInputFloat("  Amount: ");
        AddTaxPayment(date, amount);
    }
}

void Entrepreneur::removeTaxPayment(int index) {
    if (index < 0 || index >= size) return;

    for (int i = index; i < size - 1; i++) {
        tax[i] = tax[i + 1];
    }
    size--;
}