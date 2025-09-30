#include <regex>
#include <iostream>
#include <cstring>
#include <cctype>

#include"../header/utilities.h"
#include"../header/String.h"

using namespace std;

int myStrlen(const char* str) {
    if (str == nullptr) {
        return 0;
    }
    int len = 0;

    for (int ind = 0; str[ind] != '\0'; ind++) {
        len++;
    }

    return len;
}

void showMenu() {
    cout << "Menu: " << endl;
    cout << "1 - Assign a value to the first row" << endl;
    cout << "2 - String addition" << endl;
    cout << "3 - Exit." << endl;
}

String createString() {
    String newString;
    input(newString);
    return newString;
}

void Operation(int operationType) {
    const char* operationName = (operationType == 0) ? "=" : "+=";

    cout << "Operation: " << operationName << endl;
    cout << "Create first string:" << endl;
    String str1 = createString();

    cout << "Create second string:" << endl;
    String str2 = createString();

    cout << "Before operation:" << operationName << endl;
    cout << "String 1: "; print(str1); cout << endl;
    cout << "String 2: "; print(str2); cout << endl;

    if (operationType == 0) {
        str1 = str2;
    }
    else {
        str1 += str2;
    }

    cout << "After operation:" << operationName << endl;
    cout << "String 1: "; print(str1); cout << endl;
    cout << "String 2: "; print(str2); cout << endl;
}

int safeInputInt() {
    char input[10];
    int value;

    while (true) {
        cout << "Enter your choice: ";
        cin.getline(input, 10);

        if (input[0] == '\0') {
            cout << "Error: Empty input. Please enter a number." << endl;
            continue;
        }

        bool isValid = true;
        for (int i = 0; input[i] != '\0'; i++) {
            if (!isdigit(input[i])) {
                isValid = false;
                break;
            }
        }

        if (!isValid) {
            cout << "Error: Invalid input. Please enter a valid integer number." << endl;
            continue;
        }
        value = 0;
        for (int i = 0; input[i] != '\0'; i++) {
            value = value * 10 + (input[i] - '0');
        }

        return value;
    }
}

void run() {
    while (true) {
        showMenu();
        switch (int choice = safeInputInt();choice) {
        case 1:
            Operation(0);
            break;
        case 2:
            Operation(1);
            break;
        case 3:
            cout << "Exit." << endl;
            return;
        default:
            cout << "Invalid menu item. " << endl;
        }
        cout << endl;
    }
}