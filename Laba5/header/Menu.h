#pragma once
#include "SinglyLinkedList.h"
#include "Utilities.h"
#include <iostream>
#include <string>

using namespace std;

void readValue(int& val);
void readValue(float& val);
void readValue(string& val);
void readValue(char& val);

template<typename T>
void runMenu();

void runProgram();