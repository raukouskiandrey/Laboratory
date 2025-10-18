#include"Employee.h"
#include<iostream>
using namespace std;

Employee::Employee() : name("Igor"), id(1), position("Unknown") {}

Employee::Employee(string employeeName, int employeeId, string employeePosition)
    : name(employeeName), id(employeeId), position(employeePosition) {}

Employee::~Employee() {
    cout << "Destructor Employee";
}

string Employee::getName() const {
    return name;
}

int Employee::getId() const {
    return id;
}

string Employee::getPosition() const {  
    return position;
}

void Employee::setName(string n) {
    name = n;
}

void Employee::setId(int Id) {
    id = Id;
}

void Employee::setPosition(string pos) {  
    position = pos;
}