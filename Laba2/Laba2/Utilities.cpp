#include "Utilities.h"
#include <regex>
#include <iostream>
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
	cout<< "3 - Exit." << endl;
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

    cout << "Before operation:" <<operationName<< endl;
    cout << "String 1: "; print(str1); cout << endl;
    cout << "String 2: "; print(str2); cout << endl;

    if (operationType == 0){
        str1 = str2;
    }
    else {  
        str1 += str2;
    }

    cout << "After operation:" <<operationName<< endl;
    cout << "String 1: "; print(str1); cout << endl;
    cout << "String 2: "; print(str2); cout << endl;
}


void run() {
    while (true) {
        showMenu();
        int choice;
        cin >> choice;
        switch (choice) {
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

