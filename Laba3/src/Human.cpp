#include "Human.h"
#include <iostream>
using namespace std;

Human::Human() = default;

Human::Human(string n, string sn, string p, int by) : name(n), surname(sn), patronymic(p), birthYear(by) {}

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

void Human::displayHuman() const {
    cout << "Name: " << name << endl << "Surname: " << surname << endl << "Patronymic: " << patronymic << endl << "Year of birth: " << birthYear << endl;
}

void Human::inputHuman() {
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter surname: ";
    cin >> surname;
    cout << "Enter patronymic: ";
    cin >> patronymic;
    cout << "Enter year of birth: ";
    cin >> birthYear;
}