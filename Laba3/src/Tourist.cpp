#include "Tourist.h"
#include <iostream>
using namespace std;

Tourist::Tourist() : passportData("8545199"), borderCross(nullptr), size(0), capacity(3) {
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

string Tourist::getPassportData() { return passportData; };
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

void Tourist::displayTourist() {
    cout << "\nTourist information " << endl;
    displayHuman();
    cout << "Passport data: " << passportData << endl;

    cout << "Border crossings:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "  Date: " << borderCross[i].crossingDate
            << ", Country: " << borderCross[i].country << endl;
    }
}

void Tourist::inputTourist() {
    cout << "Enter tourist data: " << endl;
    inputHuman();
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