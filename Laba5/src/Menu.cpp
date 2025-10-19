#include "Menu.h"
#include "Utilities.h"
#include <iostream>
#include <limits>

using namespace std;

void readValue(int& val) {
    val = safeInputInt("");
}

void readValue(float& val) {
    val = safeInputFloat("");
}

void readValue(string& val) {
    val = readLineTrimmed("");
    while (val.empty()) {
        cout << "String cannot be empty! Please enter text: ";
        val = readLineTrimmed("");
    }
}

void readValue(char& val) {
    while (true) {
        string input = readLineTrimmed("");
        if (input.length() == 1) {
            val = input[0];
            break;
        }
        else {
            cout << "Please enter exactly one character: ";
        }
    }
}

template<typename T>
void runMenu() {
    SinglyLinkedList<T> list;
    T value;
    int choice, index;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add element to beginning\n";
        cout << "2. Add element to end\n";
        cout << "3. Show list\n";
        cout << "4. Remove first element\n";
        cout << "5. Remove last element\n";
        cout << "6. Remove by index\n";
        cout << "7. Remove all elements\n";
        cout << "8. Show list size\n";
        cout << "0. Exit\n> ";

        choice = safeInputInt("");

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            readValue(value);
            list.pushFront(value);
            cout << "Element added to beginning." << endl;
            break;
        case 2:
            cout << "Enter value: ";
            readValue(value);
            list.pushBack(value);
            cout << "Element added to end." << endl;
            break;
        case 3:
            if (list.isEmpty()) {
                cout << "List is empty!" << endl;
            }
            else {
                cout << "List contents:" << endl;
                list.print();
            }
            break;
        case 4:
            if (list.isEmpty()) {
                cout << "List is empty! Nothing to delete." << endl;
            }
            else {
                list.popFront();
                cout << "First element removed." << endl;
            }
            break;
        case 5:
            if (list.isEmpty()) {
                cout << "List is empty! Nothing to delete." << endl;
            }
            else {
                list.popBack();
                cout << "Last element removed." << endl;
            }
            break;
        case 6:
            if (list.isEmpty()) {
                cout << "List is empty! Nothing to delete." << endl;
            }
            else {
                index = safeInputInt("Enter index: ");
                if (index >= 0 && index < list.getSize()) {
                    list.deleteByIndex(index);
                }
                else {
                    cout << "Invalid index! Valid range: 0 - " << list.getSize() - 1 << endl;
                }
            }
            break;
        case 7:
            if (list.isEmpty()) {
                cout << "List is already empty!" << endl;
            }
            else {
                list.clear();
                cout << "All elements removed." << endl;
            }
            break;
        case 8:
            cout << "List size: " << list.getSize() << " elements" << endl;
            break;
        case 0:
            return;
        default:
            cout << "Invalid choice! Enter a number from 0 to 8." << endl;
        }
    }
}

void runProgram() {
    setlocale(LC_ALL, "");

    int typeChoice = safeInputInt("Select data type: \n1. int\n2. float\n3.string\n4. char\n > ");

    switch (typeChoice) {
    case 1:
        runMenu<int>();
        break;
    case 2:
        runMenu<float>();
        break;
    case 3:
        runMenu<string>();
        break;
    case 4:
        runMenu<char>();
        break;
    default:
        cout << "Invalid type choice!" << endl;
    }
}