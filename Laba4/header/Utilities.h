#pragma once
#include <string>
using namespace std;

inline void trimInplace(string& s);
string readLineTrimmed(const string& prompt);
int safeInputInt(const string& prompt);
int safePositiveInputInt(const string& prompt);
float safeInputFloat(const string& prompt);
float safePositiveInputFloat(const string& prompt);