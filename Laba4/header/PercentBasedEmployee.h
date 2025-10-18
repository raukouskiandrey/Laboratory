#pragma once
#include"Employee.h"

class PercentBasedEmployee :public Employee {
private:
    double baseSalary;
    double totalSales;
    double percentRate;
public:
    PercentBasedEmployee();
    PercentBasedEmployee(string employeeName, int employeeId, string employeePosition, double employeeSalary, double employeeTotalSales, double employeePercentRate);

    virtual ~PercentBasedEmployee();

    double calculateSalary() override;
    void input() override;
    void output() override;

    string getType() const override;
};