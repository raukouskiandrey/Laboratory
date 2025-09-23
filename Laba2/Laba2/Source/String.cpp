#include "String.h"
#include "utilities.h"
using namespace std;

String::String() : length(0), string(new char[1] {'\0'}) {}

String::String(const char* str)
    : length(myStrlen(str)), string(new char[length + 1]) {
    for (int i = 0; i < length; i++) {
        string[i] = str[i];
    }
    string[length] = '\0';
}

String::String(const String& other) : length(other.length), string(new char[length + 1]) {
	for (int i = 0; i < length; i++) {
		string[i] = other.string[i];
	}
	string[length] = '\0';
}

String::~String() {
    delete[] string;
}

String& String::operator=(const String& other) {
	if (this != &other) { 
		delete[] string; 

		length = other.length;
		string = new char[length + 1];

		for (int i = 0; i < length; i++) {
			string[i] = other.string[i];
		}
		string[length] = '\0';
	}
	return *this;
}

String& String::operator+=(const String& other) {

	char* newString = new char[length + other.length + 1];

	for (int i = 0; i < length; ++i) {
		newString[i] = string[i];
	}
	for (int j = 0; j < other.length; ++j) {
		newString[length + j] = other.string[j];
	}

	newString[length + other.length] = '\0';

	delete[] string;
	string = newString;
	length += other.length;

	return *this;
}


void print(const String& string) {
    cout << string.string;
}

void input(String& string) {
    char ch;
    int length = 0;
    int capacity = 10;

    delete[] string.string;
    string.string = new char[capacity];

    cout << "Enter string:" << endl;
    while (cin.get(ch) && ch != '\n') {
        if (length + 1 >= capacity) {
            capacity *= 2;
            auto newBuffer = new char[capacity];
            for (int i = 0; i < length; i++) {
                newBuffer[i] = string.string[i];
            }
            delete[] string.string;
            string.string = newBuffer;
        }
        string.string[length++] = ch;
    }
    string.string[length] = '\0';
    string.length = length;
}
