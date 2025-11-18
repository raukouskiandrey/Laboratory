#include "Shuttle.h"
#include "Application.h"
#include "InputValidationException.h"
#include "IndexOutOfBoundsException.h"
#include <iostream>
using namespace std;

Shuttle::Shuttle() = default;

Shuttle::Shuttle(const Shuttle& other)
    : Entrepreneur(other), Tourist(other), shopAddresses(other.shopAddresses) {}

Shuttle& Shuttle::operator=(const Shuttle& other) {
    if (this != &other) {
        Entrepreneur::operator=(other);
        Tourist::operator=(other);
        shopAddresses = other.shopAddresses;
    }
    return *this;
}

Shuttle::~Shuttle() = default;

int Shuttle::getShopSize() const { return shopAddresses.getSize(); }
int Shuttle::getShopCapacity() const { return shopAddresses.getCapacity(); }

void Shuttle::AddShopAddress(string_view Address) {
    shopAddresses.AddShopAddress(Address);
}

void Shuttle::removeShopAddress(int index) {
    shopAddresses.removeShopAddress(index);
}

string Shuttle::getShopAddress(int index) const {
    return shopAddresses.getShopAddress(index);
}

void Shuttle::display() const {
    Human::display();
    Entrepreneur::display();
    Tourist::display();

    if (shopAddresses.getSize() == 0) {
        cout << "No purchase addresses\n";
        return;
    }
    else {
        cout << "Purchase addresses:" << endl;
        for (int i = 0; i < shopAddresses.getSize(); i++) {
            cout << "  " << shopAddresses.getShopAddress(i) << endl;
        }
    }
}

void Shuttle::input() {
    Human::input();
    Entrepreneur::input();
    Tourist::input();

    int count = securelyInputInt("How many purchase addresses do you want to add? ");

    for (int i = 0; i < count; ++i) {
        string address = securelyInputLine("Purchase address " + to_string(i + 1) + ": ");
        AddShopAddress(address);
    }
}

void Shuttle::editShopAddressAdd() {
    string newAddress = securelyInputLine("Enter new shop address: ");
    AddShopAddress(newAddress);
    cout << "Address added." << endl;
}

void Shuttle::editShopAddressDelete() {
    if (shopAddresses.getSize() == 0) {
        cout << "There is nothing to delete, the list is empty." << endl;
        return;
    }
        for (int i = 0; i < shopAddresses.getSize(); i++) {
            cout << i + 1 << ". " << shopAddresses.getShopAddress(i) << endl;
        }

        while (true) {
            try {
                int addressNum = securelyInputPositiveInt("Enter address number to delete: ");
                if (addressNum > shopAddresses.getSize()) {
                    throw IndexOutOfBoundsException("Number must be smaller size : '" + to_string(addressNum) + "'");
                }
                removeShopAddress(addressNum - 1);
                cout << "Address deleted." << endl;
                break;
            }
            catch (const IndexOutOfBoundsException& e) {
                cout << "Index out of bounds: " << e.what() << ". Please try again.\n";
            }
        }
}

void Shuttle::editShopAddresses() {
    while (true) {
        cout << endl << "Change the list of shopping addresses" << endl
            << "1 - Add new address" << endl
            << "2 - Delete address" << endl
            << "3 - Return" << endl;

        int subChoice = securelyInputInt("Choice: ");

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

void Shuttle::edit(int number) {
    while (true) {
        cout << endl << "Editing shuttle (number: " << number << ")" << endl
            << "1 - Change human details" << endl
            << "2 - Change entrepreneur details" << endl
            << "3 - Change tourist details" << endl
            << "4 - Change purchase address" << endl
            << "5 - Return" << endl;

        int choice = securelyInputInt("Choice: ");
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