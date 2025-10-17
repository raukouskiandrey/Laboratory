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

void Entrepreneur::display() const {
    cout << "\n Entrepreneur information " << endl;
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

void Entrepreneur::input() {
    cout << "Enter entrepreneur data:" << endl;
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

void Entrepreneur::editLicense() {
    int newLicense;
    cout << "Enter new license number: ";
    cin >> newLicense;
    setLicenseNumber(newLicense);
}

void Entrepreneur::editRegAddress() {
    string newAddress;
    cout << "Enter new registration address: ";
    cin.ignore();
    getline(cin, newAddress);
    setRegAddress(newAddress);
}

void Entrepreneur::editTaxID() {
    int newTaxID;
    cout << "Enter new taxpayer ID: ";
    cin >> newTaxID;
    setTaxID(newTaxID);
}

void Entrepreneur::editTaxPaymentEdit() {
    int taxSize = Entrepreneur::getSize();
    if (taxSize == 0) {
        cout << "There is nothing to edit, the list is empty." << endl;
        return;
    }

    int paymentNum = safeInputInt("Enter payment number to edit: ");
    if (paymentNum > 0 && paymentNum <= taxSize) {
        string date;
        cout << "Enter new date: ";
        cin.ignore();
        getline(cin, date);

        float amount = safePositiveInputFloat("Enter new amount: ");

        Entrepreneur::editTaxPayment(paymentNum - 1, date, amount);
        cout << "Payment updated." << endl;
    }
    else {
        cout << "Invalid payment number!" << endl;
    }
}

void Entrepreneur::editTaxPaymentAdd() {
    string date;
    cout << "Enter tax payment date: ";
    cin.ignore();
    getline(cin, date);

    float amount = safePositiveInputFloat("Enter tax amount: ");
    AddTaxPayment(date, amount);
    cout << "Tax payment added." << endl;
}

void Entrepreneur::editTaxPaymentDelete() {
    int taxSize = Entrepreneur::getSize();
    if (taxSize == 0) {
        cout << "There is nothing to delete, the list is empty." << endl;
        return;
    }

    int paymentNum = safeInputInt("Enter payment number to delete: ");
    if (paymentNum > 0 && paymentNum <= taxSize) {
        Entrepreneur::removeTaxPayment(paymentNum - 1);
        cout << "Payment deleted." << endl;
    }
    else {
        cout << "Invalid payment number!" << endl;
    }
}

void Entrepreneur::editTaxPayments() {
    while (true) {
        if (int taxSize = Entrepreneur::getSize(); taxSize > 0) {
            cout << "Existing tax payments:" << endl;
            for (int i = 0; i < taxSize; i++) {
                taxPayment payment = Entrepreneur::getTaxPayment(i);
                cout << i + 1 << ". Date: " << payment.taxDate
                    << ", Amount: " << payment.taxAmount << endl;
            }
        }

        cout << "Choose action:" << endl
            << "1 - Edit existing payment" << endl
            << "2 - Add new payment" << endl
            << "3 - Delete payment" << endl
            << "4 - Return" << endl;

        int action = safeInputInt("Choice: ");

        switch (action) {
        case 1:
            editTaxPaymentEdit();
            break;
        case 2:
            editTaxPaymentAdd();
            break;
        case 3:
            editTaxPaymentDelete();
            break;
        case 4:
            return;
        default:
            cout << "Invalid choice." << endl;
        }
    }
}

void Entrepreneur::editEntrepreneurDetails() {
    while (true) {
        cout << endl << "Change entrepreneur data: " << endl
            << "1 - Change license number" << endl
            << "2 - Change registration address" << endl
            << "3 - Change taxpayer ID" << endl
            << "4 - Change tax payment data" << endl
            << "5 - Return" << endl;

        int subChoice = safeInputInt("Choice:");
        switch (subChoice) {
        case 1:
            editLicense();
            break;
        case 2:
            editRegAddress();
            break;
        case 3:
            editTaxID();
            break;
        case 4:
            editTaxPayments();
            break;
        case 5:
            return;
        default:
            cout << "Invalid choice." << endl;
        }
    }
}