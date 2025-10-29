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

static string securelyInputWord(const string& prompt) {
    while (true) {
        try {
            return safeInputWord(prompt);
        }
        catch (const InputValidationError& e) {
            cout << "Invalid argument: " << e.what() << ". Please try again.\n";
        }
        catch (const out_of_range& e) {
            cout << "Value out of range: " << e.what() << ". Please try again.\n";
        }
    }
}

static int securelyInputPositiveInt(const string& prompt) {
    while (true) {
        try {
            return safePositiveInputInt(prompt);
        }
        catch (const InputValidationError& e) {
            cout << "Invalid argument: " << e.what() << ". Please try again.\n";
        }
        catch (const out_of_range& e) {
            cout << "Value out of range: " << e.what() << ". Please try again.\n";
        }
    }
}

static int securelyInputInt(const string& prompt) {
    while (true) {
        try {
            return safeInputInt(prompt);
        }
        catch (const InputValidationError& e) {
            cout << "Invalid argument: " << e.what() << ". Please try again.\n";
        }
        catch (const out_of_range& e) {
            cout << "Value out of range: " << e.what() << ". Please try again.\n";
        }
    }
}

static int securelyInputPositiveFloat(const string& prompt) {
    while (true) {
        try {
            return safePositiveInputFloat(prompt);
        }
        catch (const InputValidationError& e) {
            cout << "Invalid argument: " << e.what() << ". Please try again.\n";
        }
        catch (const out_of_range& e) {
            cout << "Value out of range: " << e.what() << ". Please try again.\n";
        }
    }
}

void Entrepreneur::input() {
    cout << "Enter entrepreneur data:" << endl;
    licenseNumber = securelyInputPositiveInt("Enter license number: ");
    regAddress = securelyInputWord("Enter registration address: ");
    taxID = securelyInputPositiveInt("Enter tax ID: ");

    while (true) {
        try {
            int count = securelyInputInt("How many tax payments do you want to add? ");
            if (count < 0) {
                throw InputValidationError("Number of tax payments cannot be negative");
            }
            for (int i = 0; i < count; ++i) {
                cout << "Payment " << i + 1 << ":\n";
                string date = securelyInputWord("Date: ");
                float amount = securelyInputPositiveFloat("Amount: ");
                AddTaxPayment(date, amount);
            }
            break;
        }
        catch (InputValidationError& e) {
            cout << "Invalid argument: " << e.what() << ". Please try again.\n";
        }
    }
}

void Entrepreneur::editLicense() {
    int newLicense = securelyInputPositiveInt("Enter new license number: ");
    setLicenseNumber(newLicense);
}

void Entrepreneur::editRegAddress() {
    string newAddress = securelyInputWord("Enter new registration address: ");
    setRegAddress(newAddress);
}

void Entrepreneur::editTaxID() {
    int newTaxID = securelyInputPositiveInt("Enter new taxpayer ID: ");
    setTaxID(newTaxID);
}

void Entrepreneur::editTaxPaymentEdit() {
    int taxSize = getTaxPaymentSize();
    if (taxSize == 0) {
        cout << "There is nothing to edit, the list is empty." << endl;
        return;
    }

    while (true) {
        try {
            int paymentNum = securelyInputPositiveInt("Enter payment number to edit: ");
            if (paymentNum > taxSize) {
                throw InputValidationError("Number must be smaller size : '" + to_string(paymentNum) + "'");
            }
                string date = securelyInputWord("Enter new date: ");
                float amount = securelyInputPositiveFloat("Enter new amount: ");

                editTaxPayment(paymentNum - 1, date, amount);
                cout << "Payment updated." << endl;
                break;
        }
        catch (InputValidationError& e) {
            cout << "Invalid argument: " << e.what() << ". Please try again.\n";
        }
    }
    
}

void Entrepreneur::editTaxPaymentAdd() {
    string date = securelyInputWord("Enter tax payment date: ");
    float amount = securelyInputPositiveFloat("Enter tax amount: ");
    AddTaxPayment(date, amount);
    cout << "Tax payment added." << endl;
}

void Entrepreneur::editTaxPaymentDelete() {
    int taxSize = getTaxPaymentSize();
    if (taxSize == 0) {
        cout << "There is nothing to delete, the list is empty." << endl;
        return;
    }

    while (true) {
        try {
            int paymentNum = securelyInputPositiveInt("Enter payment number to delete: ");
            if (paymentNum > taxSize) {
                throw InputValidationError("Number must be smaller size : '" + to_string(paymentNum) + "'");
            }
            removeTaxPayment(paymentNum - 1);
            cout << "Payment deleted." << endl;
            break;
        }
        catch (InputValidationError& e) {
            cout << "Invalid argument: " << e.what() << ". Please try again.\n";
        }
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

        int action = securelyInputInt("Choice: ");

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

        int subChoice = securelyInputInt("Choice:");
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