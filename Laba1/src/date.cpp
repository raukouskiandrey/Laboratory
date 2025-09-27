
#include "date.h"
#include "utilities.h"
#include <array>
#include <chrono>
#include <ctime>
#include <iostream>

using namespace std;

Date::Date() : day(1), month(1), year(2000) {}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

bool Date::isLeapYear(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

Date Date::getCurrentDate() {
    using namespace std::chrono;

    auto now = system_clock::now();
    time_t timeNow = system_clock::to_time_t(now);

    tm localTime{};
#ifdef _WIN32
    localtime_s(&localTime, &timeNow);
#else
    localtime_r(&timeNow, &localTime);
#endif

    return Date(localTime.tm_mday, localTime.tm_mon + 1, localTime.tm_year + 1900);
}

bool Date::isValid() const {
    if (year < 1) {
        cout << "Incorrect year" << endl;
        return false;
    }

    if (month < 1 || month > 12) {
        cout << "There is no such month." << endl;
        return false;
    }

    array<int, 12> daysInMonth = { 31, 28, 31, 30, 31, 30,
                                  31, 31, 30, 31, 30, 31 };
    if (isLeapYear(year))
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1]) {
        cout << "There is no such day this month." << endl;
        return false;
    }


    if (Date currentDate = getCurrentDate(); year > currentDate.year ||
        (year == currentDate.year && month > currentDate.month) ||
        (year == currentDate.year && month == currentDate.month && day > currentDate.day)) {
        cout << "Error: the date entered is in the future.\n";
        return false;
    }

    return true;
}

void Date::input() {
    while (true) {
        cout << "Enter date: " << endl;
        day = safePositiveInputInt("Day: ");
        month = safePositiveInputInt("Month: ");
        year = safePositiveInputInt("Year: ");

        if (isValid()) {
            break;
        }
        else {
            cout << "Try again." << endl;
        }
    }
}

void Date::print() const {
    cout << day << "." << month << "." << year;
}
