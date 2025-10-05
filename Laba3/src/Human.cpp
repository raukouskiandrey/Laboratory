#include "Human.h"
#include <iostream>
using namespace std;

Human::Human() : name("Fyodor"), surname("Konyukhov"), patronymic("Filippovich"), birthYear(1951) {}

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

string Human::getName() { return name; }
string Human::getSurname() { return surname; }
string Human::getPatronymic() { return patronymic; }
int Human::getBirthYear() { return birthYear; }

void Human::setName(const string& n) { name = n; }
void Human::setSurname(const string& sn) { surname = sn; }
void Human::setPatronymic(const string& p) { patronymic = p; }
void Human::setBirthYear(const int& by) { birthYear = by; }

void Human::displayHuman() {
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