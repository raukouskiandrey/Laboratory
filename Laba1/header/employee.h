#pragma once
#include "date.h"
#include <string>

enum class EmployeePosition {
    LABORANT = 1,
    SECRETARY,
    MANAGER,
    ENGINEER,
    DIRECTOR,
    ACCOUNTANT
};

class App;

class Employee {
private:
    int employeeId;
    float salary;
    Date hireDate;
    EmployeePosition position;

public:
    Employee() = default;
    Employee(int id, float s, Date d, EmployeePosition p);

    void getEmployDataWithoutId();
    void putEmploy() const;
    int getId() const;
    void setId(int id);
};