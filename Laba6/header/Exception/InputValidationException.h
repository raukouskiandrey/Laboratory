#pragma once
#include <stdexcept>
#include <string>

class InputValidationException :public std::runtime_error {
	using std::runtime_error::runtime_error;
};

void trimInplace(std::string& s);
std::string readLineTrimmed(const std::string& prompt);

int safeInputInt(const std::string& prompt);
int safePositiveInputInt(const std::string& prompt);

float safeInputFloat(const std::string& prompt);
float safePositiveInputFloat(const std::string& prompt);

std::string safeInputWord(const std::string& prompt);
std::string safeInputLine(const std::string& prompt);

std::string securelyInputWord(const std::string& prompt);
int securelyInputPositiveInt(const std::string& prompt);
int securelyInputInt(const std::string& prompt);
float securelyInputPositiveFloat(const std::string& prompt);
std::string securelyInputLine(const std::string& prompt);