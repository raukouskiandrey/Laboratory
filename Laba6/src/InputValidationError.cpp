#include <iostream>
#include <regex>
#include <ranges>
#include <sstream>  
#include <algorithm> 

#include "InputValidationException.h"
#include"EmptyInputException.h"
#include"InvalidArgumentException.h"
#include"OutOfRangeException.h"
#include"NonPositiveNumberException.h"

using namespace std;

void trimInplace(string& s) {
    while (!s.empty() && isspace(static_cast<unsigned char>(s.front())))
        s.erase(s.begin());
    while (!s.empty() && isspace(static_cast<unsigned char>(s.back())))
        s.pop_back();
}
 
string readLineTrimmed(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    trimInplace(input);
    return input;
}

int safeInputInt(const string& prompt) {
    regex pat(R"(^[+-]?\d+$)");
    string input = readLineTrimmed(prompt);

    if (input.empty()) {
        throw EmptyInputException("Input cannot be empty: '" + input + "'");
    }

    if (!regex_match(input, pat)) {
        throw InvalidArgumentException("Invalid integer input: '" + input + "'");
    }
    try {
        return stoi(input);
    }
    catch(const invalid_argument& e){
        throw InvalidArgumentException("Invalid integer input: '" + input + "'");
    }
    catch(const out_of_range& e){
        throw OutOfRangeException("Integer range exceeded: '" + input + "'");
    }
}

int safePositiveInputInt(const string& prompt) {
    int number = safeInputInt(prompt);
    if (number <= 0) {
        throw NonPositiveNumberException("The number must be positive.");
    }
    return number;
}

float safeInputFloat(const string& prompt) {
    static const regex pat(R"(^[+-]?\d+([.,]\d{0,2})?$)");

    while (true) {
        string input = readLineTrimmed(prompt);

        if (input.empty()) {
            throw EmptyInputException("Input cannot be empty: '" + input + "'");
        }

        if (!regex_match(input, pat)) {
            throw InvalidArgumentException("Invalid float input: '" + input + "'");
        }

            std::replace(input.begin(), input.end(), ',', '.');

            stringstream ss(input);
            ss.imbue(locale::classic());
            float value;
            ss >> value;

            if (!ss || !ss.eof()) {
                throw InvalidArgumentException("Invalid float input: '" + input + "'");
            }

            return value;
    }
}

float safePositiveInputFloat(const string& prompt) {
    float number = safeInputFloat(prompt);
    if (number <= 0.0f) {
    throw NonPositiveNumberException("The number must be positive.");
    }
    return number;
}

string safeInputWord(const string& prompt) {
    regex pat(R"(^\S+$)");
    string input = readLineTrimmed(prompt);

    if (input.empty()) {
        throw EmptyInputException("Input cannot be empty: '" + input + "'");
    }
    if (!regex_match(input, pat)) {
        throw InvalidArgumentException("Invalid word input: '" + input + "'");
    }
    return input;
}

string safeInputLine(const string& prompt) {
    string input = readLineTrimmed(prompt);
    if (input.empty())
        throw EmptyInputException("Input cannot be empty.");
    return input;
}

string securelyInputWord(const string& prompt) {
    while (true) {
        try {
            return safeInputWord(prompt);
        }
        catch (const InvalidArgumentException& e) {
            cout << "Invalid argument: " << e.what() << ". Please try again.\n";
        }
        catch (const EmptyInputException& e) {
            cout << "Empty Input: " << e.what() << ". Please try again.\n";
        }
    }
}

int securelyInputPositiveInt(const string& prompt) {
    while (true) {
        try {
            return safePositiveInputInt(prompt);
        }
        catch (const InvalidArgumentException& e) {
            cout << "Invalid argument: " << e.what() << ". Please try again.\n";
        }
        catch (const OutOfRangeException& e) {
            cout << "Value out of range: " << e.what() << ". Please try again.\n";
        }
        catch (const EmptyInputException& e) {
            cout << "Empty input: " << e.what() << ". Please try again.\n";
        }
        catch (const NonPositiveNumberException& e) {
            cout << "Non-positive number: " << e.what() << ". Please try again.\n";
        }
    }
}

int securelyInputInt(const string& prompt) {
    while (true) {
        try {
            return safeInputInt(prompt);
        }
        catch (const InvalidArgumentException& e) {
            cout << "Invalid argument: " << e.what() << ". Please try again.\n";
        }
        catch (const OutOfRangeException& e) {
            cout << "Value out of range: " << e.what() << ". Please try again.\n";
        }
        catch (const EmptyInputException& e) {
            cout << "Empty input: " << e.what() << ". Please try again.\n";
        }
    }
}

float securelyInputPositiveFloat(const string& prompt) {
    while (true) {
        try {
            return safePositiveInputFloat(prompt);
        }
        catch (const InvalidArgumentException& e) {
            cout << "Invalid argument: " << e.what() << ". Please try again.\n";
        }
        catch (const OutOfRangeException& e) {
            cout << "Value out of range: " << e.what() << ". Please try again.\n";
        }
        catch (const EmptyInputException& e) {
            cout << "Empty input" << e.what() << ". Please try again.\n";
        }
        catch (const NonPositiveNumberException& e) {
            cout << "No positive number: " << e.what() << ". Please try again.\n";
        }
    }
}

string securelyInputLine(const string& prompt) {
    while (true) {
        try {
            return safeInputLine(prompt);
        }
        catch (const EmptyInputException& e) {
            cout << "Empty Input: " << e.what() << ". Please try again.\n";
        }
    }
}