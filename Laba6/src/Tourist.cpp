#include "Tourist.h"
#include "Utilities.h"
#include <iostream>
using namespace std;

Tourist::Tourist() = default;

Tourist::Tourist(const Tourist& other)
    : Human(other), passportData(other.passportData), borderCrossings(other.borderCrossings) {}

Tourist& Tourist::operator=(const Tourist& other) {
    if (this != &other) {
        Human::operator=(other);
        passportData = other.passportData;
        borderCrossings = other.borderCrossings;
    }
    return *this;
}

Tourist::~Tourist() = default;

string Tourist::getPassportData() const { return passportData; }
int Tourist::getBorderCrossingSize() const { return borderCrossings.getSize(); }

void Tourist::setPassportData(string_view pasData) { passportData = pasData; }

void Tourist::editBorderCross(int index, string_view date, string_view country) {
    borderCrossings.editBorderCross(index, date, country);
}

borderCrossing Tourist::getBorderCross(int index) const {
    return borderCrossings.getBorderCross(index);
}

void Tourist::AddBorderCross(string_view date, string_view country) {
    borderCrossings.AddBorderCross(date, country);
}

void Tourist::removeBorderCross(int index) {
    borderCrossings.removeBorderCross(index);
}

void Tourist::display() const {
    cout << "\nTourist information " << endl;
    cout << "Passport data: " << passportData << endl;

    cout << "Border crossings:" << endl;
    for (int i = 0; i < borderCrossings.getSize(); i++) {
        borderCrossing crossing = borderCrossings.getBorderCross(i);
        cout << "  Date: " << crossing.crossingDate
            << ", Country: " << crossing.country << endl;
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

static int securelyInputPositionInt(const string& prompt) {
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

void Tourist::input() {
        cout << "Enter tourist data: " << endl;
        passportData = securelyInputWord("Enter passport data: ");

        while (true) {
            try {
                int count = securelyInputInt("How many border crossings do you want to add? ");
                if (count < 0) {
                    throw InputValidationError("Number of border crossings cannot be negative");
                }
                for (int i = 0; i < count; ++i) {
                    cout << "Border crossing " << i + 1 << ":\n";
                    string date = securelyInputWord("Date: ");
                    string country = securelyInputWord("Destination country: ");
                    AddBorderCross(date, country);
                }
                break;
            }
            catch (InputValidationError& e) {
                cout << "Invalid argument: " << e.what() << ". Please try again.\n";
            }
        }
}

void Tourist::editPassport() {
    string newPassport = safeInputWord("Enter new passport data: ");
    setPassportData(newPassport);
}

void Tourist::editBorderCrossingEdit() {
    int borderSize = getBorderCrossingSize();
    if (borderSize == 0) {
        cout << "There is nothing to edit, the list is empty." << endl;
        return;
    }

    while (true) {
        try {
            int crossingNum = securelyInputPositionInt("Enter crossing number to edit: ");
            if (crossingNum > borderSize) {
                throw InputValidationError("Number must be smaller size: '" + to_string(crossingNum) + "'");
            }
                string date = securelyInputWord("Enter new date: ");
                string country = securelyInputWord("Enter new destination country: ");

                editBorderCross(crossingNum - 1, date, country);
                cout << "Crossing updated." << endl;   
                break;
        }
        catch (InputValidationError& e) {
            cout << "Invalid argument: " << e.what() << ". Please try again.\n";
        }
    }
}

void Tourist::editBorderCrossingAdd() {
    string date = securelyInputWord("Enter date: ");
    string country = securelyInputWord("Enter destination country: ");
    AddBorderCross(date, country);
    cout << "Border crossing added." << endl;
}

void Tourist::editBorderCrossingDelete() {
    int borderSize = getBorderCrossingSize();
    if (borderSize == 0) {
        cout << "There is nothing to delete, the list is empty." << endl;
        return;
    }

    while (true) {
        try {
            int crossingNum = securelyInputPositionInt("Enter crossing number to delete: ");
            if (crossingNum > borderSize) {
                throw InputValidationError("Number must be smaller size: '" + to_string(crossingNum) + "'");
            }
            removeBorderCross(crossingNum - 1);
            cout << "Crossing deleted." << endl;
            break;
        }
        catch (InputValidationError& e) {
            cout << "Invalid argument: " << e.what() << ". Please try again.\n";
        }
    }
}

void Tourist::editBorderCrossings() {
    int borderSize = getBorderCrossingSize();
    if (borderSize > 0) {
        cout << "Existing border crossings:" << endl;
        for (int i = 0; i < borderSize; i++) {
            borderCrossing crossing = getBorderCross(i);
            cout << i + 1 << ". Date: " << crossing.crossingDate
                << ", Country: " << crossing.country << endl;
        }
    }

    while (true) {
        try {
            cout << "Choose action:" << endl
                << "1 - Edit existing crossing" << endl
                << "2 - Add new crossing" << endl
                << "3 - Delete crossing" << endl
                << "4 - Return" << endl;

            int action = securelyInputInt("Choice: ");

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
        catch (InputValidationError& e) {
            cout << "Invalid argument: " << e.what() << ". Please try again.\n";
        }
    }
}

void Tourist::editTouristDetails() {
    while (true) {
        try {
            cout << endl << "Change tourist data: " << endl
                << "1 - Change passport data" << endl
                << "2 - Change border crossing data" << endl
                << "3 - Return" << endl;

            int subChoice = securelyInputInt("Choice: ");
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
        catch (InputValidationError& e) {
                cout << "Invalid argument: " << e.what() << ". Please try again.\n";
        }
    }
}