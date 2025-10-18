#include"HourlyEmployee.h"
#include "Utilities.h"
#include <iostream>
using namespace std;

HourlyEmployee::HourlyEmployee() : Employee(), hours(1), hourlyRate(1) {}

HourlyEmployee::HourlyEmployee(string employeeName, int employeeId, string employeePosition, int employeeHours, double employeeHourlyRate)
    : Employee(employeeName, employeeId, employeePosition), hours(employeeHours), hourlyRate(employeeHourlyRate) {}

void HourlyEmployee::input() {
    cout << "Enter data hourly employee: " << endl;

    string name = readLineTrimmed("Enter name: ");
    setName(name);

    string position = readLineTrimmed("Enter position: ");
    setPosition(position);

    int id = safePositiveInputInt("Enter ID: ");
    setId(id);

    hours = safePositiveInputInt("Enter hours: ");
    hourlyRate = safePositiveInputFloat("Enter hourly rate: ");
}

HourlyEmployee::~HourlyEmployee() {
    cout << "Destructor HourlyEmployee" << endl;
}

double HourlyEmployee::calculateSalary() {
    return hours * hourlyRate;
}

void HourlyEmployee::output() {
    cout << "HourlyEmployee: " << endl
        << "Name: " << getName() << endl
        << "Position: " << getPosition() << endl
        << "ID: " << getId() << endl
        << "Hours: " << hours << endl
        << "HourlyRate: " << hourlyRate << endl
        << "Salary: " << calculateSalary() << endl;
}

string HourlyEmployee::getType() const {
    return "HOURLY";
}