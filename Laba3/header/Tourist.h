#pragma once
#include "Human.h"
#include <string>
using namespace std;

struct borderCrossing {
    string crossingDate;
    string country;
};

class Tourist : public Human {
private:
    string passportData;
    int size;
    int capacity;
    borderCrossing* borderCross;

public:
    Tourist();
    Tourist(const Tourist& other);
    Tourist& operator=(const Tourist& other);
    ~Tourist();

    string getPassportData();
    int getSize() const;
    int getCapacity() const;

    void setPassportData(string pasData);

    void editBorderCross(int index, const string& date, const string& country);
    borderCrossing getBorderCross(int index) const;

    void AddBorderCross(const string& date, string country);
    void removeBorderCross(int index);
    void resizeBorderArray();
    void displayTourist();
    void inputTourist();
};