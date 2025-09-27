
#include <iostream>
#include <ranges>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

inline void trimInplace(string& s) {
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

int safePositiveInputInt(const string& prompt) {
    while (true) {
        int number = safeInputInt(prompt);
        if ( number > 0)
            return number;
        cout << "The number must be positive." << endl;
    }
}

float safeInputFloat(const string& prompt) {
    static const regex pat(R"(^[+-]?\d+([.,]\d{0,2})?$)");

    while (true) {
        string input = readLineTrimmed(prompt);

        if (!input.empty() && regex_match(input, pat)) {
            ranges::replace(input, ',', '.');

            stringstream ss(input);
            ss.imbue(locale::classic());
            float value;
            ss >> value;

            if (ss && ss.eof()) {
                return value;
            }
            else {
                cout << "Invalid input. Enter number." << endl;
            }
        }
        else {
            cout << "Invalid input." << endl;
        }
    }
}

float safePositiveInputFloat(const string& prompt) {
    while (true) {
        if (float number = safeInputFloat(prompt); number > 0.0f)
            return number;

        cout << "The number must be positive." << endl;
    }
}
