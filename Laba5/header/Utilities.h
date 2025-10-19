#pragma once
#include <string>
using namespace std;

inline void trimInplace(string& s);
string readLineTrimmed(const string& prompt);
int safeInputInt(const string& prompt);
float safeInputFloat(const string& prompt);