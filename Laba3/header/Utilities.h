#pragma once
#include <string>

void trimInplace(std::string& s);
std::string readLineTrimmed(const std::string& prompt);
int safeInputInt(const std::string& prompt);
int safePositiveInputInt(const std::string& prompt);
float safeInputFloat(const std::string& prompt);  
float safePositiveInputFloat(const std::string& prompt);  