#include "Human.h"
#include"InputValidationException.h"
#include "FutureYearException.h"
#include <iostream>
#include <chrono>

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

int Human::getCurrentDate() {
    const auto now = chrono::system_clock::now();
    time_t tt = chrono::system_clock::to_time_t(now);
    tm tmv{};
#ifdef _WIN32
    localtime_s(&tmv, &tt);
#endif
    int TM_YEAR_BASE = 1900;
    int currentYear = tmv.tm_year + TM_YEAR_BASE;
    return currentYear;
}

void Human::display() const {
    cout << "Name: " << name << endl << "Surname: " << surname << endl << "Patronymic: " << patronymic << endl << "Year of birth: " << birthYear << endl;
}

void Human::input() {
    name = securelyInputWord("Enter name: ");
    surname = securelyInputWord("Enter surname: ");
    patronymic = securelyInputWord("Enter patronymic: ");

    while (true) {
        try {
            int year = securelyInputPositiveInt("Enter year of birth: ");
            if (year > getCurrentDate()) {
                throw FutureYearException("Year cannot be in the future: '" + to_string(year) + "'");
            }
            birthYear = year;
            break;
        }
        catch (const FutureYearException& e) {
            cout << "Future year error: " << e.what() << ". Please try again.\n";
        }
    }
}

void Human::editName() {
    string newName = securelyInputWord("Enter new name: ");
    Human::setName(newName);
}

void Human::editSurname() {
    string newSurname = securelyInputWord("Enter new surname: ");
    Human::setSurname(newSurname);
}

void Human::editPatronymic() {
    string newPatronymic = securelyInputWord("Enter new patronymic: ");
    Human::setPatronymic(newPatronymic);
}

void Human::editBirthYear() {
    int newYear = securelyInputPositiveInt("Enter year of birth: ");
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

            int subChoice = securelyInputInt("Choice: ");
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


