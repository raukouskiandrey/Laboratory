#include "employee.h"
#include "application.h"
#include "utilities.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

Employee::Employee(int id, float s, Date d, EmployeePosition p)
    : employeeId(id), salary(s), hireDate(d), position(p) {}

string employeePositionToString(EmployeePosition position) {
    switch (position) {
        using enum EmployeePosition;
    case LABORANT:
        return "Laborant";
    case SECRETARY:
        return "Secretary";
    case MANAGER:
        return "Manager";
    case ENGINEER:
        return "Engineer";
    case DIRECTOR:
        return "Director";
    case ACCOUNTANT:
        return "Accountan";
    default:
        return "Unknown";
    }
}

void Employee::getEmployDataWithoutId() {
    salary = safePositiveInputFloat("Enter employee salary: ");
    hireDate.input();

    int typeChoice = safeInputInt(
        "Select employee position:\n"
        "1 - Laborant\n2 - Secretary\n3 - Manager\n4 - Engineer\n5 - Director\n6 - Accountan\n"
        "Choice: ");

    switch (typeChoice) {
        using enum EmployeePosition;
    case 1:
        position = LABORANT;
        break;
    case 2:
        position = SECRETARY;
        break;
    case 3:
        position = MANAGER;
        break;
    case 4:
        position = ENGINEER;
        break;
    case 5:
        position = DIRECTOR;
        break;
    case 6:
        position = ACCOUNTANT;
        break;
    default:
        position = LABORANT;
        break;
    }
}

void Employee::putEmploy() const {
    cout << "Number: " << employeeId << "\n";
    cout << fixed << setprecision(2);
    cout << "Salary: " << salary << "\n";
    cout << "Hire date: ";
    hireDate.print();
    cout << "\nJob position: " << employeePositionToString(position) << "\n";
}

int Employee::getId() const {
    return employeeId;
}

void Employee::setId(int id) {
    employeeId = id;
}