#include "Human.h"
#include"Utilities.h"
#include <iostream>
using namespace std;

Human::Human() = default;

Human::Human(const string& n, const string& sn, const string& p, int by)
    : name(n), surname(sn), patronymic(p), birthYear(by) {}

Human::Human(const Human& other) : name(other.name), surname(other.surname), patronymic(other.patronymic), birthYear(other.birthYear) {}

Human& Human::operator=(const Human& other) {
    if (this != &other) {
        name = other.name;
        surname = other.surname;
        patronymic = other.patronymic;
        birthYear = other.birthYear;
    }
    return *this;
}

string Human::getName() const { return name; }
string Human::getSurname() const { return surname; }
string Human::getPatronymic() const { return patronymic; }
int Human::getBirthYear() const { return birthYear; }

void Human::setName(string_view n) { name = n; }
void Human::setSurname(string_view sn) { surname = sn; }
void Human::setPatronymic(string_view p) { patronymic = p; }
void Human::setBirthYear(const int& by) { birthYear = by; }

void Human::display() const {
    cout << "Name: " << name << endl << "Surname: " << surname << endl << "Patronymic: " << patronymic << endl << "Year of birth: " << birthYear << endl;
}

void Human::input() {
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter surname: ";
    cin >> surname;
    cout << "Enter patronymic: ";
    cin >> patronymic;
    cout << "Enter year of birth: ";
    cin >> birthYear;
}

void Human::editName() {
    string newName;
    cout << "Enter new name: ";
    cin.ignore();
    getline(cin, newName);
    Human::setName(newName);
}

void Human::editSurname() {
    string newSurname;
    cout << "Enter new surname: ";
    cin.ignore();
    getline(cin, newSurname);
    Human::setSurname(newSurname);
}

void Human::editPatronymic() {
    string newPatronymic;
    cout << "Enter new patronymic: ";
    cin.ignore();
    getline(cin, newPatronymic);
    Human::setPatronymic(newPatronymic);
}

void Human::editBirthYear() {
    int newYear;
    cout << "Enter new birth year: ";
    cin >> newYear;
    Human::setBirthYear(newYear);
}

void Human::editHumanDetails() {
    while (true) {
        cout << endl << "Change human data: " << endl
            << "1 - Change name" << endl
            << "2 - Change surname" << endl
            << "3 - Change patronymic" << endl
            << "4 - Change birth year" << endl
            << "5 - Return" << endl;

        int subChoice = safeInputInt("Choice: ");
        switch (subChoice) {
        case 1:
            editName();
            break;
        case 2:
            editSurname();
            break;
        case 3:
            editPatronymic();
            break;
        case 4:
            editBirthYear();
            break;
        case 5:
            return;
        default:
            cout << "Invalid choice." << endl;
        }
    }
}