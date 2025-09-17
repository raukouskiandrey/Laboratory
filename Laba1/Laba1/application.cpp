#include <iostream>
#include "application.h"
#include "employee.h"
#include "addition_input.h" 
using namespace std;

App::App() = default;

App::~App() { delete[] employees; }

void App::resize() {
    int newCapacity = (capacity == 0) ? 2 : capacity * 2;
    auto newArr = new Employee[newCapacity];
    int limit = (size < newCapacity) ? size : newCapacity;
    for (int i = 0; i < limit; ++i)
        newArr[i] = employees[i];
    delete[] employees;
    employees = newArr;
    capacity = newCapacity;
}

void App::showMenu() const {
    cout << "Menu: "<<endl;
    cout << "1. Add an employee"<<endl;
    cout << "2. Delete employee"<<endl;
    cout << "3. Show all employees"<<endl;
    cout << "4. Change employee details"<<endl;
    cout << "5. Exit" << endl;
}

void App::addEmployee() {
    Employee e;
    cout << "Adding an employee: "<<endl;

    int num;
    while (true) {
        num = safePositiveInputInt("Enter employee number: ");
        if (!idExists(num))
            break;
        cout << "Error: Number " << num << " already taken. Enter another." << endl;
    }
    e.setId(num);
    e.getEmployDataWithoutId();

    while (size >= capacity)
        resize();
    ++size;
    employees[size - 1] = e;
    cout << "Employee added."<<endl;
}

void App::listEmployees() const {
    if (size == 0) {
        cout << "The list is empty."<<endl;
        return;
    }
    cout << "List of employees"<<endl;
    for (int i = 0; i < size; ++i) {
        cout << "\n#" << (i + 1) << "\n";
        employees[i].putEmploy();
    }
}

int App::findById(int id) const {
    for (int i = 0; i < size; ++i) {
        if (employees[i].getId() == id)
            return i;
    }
    return -1;
}

void App::deleteEmployee() {
    if (size == 0) {
        cout << "There is nothing to delete, the list is empty."<<endl;
        return;
    }
    int id = safePositiveInputInt("Enter the employee number to delete: ");
    int idx = findById(id);
    if (idx == -1) {
        cout << "An employee with this number was not found."<<endl;
        return;
    }
    for (int i = idx; i < size - 1; ++i)
        employees[i] = employees[i + 1];
    --size;
    cout << "Employee delete."<<endl;
}

void App::editEmployee() {
    if (size == 0) {
        cout << "There is nothing to edit, the list is empty."<<endl;
        return;
    }
    int id = safePositiveInputInt("Enter employee number to edit: ");
    int idx = findById(id);
    if (idx == -1) {
        cout << "An employee with this number was not found."<<endl;
        return;
    }
    employees[idx].edit(*this);
}

void App::run() {
    while (true) {
        showMenu();
        int choice = safeInputInt("Choice: ");
        switch (choice) {
        case 1:
            addEmployee();
            break;
        case 2:
            deleteEmployee();
            break;
        case 3:
            listEmployees();
            break;
        case 4:
            editEmployee();
            break;
        case 5:
            cout << "Exit."<< endl;
            return;
        default:
            cout << "Invalid menu item. "<<endl;
        }
    }
}

bool App::idExists(int id) const {
    return findById(id) != -1;
}