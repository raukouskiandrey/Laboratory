#pragma once
#include <iostream>

struct Date {
    int day;
    int month;
    int year;

    Date();
    Date(int d, int m, int y);

    void input();
    void print() const;
    bool isValid() const;

private:
    static bool isLeapYear(int y);
    static Date getCurrentDate();
};