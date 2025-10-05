#include "Application.h"
#include "Utilities.h"
#include <iostream>
using namespace std;

void App::resize() {
    int newCapacity = (capacity == 0) ? 2 : capacity * 2;
    auto newArr = new Canoe[newCapacity];
    int limit = (size < newCapacity) ? size : newCapacity;
    for (int i = 0; i < limit; ++i)
        newArr[i] = canoes[i];
    delete[] canoes;
    canoes = newArr;
    capacity = newCapacity;
}

void App::showMenu() const {
    cout << "Menu: " << endl;
    cout << "1. Add canoe" << endl;
    cout << "2. Delete canoe" << endl;
    cout << "3. View all canoes" << endl;
    cout << "4. Edit canoe" << endl;
    cout << "5. Exit" << endl;
}

void App::addCanoe() {
    Canoe c;
    cout << "Adding canoe #" << size + 1 << endl;

    c.inputCanoe();

    while (size >= capacity)
        resize();
    ++size;
    canoes[size - 1] = c;
    cout << "Canoe added." << endl;
}

void App::listCanoe() const {
    if (size == 0) {
        cout << "The list is empty." << endl;
        return;
    }
    cout << "Canoe list" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "\n#" << (i + 1) << "\n";
        canoes[i].displayCanoe();
    }
}

void App::deleteCanoe() {
    if (size == 0) {
        cout << "There is nothing to delete, the list is empty." << endl;
        return;
    }
    int number = safeInputInt("Enter canoe number to delete: ");
    if (number > 0 && number <= size) {
        for (int i = number - 1; i < size - 1; ++i)
            canoes[i] = canoes[i + 1];
        --size;
        cout << "Canoe deleted." << endl;
    }
    else {
        cout << "No such number!!!" << endl;
    }
}

void App::editCanoe() {
    if (size == 0) {
        cout << "There is nothing to edit, the list is empty." << endl;
        return;
    }
    int number = safePositiveInputInt("Enter canoe number to edit: ");
    if (number > 0 && number <= size) {
        canoes[number - 1].edit(number);
    }
    else {
        cout << "No such number!!!" << endl;
    }
}

void App::run() {
    while (true) {
        showMenu();
        int choice = safeInputInt("Choice: ");
        switch (choice) {
        case 1:
            addCanoe();
            break;
        case 2:
            deleteCanoe();
            break;
        case 3:
            listCanoe();
            break;
        case 4:
            editCanoe();
            break;
        case 5:
            cout << "Exit." << endl;
            return;
        default:
            cout << "Invalid menu item. " << endl;
        }
    }
}