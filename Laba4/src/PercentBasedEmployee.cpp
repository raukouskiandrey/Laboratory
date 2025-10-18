#include"PercentBasedEmployee.h"
#include "Utilities.h"
#include<iostream>
using namespace std;

PercentBasedEmployee::PercentBasedEmployee() :Employee(), baseSalary(1), totalSales(1), percentRate(0.1) {};

PercentBasedEmployee::PercentBasedEmployee(string employeeName, int employeeId, string employeePosition, double employeeSalary, double employeeTotalSales, double employeePercentRate)
    : Employee(employeeName, employeeId, employeePosition), baseSalary(employeeSalary), totalSales(employeeTotalSales), percentRate(employeePercentRate) {};

PercentBasedEmployee::~PercentBasedEmployee() {
    cout << "Destructor PercentBasedEmployee" << endl;
};

double PercentBasedEmployee::calculateSalary() {
    return baseSalary + totalSales * percentRate / 100;
}

void PercentBasedEmployee::input() {
    cout << "Enter PercentBasedEmployee: " << endl;

    string name = readLineTrimmed("Enter name: ");
    setName(name);

    string position = readLineTrimmed("Enter position: ");
    setPosition(position);

    int id = safePositiveInputInt("Enter ID: ");
    setId(id);

    baseSalary = safePositiveInputFloat("Enter base salary: ");
    totalSales = safePositiveInputFloat("Enter totalSales: ");
    percentRate = safePositiveInputFloat("Enter percentRate: ");
}

void PercentBasedEmployee::output() {
    cout << "PercentBasedEmployee: " << endl
        << "Name: " << getName() << endl
        << "Position: " << getPosition() << endl
        << "ID: " << getId() << endl
        << "Base salary: " << baseSalary << endl
        << "Total sales: " << totalSales << endl
        << "Percent rate: " << percentRate << "%" << endl
        << "Total salary: " << calculateSalary() << endl;
}

string PercentBasedEmployee::getType() const  {
    return "PERCENT-BASED";
}