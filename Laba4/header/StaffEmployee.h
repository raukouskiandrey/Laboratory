#pragma once
#include"Employee.h"

class StaffEmployee :public Employee {
private:
    double salary;
public:
    StaffEmployee();
    StaffEmployee(string employeeName, int employeeId, string employeePosition, double employeeSalary);

    virtual ~StaffEmployee();

    double calculateSalary() override;
    void input() override;
    void output() override;

    string getType() const override;
};