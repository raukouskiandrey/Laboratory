#pragma once
#include"Employee.h"
using namespace std;

class HourlyEmployee :public Employee {
private:
    int hours;
    double hourlyRate;
public:
    HourlyEmployee();
    HourlyEmployee(string employeeName, int employeeId, string employeePosition, int employeeHours, double employeeHourlyRate);

    ~HourlyEmployee();

    double calculateSalary() override;
    void input() override;
    void output() override;

    string getType() const override;
};