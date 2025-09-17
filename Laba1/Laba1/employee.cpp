#include "employee.h"
#include "application.h"
#include "addition_input.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

Employee::Employee(int id, float s, Date d, EmployeePosition p)
    : employeeId(id), salary(s), hireDate(d), position(p) {}

string employeePositionToString(EmployeePosition position) {
    switch (position) {
    case EmployeePosition::LABORANT:
        return "Laborant";
    case EmployeePosition::SECRETARY:
        return "Secretary";
    case EmployeePosition::MANAGER:
        return "Manager";
    case EmployeePosition::ENGINEER:
        return "Engineer";
    case EmployeePosition::DIRECTOR:
        return "Director";
    case EmployeePosition::ACCOUNTAN:
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
        position = ACCOUNTAN;
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

void Employee::edit(const App& app) {
    cout << endl << "Editing an employee (number: " << employeeId << ")" << endl;
    cout << "1. Change number" << endl;
    cout << "2. Change salary" << endl;
    cout << "3. Change the hire date" << endl;
    cout << "4. Change position" << endl;
    cout << "5. Cancel" << endl;

    int choice = safeInputInt("Choice: ");
    switch (choice) {
    case 1: {
        int newId;
        while (true) {
            newId = safePositiveInputInt("New number: ");
            if (newId == employeeId || !app.idExists(newId))
                break;
            cout << "Error: number " << newId << " already taken. Enter another one." << endl;
        }
        employeeId = newId;
        cout << "Ready." << endl;
        break;
    }
    case 2:
        salary = safePositiveInputFloat("New salary: ");
        cout << "Ready." << endl;
        break;
    case 3:
        cout << "New date:" << endl;
        hireDate.input();
        cout << "Ready." << endl;
        break;
    case 4: {
        switch (int typeChoice = safeInputInt("New position:\n"
            "1 - Laborant\n2 - Secretary\n3 - Manager\n4 - Engineer\n5 - Director\n6 - Accountan\n"
            "Choice: ");typeChoice) {
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
            position = ACCOUNTAN;
            break;
        default:
            cout << "Incorrect choice. Position not changed." << endl;
            break;
        }
        cout << "Ready." << endl;
        break;
    }
    default:
        cout << "Cancel." << endl;
        break;
    }
}