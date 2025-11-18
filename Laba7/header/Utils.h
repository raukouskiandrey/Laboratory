#pragma once

#include <string>

void clearInputBuffer();
std::string readLineTrimmed(const std::string& prompt);
int safeInputInt(const std::string& prompt);
void trimInplace(std::string& s);