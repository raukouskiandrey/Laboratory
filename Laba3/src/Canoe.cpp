#include "Canoe.h"
#include "Application.h"
#include "Utilities.h"
#include <iostream>
using namespace std;

Canoe::Canoe() : shopAddress(nullptr), shopSize(0), shopCapacity(3) {
    shopAddress = new string[shopCapacity];
}

Canoe::Canoe(const Canoe& other) : Entrepreneur(other), Tourist(other), shopSize(other.shopSize), shopCapacity(other.shopCapacity) {
    shopAddress = new string[shopCapacity];
    for (int i = 0; i < shopSize; i++) {
        shopAddress[i] = other.shopAddress[i];
    }
}

Canoe& Canoe::operator=(const Canoe& other) {
    if (this != &other) {
        Entrepreneur::operator=(other);
        Tourist::operator=(other);
        shopSize = other.shopSize;
        shopCapacity = other.shopCapacity;

        delete[] shopAddress;
        shopAddress = new string[shopCapacity];
        for (int i = 0; i < shopSize; i++) {
            shopAddress[i] = other.shopAddress[i];
        }
    }
    return *this;
}

Canoe::~Canoe() {
    delete[] shopAddress;
}

int Canoe::getShopSize() const { return shopSize; }
int Canoe::getShopCapacity() const { return shopCapacity; }

void Canoe::AddShopAddress(string_view Address) {
    if (shopSize >= shopCapacity) {
        resizeShopArray();
    }
    shopAddress[shopSize] = string(Address);
    shopSize++;
}

void Canoe::resizeShopArray() {
    shopCapacity = (shopCapacity == 0) ? 3 : shopCapacity * 2;
    string* newShopAddress = new string[shopCapacity];
    for (int i = 0; i < shopSize; i++) {
        newShopAddress[i] = shopAddress[i];
    }
    delete[] shopAddress;
    shopAddress = newShopAddress;
}

void Canoe::displayCanoe() {
    displayEntrepreneur();
    displayTourist();

    if (shopSize == 0) {
        cout << "No purchase addresses\n";
        return;
    }
    else {
        cout << "Purchase addresses:" << endl;
        for (int i = 0; i < shopSize; i++) {
            cout << "  " << shopAddress[i] << endl;
        }
    }
}

void Canoe::inputCanoe() {
    inputEntrepreneur();
    inputTourist();

    int count;
    cout << "How many purchase addresses do you want to add? ";
    cin >> count;
    cin.ignore();

    for (int i = 0; i < count; ++i) {
        string address;
        cout << "Purchase address " << i + 1 << ": ";
        getline(cin, address);
        AddShopAddress(address);
    }
}

void Canoe::editEntrepreneurName() {
    string newName;
    cout << "Enter new name: ";
    cin.ignore();
    getline(cin, newName);
    Entrepreneur::setName(newName);
}

void Canoe::editEntrepreneurSurname() {
    string newSurname;
    cout << "Enter new surname: ";
    cin.ignore();
    getline(cin, newSurname);
    Entrepreneur::setSurname(newSurname);
}

void Canoe::editEntrepreneurPatronymic() {
    string newPatronymic;
    cout << "Enter new patronymic: ";
    cin.ignore();
    getline(cin, newPatronymic);
    Entrepreneur::setPatronymic(newPatronymic);
}

void Canoe::editEntrepreneurBirthYear() {
    int newYear;
    cout << "Enter new birth year: ";
    cin >> newYear;
    Entrepreneur::setBirthYear(newYear);
}

void Canoe::editEntrepreneurLicense() {
    int newLicense;
    cout << "Enter new license number: ";
    cin >> newLicense;
    setLicenseNumber(newLicense);
}

void Canoe::editEntrepreneurRegAddress() {
    string newAddress;
    cout << "Enter new registration address: ";
    cin.ignore();
    getline(cin, newAddress);
    setRegAddress(newAddress);
}

void Canoe::editEntrepreneurTaxID() {
    int newTaxID;
    cout << "Enter new taxpayer ID: ";
    cin >> newTaxID;
    setTaxID(newTaxID);
}

