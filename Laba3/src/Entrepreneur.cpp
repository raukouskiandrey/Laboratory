#include "Entrepreneur.h"
#include "Utilities.h"
#include <iostream>
using namespace std;

Entrepreneur::Entrepreneur() = default;

Entrepreneur::Entrepreneur(const Entrepreneur& other)
    : Human(other), licenseNumber(other.licenseNumber), regAddress(other.regAddress),
    taxID(other.taxID), taxPayments(other.taxPayments) {}

Entrepreneur& Entrepreneur::operator=(const Entrepreneur& other) {
    if (this != &other) {
        Human::operator=(other);
        licenseNumber = other.licenseNumber;
        regAddress = other.regAddress;
        taxID = other.taxID;
        taxPayments = other.taxPayments;
    }
    return *this;
}

Entrepreneur::~Entrepreneur() = default;

int Entrepreneur::getLicenseNumber() const { return licenseNumber; }
string Entrepreneur::getRegAddress() const { return regAddress; }
int Entrepreneur::getTaxID() const { return taxID; }
int Entrepreneur::getTaxPaymentSize() const { return taxPayments.getSize(); }

void Entrepreneur::setLicenseNumber(int lnumb) { licenseNumber = lnumb; }
void Entrepreneur::setRegAddress(string_view regadd) { regAddress = regadd; }
void Entrepreneur::setTaxID(int taxid) { taxID = taxid; }

void Entrepreneur::editTaxPayment(int index, string_view date, float amount) {
    taxPayments.editTaxPayment(index, date, amount);
}

taxPayment Entrepreneur::getTaxPayment(int index) const {
    return taxPayments.getTaxPayment(index);
}

void Entrepreneur::AddTaxPayment(string_view date, float amount) {
    taxPayments.AddTaxPayment(date, amount);
}

void Entrepreneur::removeTaxPayment(int index) {
    taxPayments.removeTaxPayment(index);
}

void Entrepreneur::display() const {
    cout << "\n Entrepreneur information " << endl;
    cout << "License number: " << licenseNumber << endl
        << "Registration address: " << regAddress << endl
        << "Tax ID: " << taxID << endl;

    if (taxPayments.getSize() > 0) {
        cout << "Tax payments:" << endl;
        for (int i = 0; i < taxPayments.getSize(); i++) {
            taxPayment payment = taxPayments.getTaxPayment(i);
            cout << "  Date: " << payment.taxDate
                << ", Amount: " << payment.taxAmount << endl;
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
    int taxSize = getTaxPaymentSize();
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

        editTaxPayment(paymentNum - 1, date, amount);
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
    int taxSize = getTaxPaymentSize();
    if (taxSize == 0) {
        cout << "There is nothing to delete, the list is empty." << endl;
        return;
    }

    int paymentNum = safeInputInt("Enter payment number to delete: ");
    if (paymentNum > 0 && paymentNum <= taxSize) {
        removeTaxPayment(paymentNum - 1);
        cout << "Payment deleted." << endl;
    }
    else {
        cout << "Invalid payment number!" << endl;
    }
}

void Entrepreneur::editTaxPayments() {
    while (true) {
        int taxSize = getTaxPaymentSize();
        if (taxSize > 0) {
            cout << "Existing tax payments:" << endl;
            for (int i = 0; i < taxSize; i++) {
                taxPayment payment = getTaxPayment(i);
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