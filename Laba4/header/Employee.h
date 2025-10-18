#pragma once
#include<string>
using namespace std;

class Employee {
private:
    string name;
    int id;
    string position;  
public:
    Employee();
    Employee(string employeeName, int employeeId, string employeePosition = "Unknown");

    ~Employee();

    string getName() const;
    int getId() const;
    string getPosition() const;  

    void setName(string n);
    void setId(int Id);
    void setPosition(string pos);  

    virtual double calculateSalary() = 0;
    virtual void input() = 0;
    virtual void output() = 0;

    virtual string getType() const = 0;
};