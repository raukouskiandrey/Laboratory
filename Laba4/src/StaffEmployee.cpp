#include"StaffEmployee.h"
#include "Utilities.h"
#include<iostream>
using namespace std;

StaffEmployee::StaffEmployee() : Employee(), salary(1) {}

StaffEmployee::StaffEmployee(string employeeName, int employeeId, string employeePosition, double employeeSalary)
    : Employee(employeeName, employeeId, employeePosition), salary(employeeSalary) {}

void StaffEmployee::input() {
    cout << "Enter data staff employee: " << endl;

    string name = readLineTrimmed("Enter name: ");
    setName(name);

    string position = readLineTrimmed("Enter position: ");
    setPosition(position);

    int id = safePositiveInputInt("Enter ID: ");
    setId(id);

    salary = safePositiveInputFloat("Enter salary: ");
}

StaffEmployee::~StaffEmployee() {
    cout << "Destructor StaffEmployee" << endl;
}

double StaffEmployee::calculateSalary() {
    return salary;
}

void StaffEmployee::output() {
    cout << "StaffEmployee: " << endl
        << "Name: " << getName() << endl
        << "Position: " << getPosition() << endl
        << "ID: " << getId() << endl
        << "Salary: " << calculateSalary() << endl;
}

string StaffEmployee::getType() const {
    return "STAFF";
}