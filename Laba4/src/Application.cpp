#include "Application.h"
#include "Utilities.h"
#include <iostream>
#include <limits>
#include <cstring>

using namespace std;

App::App() : capacity(5), employeeCount(0) {
    employees = new Employee * [capacity];
}

App::~App() {
    for (int i = 0; i < employeeCount; ++i) {
        delete employees[i];
    }
    delete[] employees;
}

void App::clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void App::resizeEmployeeArray() {
    int newCapacity = capacity * 2;
    auto newEmployees = new Employee * [newCapacity];

    for (int i = 0; i < employeeCount; ++i) {
        newEmployees[i] = employees[i];
    }

    delete[] employees;
    employees = newEmployees;
    capacity = newCapacity;

    cout << "Array resized to " << capacity << " elements!" << endl;
}

int App::findById(int id) const {
    for (int i = 0; i < employeeCount; ++i) {
        if (employees[i]->getId() == id)
            return i;
    }
    return -1;
}

bool App::idExists(int id) const {
    return findById(id) != -1;
}

void App::displayMainMenu() const {
    cout << "\n\tMENU" << endl;
    cout << "1. Enter employee" << endl;
    cout << "2. Show employees" << endl;
    cout << "3. Delete employee " << endl;
    cout << "0. Exit" << endl;
    cout << "Choose option: ";
}

void App::displayEmployeeTypeMenu() const {
    cout << "\n\tCHOOSE EMPLOYEE TYPE" << endl;
    cout << "1. Hourly employee" << endl;
    cout << "2. Staff employee" << endl;
    cout << "3. Percent-based employee" << endl;
    cout << "0. Back" << endl;
    cout << "Choose type: ";
}

void App::displayOutputMenu() const {
    cout << "\n\tSHOW EMPLOYEES" << endl;
    cout << "1. Show all employees" << endl;
    cout << "2. Show hourly employees" << endl;
    cout << "3. Show staff employees" << endl;
    cout << "4. Show percent-based employees" << endl;
    cout << "0. Back" << endl;
    cout << "Choose option: ";
}

void App::addEmployee() {
    int typeChoice;

    while (true) {
        displayEmployeeTypeMenu();
        cin >> typeChoice;

        if (cin.fail()) {
            cout << "Invalid input! Please enter a number." << endl;
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (typeChoice) {
        case 1:
            addHourlyEmployee();
            return;
        case 2:
            addStaffEmployee();
            return;
        case 3:
            addPercentBasedEmployee();
            return;
        case 0:
            return;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
}

void App::addHourlyEmployee() {
    if (employeeCount >= capacity) {
        resizeEmployeeArray();
    }

    auto employee = new HourlyEmployee();
    employee->input();

    while (idExists(employee->getId())) {
        cout << "This ID already exists. Please enter a new ID: " << endl;
        int newId = safePositiveInputInt("Enter ID: ");
        employee->setId(newId);
    }

    employees[employeeCount++] = employee;
    cout << "Hourly employee added successfully! ID: " << employee->getId() << endl;
}

void App::addStaffEmployee() {
    if (employeeCount >= capacity) {
        resizeEmployeeArray();
    }

    auto employee = new StaffEmployee();
    employee->input();

    while (idExists(employee->getId())) {
        cout << "This ID already exists. Please enter a new ID: " << endl;
        int newId = safePositiveInputInt("Enter ID: ");
        employee->setId(newId);
    }

    employees[employeeCount++] = employee;
    cout << "Staff employee added successfully! ID: " << employee->getId() << endl;
}

void App::addPercentBasedEmployee() {
    if (employeeCount >= capacity) {
        resizeEmployeeArray();
    }

    auto employee = new PercentBasedEmployee();
    employee->input();

    while (idExists(employee->getId())) {
        cout << "This ID already exists. Please enter a new ID: " << endl;
        int newId = safePositiveInputInt("Enter ID: ");
        employee->setId(newId);
    }

    employees[employeeCount++] = employee;
    cout << "Percent-based employee added successfully! ID: " << employee->getId() << endl;
}

void App::showEmployees() {
    int outputChoice;

    while (true) {
        displayOutputMenu();
        cin >> outputChoice;

        if (cin.fail()) {
            cout << "Invalid input! Please enter a number." << endl;
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (outputChoice) {
        case 1:
            showAllEmployees();
            break;
        case 2:
            showEmployeeByType("HOURLY");
            break;
        case 3:
            showEmployeeByType("STAFF");
            break;
        case 4:
            showEmployeeByType("PERCENT-BASED");
            break;
        case 0:
            return;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
}

void App::showAllEmployees() {
    if (employeeCount == 0) {
        cout << "No employees in the system!" << endl;
        return;
    }

    cout << "\n\tALL EMPLOYEES (" << employeeCount << ")" << endl;
    for (int i = 0; i < employeeCount; ++i) {
        cout << "\n--- Employee " << i + 1 << " ---" << endl;
        employees[i]->output();
    }
}

void App::showEmployeeByType(const char* type) {
    bool found = false;

    cout << "\n\t" << type << " EMPLOYEES" << endl;

    for (int i = 0; i < employeeCount; ++i) {
        if (employees[i]->getType() == type) {
            found = true;
            cout << "\n--- Employee " << i + 1 << " ---" << endl;
            employees[i]->output();
        }
    }

    if (!found) {
        cout << "No " << type << " employees found!" << endl;
    }
}

void App::deleteEmployeeById() {
    if (employeeCount == 0) {
        cout << "No employees in the system for deletion!" << endl;
        return;
    }

    int id;
    cout << "Enter employee ID to delete: ";
    cin >> id;

    if (cin.fail()) {
        cout << "Invalid ID format!" << endl;
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    int index = findById(id);
    if (index == -1) {
        cout << "Employee with ID " << id << " not found!" << endl;
        return;
    }

    cout << "Deleting employee:" << endl;
    employees[index]->output();

    delete employees[index];

    for (int i = index; i < employeeCount - 1; ++i) {
        employees[i] = employees[i + 1];
    }

    employeeCount--;
    cout << "Employee deleted successfully!" << endl;
}

void App::run() {
    int choice;

    while (true) {
        displayMainMenu();
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input! Please enter a number." << endl;
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
        case 1:
            addEmployee();
            break;
        case 2:
            showEmployees();
            break;
        case 3:
            deleteEmployeeById();
            break;
        case 0:
            cout << "Goodbye!" << endl;
            return;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
}