void Canoe::editEntrepreneurTaxPaymentEdit() {
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

void Canoe::editEntrepreneurTaxPaymentAdd() {
    string date;
    cout << "Enter tax payment date: ";
    cin.ignore();
    getline(cin, date);

    float amount = safePositiveInputFloat("Enter tax amount: ");
    AddTaxPayment(date, amount);
    cout << "Tax payment added." << endl;
}

void Canoe::editEntrepreneurTaxPaymentDelete() {
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

void Canoe::editEntrepreneurTaxPayments() {
    while (true) {
        if (int taxSize = Entrepreneur::getSize();taxSize > 0) {
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
            editEntrepreneurTaxPaymentEdit();
            break;
        case 2:
            editEntrepreneurTaxPaymentAdd();
            break;
        case 3:
            editEntrepreneurTaxPaymentDelete();
            break;
        case 4:
            return;
        default:
            cout << "Invalid choice." << endl;
        }
    }
}

void Canoe::editEntrepreneurDetails() {
    while (true) {
        cout << endl << "Change entrepreneur data: " << endl
            << "1 - Change name" << endl
            << "2 - Change surname" << endl
            << "3 - Change patronymic" << endl
            << "4 - Change year of birth" << endl
            << "5 - Change license number" << endl
            << "6 - Change registration address" << endl
            << "7 - Change taxpayer ID" << endl
            << "8 - Change tax payment data" << endl
            << "9 - Return" << endl;

        int subChoice = safeInputInt("Choice:");
        switch (subChoice) {
        case 1:
            editEntrepreneurName();
            break;
        case 2:
            editEntrepreneurSurname();
            break;
        case 3:
            editEntrepreneurPatronymic();
            break;
        case 4:
            editEntrepreneurBirthYear();
            break;
        case 5:
            editEntrepreneurLicense();
            break;
        case 6:
            editEntrepreneurRegAddress();
            break;
        case 7:
            editEntrepreneurTaxID();
            break;
        case 8:
            editEntrepreneurTaxPayments();
            break;
        case 9:
            return;
        default:
            cout << "Invalid choice." << endl;
        }
    }
}

void Canoe::editTouristName() {
    string newName;
    cout << "Enter new name: ";
    cin.ignore();
    getline(cin, newName);
    Tourist::setName(newName);
}

void Canoe::editTouristSurname() {
    string newSurname;
    cout << "Enter new surname: ";
    cin.ignore();
    getline(cin, newSurname);
    Tourist::setSurname(newSurname);
}

void Canoe::editTouristPatronymic() {
    string newPatronymic;
    cout << "Enter new patronymic: ";
    cin.ignore();
    getline(cin, newPatronymic);
    Tourist::setPatronymic(newPatronymic);
}

void Canoe::editTouristBirthYear() {
    int newYear;
    cout << "Enter new birth year: ";
    cin >> newYear;
    Tourist::setBirthYear(newYear);
}

void Canoe::editTouristPassport() {
    string newPassport;
    cout << "Enter new passport data: ";
    cin.ignore();
    getline(cin, newPassport);
    setPassportData(newPassport);
}

void Canoe::editTouristBorderCrossingEdit() {
    int borderSize = Tourist::getSize();
    if (borderSize == 0) {
        cout << "There is nothing to edit, the list is empty." << endl;
        return;
    }

    int crossingNum = safeInputInt("Enter crossing number to edit: ");
    if (crossingNum > 0 && crossingNum <= borderSize) {
        string date;
        string country;
        cout << "Enter new date: ";
        cin.ignore();
        getline(cin, date);
        cout << "Enter new country: ";
        getline(cin, country);

        Tourist::editBorderCross(crossingNum - 1, date, country);
        cout << "Crossing updated." << endl;
    }
    else {
        cout << "Invalid crossing number!" << endl;
    }
}

void Canoe::editTouristBorderCrossingAdd() {
    string date;
    string country;
    cout << "Enter crossing date: ";
    cin.ignore();
    getline(cin, date);
    cout << "Enter country: ";
    getline(cin, country);
    AddBorderCross(date, country);
    cout << "Border crossing added." << endl;
}

void Canoe::editTouristBorderCrossingDelete() {
    int borderSize = Tourist::getSize();
    if (borderSize == 0) {
        cout << "There is nothing to delete, the list is empty." << endl;
        return;
    }

    int crossingNum = safeInputInt("Enter crossing number to delete: ");
    if (crossingNum > 0 && crossingNum <= borderSize) {
        Tourist::removeBorderCross(crossingNum - 1);
        cout << "Crossing deleted." << endl;
    }
    else {
        cout << "Invalid crossing number!" << endl;
    }
}

void Canoe::editTouristBorderCrossings() {
    if (int borderSize = Tourist::getSize();borderSize > 0) {
        cout << "Existing border crossings:" << endl;
        for (int i = 0; i < borderSize; i++) {
            borderCrossing crossing = Tourist::getBorderCross(i);
            cout << i + 1 << ". Date: " << crossing.crossingDate
                << ", Country: " << crossing.country << endl;
        }
    }

    cout << "Choose action:" << endl
        << "1 - Edit existing crossing" << endl
        << "2 - Add new crossing" << endl
        << "3 - Delete crossing" << endl
        << "4 - Return" << endl;

    int action = safeInputInt("Choice: ");

    switch (action) {
    case 1:
        editTouristBorderCrossingEdit();
        break;
    case 2:
        editTouristBorderCrossingAdd();
        break;
    case 3:
        editTouristBorderCrossingDelete();
        break;
    case 4:
        return;
    default:
        cout << "Invalid choice." << endl;
    }
}

void Canoe::editTouristDetails() {
    while (true) {
        cout << endl << "Change tourist data: " << endl
            << "1 - Change name" << endl
            << "2 - Change surname" << endl
            << "3 - Change patronymic" << endl
            << "4 - Change year of birth" << endl
            << "5 - Change passport data" << endl
            << "6 - Change border crossing data" << endl
            << "7 - Return" << endl;

        int subChoice = safeInputInt("Choice: ");
        switch (subChoice) {
        case 1:
            editTouristName();
            break;
        case 2:
            editTouristSurname();
            break;
        case 3:
            editTouristPatronymic();
            break;
        case 4:
            editTouristBirthYear();
            break;
        case 5:
            editTouristPassport();
            break;
        case 6:
            editTouristBorderCrossings();
            break;
        case 7:
            return;
        default:
            cout << "Invalid choice." << endl;
        }
    }
}

void Canoe::editShopAddressAdd() {
    string newAddress;
    cout << "Enter new shop address: ";
    getline(cin, newAddress);
    AddShopAddress(newAddress);
    cout << "Address added." << endl;
}

void Canoe::editShopAddressDelete() {
    if (shopSize > 0) {
        cout << "Existing addresses:" << endl;
        for (int i = 0; i < shopSize; i++) {
            cout << i + 1 << ". " << shopAddress[i] << endl;
        }

        int addressNum = safeInputInt("Enter address number to delete: ");
        if (addressNum > 0 && addressNum <= shopSize) {
            for (int i = addressNum - 1; i < shopSize - 1; i++) {
                shopAddress[i] = shopAddress[i + 1];
            }
            shopSize--;
            cout << "Address deleted." << endl;
        }
        else {
            cout << "Invalid address number!" << endl;
        }
    }
    else {
        cout << "There is nothing to delete, the list is empty." << endl;
    }
}

void Canoe::editShopAddresses() {
    while (true) {
        cout << endl << "Change the list of shopping addresses" << endl
            << "1 - Add new address" << endl
            << "2 - Delete address" << endl
            << "3 - Return" << endl;

        int subChoice = safeInputInt("Choice: ");
        cin.ignore();

        switch (subChoice) {
        case 1:
            editShopAddressAdd();
            break;
        case 2:
            editShopAddressDelete();
            break;
        case 3:
            return;
        default:
            cout << "Invalid choice." << endl;
        }
    }
}

void Canoe::edit(int number) {
    while (true) {
        cout << endl << "Editing canoe (number: " << number << ")" << endl
            << "1 - Change entrepreneur details" << endl
            << "2 - Change tourist details" << endl
            << "3 - Change purchase address" << endl
            << "4 - Return" << endl;

        int choice = safeInputInt("Choice: ");
        switch (choice) {
        case 1:
            editEntrepreneurDetails();
            break;
        case 2:
            editTouristDetails();
            break;
        case 3:
            editShopAddresses();
            break;
        case 4:
            cout << "Return." << endl;
            return;
        default:
            cout << "Invalid choice." << endl;
        }
    }
}