#include "Tourist.h"
#include "Utilities.h"
#include <iostream>
using namespace std;

Tourist::Tourist() {
    borderCross = new borderCrossing[capacity];
}
Tourist::Tourist(const Tourist& other) : Human(other), passportData(other.passportData), size(other.size), capacity(other.capacity) {
    borderCross = new borderCrossing[capacity];
    for (int i = 0; i < size; i++) {
        borderCross[i] = other.borderCross[i];
    }
}

Tourist& Tourist::operator=(const Tourist& other) {
    if (this != &other) {
        Human::operator=(other);
        passportData = other.passportData;
        size = other.size;
        capacity = other.capacity;

        delete[] borderCross;
        borderCross = new borderCrossing[capacity];
        for (int i = 0; i < size; i++) {
            borderCross[i] = other.borderCross[i];
        }
    }
    return *this;
}

Tourist::~Tourist() {
    delete[] borderCross;
}

string Tourist::getPassportData() const { return passportData; };
int Tourist::getSize() const { return size; }
int Tourist::getCapacity() const { return capacity; }

void Tourist::setPassportData(string_view pasData) { passportData = pasData; };

void Tourist::editBorderCross(int index, string_view date, string_view country) {
    if (index >= 0 && index < size) {
        borderCross[index].crossingDate = date;
        borderCross[index].country = country;
    }
}

borderCrossing Tourist::getBorderCross(int index) const {
    if (index >= 0 && index < size) {
        return borderCross[index];
    }
    return borderCrossing();
}


void Tourist::AddBorderCross(string_view date, string_view country) {
    if (size >= capacity) {
        resizeBorderArray();
    }
    borderCross[size].crossingDate = date;
    borderCross[size].country = country;
    size++;
}

void Tourist::resizeBorderArray() {
    int newCapacity = (capacity == 0) ? 3 : capacity * 2;
    auto newBorderCross = new borderCrossing[newCapacity];

    if (borderCross != nullptr && size > 0) {
        for (int i = 0; i < size; i++) {
            newBorderCross[i] = borderCross[i];
        }
        delete[] borderCross;
    }

    borderCross = newBorderCross;
    capacity = newCapacity;
}

void Tourist::display() const{
    cout << "\nTourist information " << endl;
    cout << "Passport data: " << passportData << endl;

    cout << "Border crossings:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "  Date: " << borderCross[i].crossingDate
            << ", Country: " << borderCross[i].country << endl;
    }
}

void Tourist::input() {
    cout << "Enter tourist data: " << endl;
    cout << "Enter passport data: ";
    cin >> passportData;

    int count;
    cout << "How many border crossings do you want to add? ";
    cin >> count;
    for (int i = 0; i < count; ++i) {
        string date;
        string country;
        cout << "Border crossing " << i + 1 << ":\n";
        cout << "  Date: ";
        cin >> date;
        cout << "  Destination country: ";
        cin >> country;
        AddBorderCross(date, country);
    }
}

void Tourist::removeBorderCross(int index) {
    if (index < 0 || index >= size) return;

    for (int i = index; i < size - 1; i++) {
        borderCross[i] = borderCross[i + 1];
    }
    size--;
}

void Tourist::editPassport() {
    string newPassport;
    cout << "Enter new passport data: ";
    cin.ignore();
    getline(cin, newPassport);
    setPassportData(newPassport);
}

void Tourist::editBorderCrossingEdit() {
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

void Tourist::editBorderCrossingAdd() {
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

void Tourist::editBorderCrossingDelete() {
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

void Tourist::editBorderCrossings() {
    if (int borderSize = Tourist::getSize(); borderSize > 0) {
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
        editBorderCrossingEdit();
        break;
    case 2:
        editBorderCrossingAdd();
        break;
    case 3:
        editBorderCrossingDelete();
        break;
    case 4:
        return;
    default:
        cout << "Invalid choice." << endl;
    }
}

void Tourist::editTouristDetails() {
    while (true) {
        cout << endl << "Change tourist data: " << endl
            << "1 - Change passport data" << endl
            << "2 - Change border crossing data" << endl
            << "3 - Return" << endl;

        int subChoice = safeInputInt("Choice: ");
        switch (subChoice) {
        case 1:
            editPassport();
            break;
        case 2:
            editBorderCrossings();
            break;
        case 3:
            return;
        default:
            cout << "Invalid choice." << endl;
        }
    }
}