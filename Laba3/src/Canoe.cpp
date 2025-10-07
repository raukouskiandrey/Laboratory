#include "Canoe.h"
#include "Application.h"
#include "Utilities.h"
#include <iostream>
using namespace std;

Canoe::Canoe() {
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
    auto newShopAddress = new string[shopCapacity];
    for (int i = 0; i < shopSize; i++) {
        newShopAddress[i] = shopAddress[i];
    }
    delete[] shopAddress;
    shopAddress = newShopAddress;
}

void Canoe::display() const {
    Human::display();
    Entrepreneur::display();
    Tourist::display();

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

void Canoe::input() {
    Human::input();
    Entrepreneur::input();
    Tourist::input();

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
            << "1 - Change human details" << endl
            << "2 - Change entrepreneur details" << endl
            << "3 - Change tourist details" << endl
            << "4 - Change purchase address" << endl
            << "5 - Return" << endl;

        int choice = safeInputInt("Choice: ");
        switch (choice) {
        case 1:
            editHumanDetails();
            break;
        case 2:
            editEntrepreneurDetails();
            break;
        case 3:
            editTouristDetails();
            break;
        case 4:
            editShopAddresses();
            break;
        case 5:
            cout << "Return." << endl;
            return;
        default:
            cout << "Invalid choice." << endl;
        }
    }
}