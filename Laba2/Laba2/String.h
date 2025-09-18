#pragma once
#include<iostream>

class String {
private:
	char* string;
	int length;
public:

	String();
	String(const char* str);
	String(const String& other);
	~String();

	String& operator=(const String &other);
	String& operator+=(const String& other);

	friend void print(const String&);
	friend void input(String&);
};	