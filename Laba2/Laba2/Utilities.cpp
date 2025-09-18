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
	cout << "Menu: " << endl
		<< "1 - Perform an operation =" << endl
		<< "2 - Perform an operation +=" << endl
		<< "3 - Exit." << endl;
}

inline void trim_inplace(string& s) {
    while (!s.empty() && isspace(static_cast<unsigned char>(s.front())))
        s.erase(s.begin());
    while (!s.empty() && isspace(static_cast<unsigned char>(s.back())))
        s.pop_back();
}

string readLineTrimmed(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    trim_inplace(input);
    return input;
}

int safeInputInt(const string& prompt) {
    regex pat(R"(^[+-]?\d+$)");

    while (true) {
        string input = readLineTrimmed(prompt);

        if (!input.empty() && regex_match(input, pat)) {
            try {
                return stoi(input);
            }
            catch (const out_of_range&) {
                cout << "Number out of int range.Enter again" << endl;
            }
        }
        else {
            cout << "Invalid input. Enter integer." << endl;
        }
    }
}

String createString() {
    String newString;
    input(newString);
    return newString;
}

void demonstrateAssignment() {
    cout << "=== Operation = ===" << endl;
    cout << "Create first string:" << endl;
    String str1 = createString();

    cout << "Create second string:" << endl;
    String str2 = createString();

    cout << "Before assignment:" << endl;
    cout << "String 1: "; print(str1); cout << endl;
    cout << "String 2: "; print(str2); cout << endl;

    str1 = str2;

    cout << "After assignment (str1 = str2):" << endl;
    cout << "String 1: "; print(str1); cout << endl;
    cout << "String 2: "; print(str2); cout << endl;
}

void demonstrateAdditionAssignment() {
    cout << "=== Operation += ===" << endl;
    cout << "Create first string:" << endl;
    String str1 = createString();

    cout << "Create second string:" << endl;
    String str2 = createString();

    cout << "Before += operation:" << endl;
    cout << "String 1: "; print(str1); cout << endl;
    cout << "String 2: "; print(str2); cout << endl;

    str1 += str2;

    cout << "After += operation (str1 += str2):" << endl;
    cout << "String 1: "; print(str1); cout << endl;
    cout << "String 2: "; print(str2); cout << endl;
}

void run() {
    while (true) {
        showMenu();
        int choice = safeInputInt("Choice: ");
        switch (choice) {
        case 1:
            demonstrateAssignment();
            break;
        case 2:
            demonstrateAdditionAssignment();
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

