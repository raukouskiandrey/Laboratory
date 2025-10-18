#pragma once

#include "Employee.h"
#include "HourlyEmployee.h"
#include "StaffEmployee.h"
#include "PercentBasedEmployee.h"

class App {
private:
    Employee** employees;
    int capacity;
    int employeeCount;

    void resizeEmployeeArray();
    void clearInputBuffer();
    int findById(int id) const;
    bool idExists(int id) const;

    void displayMainMenu() const;
    void displayEmployeeTypeMenu() const;
    void displayOutputMenu() const;

    void addEmployee();
    void addHourlyEmployee();
    void addStaffEmployee();
    void addPercentBasedEmployee();

    void showEmployees();
    void showAllEmployees();
    void showEmployeeByType(const char* type);

    void deleteEmployeeById();

public:
    App();
    ~App();
    void run();
};