#include"Menu.h"
#include"DoublyLinkedList.h"
#include "Utilities.h"
#include"Algorithm.h"
#include<iostream>
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

void showMenu() {
    cout << "Menu :" << endl;
    cout << "1. Create a new list" << endl;
    cout << "2. Add to the beginning" << endl;
    cout << "3. Add to the end" << endl;
    cout << "4. Delete the first element" << endl;
    cout << "5. Delete the last element" << endl;
    cout << "6. Search" << endl;
    cout << "7. Sort" << endl;
    cout << "8. Show the list" << endl;
    cout << "9. Clear the list" << endl;
    cout << "10. Exit" << endl;
}

void createList() {
    while (true) {
        cout << "Types:" << endl;
        cout << "1. int" << endl;
        cout << "2. float" << endl;
        cout << "3. string" << endl;
        cout << "4. char" << endl;
        cout << "5. Exit program" << endl;

        int typeChoice = safeInputInt("Select type: ");

        switch (typeChoice) {
        case 1: runMenu<int>(); break;
        case 2: runMenu<float>(); break;
        case 3: runMenu<string>(); break;
        case 4: runMenu<char>(); break;
        case 5: return; 
        default:
            cout << "Invalid choice! Please select from 1 to 5." << endl;
        }
    }
}
template<typename t>
void runMenu() {
    DoublyLinkedList<t> list;
    Algorithm<t> algo;
    t value;
    int choice;

    while (true) {
        showMenu();

        choice = safeInputInt("Select: ");

        switch (choice) {
        case 1:
            list.clear();
            cout << "List cleared. Create a new list." << endl;
            return;
        case 2:
            cout << "Enter data: ";
            readValue(value);
            list.pushFront(value);
            cout << "Element added to the beginning." << endl;
            break;
        case 3:
            cout << "Enter data: ";
            readValue(value);
            list.pushBack(value);
            cout << "Element added to the end." << endl;
            break;
        case 4:
            if (list.empty()) {
                cout << "List is empty! Nothing to delete." << endl;
            }
            else {
                list.popFront();
                cout << "First element deleted." << endl;
            }
            break;
        case 5:
            if (list.empty()) {
                cout << "List is empty! Nothing to delete." << endl;
            }
            else {
                list.popBack();
                cout << "Last element deleted." << endl;
            }
            break;
        case 6:
            if (list.empty()) {
                cout << "List is empty! Nothing to search for." << endl;
            }
            else {
                cout << "Enter data to search for: ";
                readValue(value);
                if (algo.find(list, value)) {
                    cout << "Value found in the list." << endl;
                }
                else {
                    cout << "Not found." << endl;
                }
            }
            break;
        case 7:
            if (list.empty()) {
                cout << "List is empty! Nothing to sort." << endl;
            }
            else if (list.getSize() == 1) {
                cout << "The list has only one element - sorting is not required." << endl;
            }
            else {
                algo.sort(list);
                cout << "List sorted." << endl;
            }
            break;
        case 8:
            if (list.empty()) {
                cout << "List is empty!" << endl;
            }
            else {
                cout << "List contents:" << endl;
                for (auto it = list.begin(); it != list.end(); ++it) {
                    cout << *it << " ";
                }
                cout << endl;
            }
            break;
        case 9:
            if (list.empty()) {
                cout << "List is already empty!" << endl;
            }
            else {
                list.clear();
                cout << "List deleted." << endl;
            }
            break;
        case 10:
            cout << "Exit." << endl;
            exit(0);
        default:
            cout << "Invalid choice! Please select from 1 to 10." << endl;
        }
    }
}