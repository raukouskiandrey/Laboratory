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
    borderCrossing* borderCross;
    int size;
    int capacity;
   
public:
    Tourist();
    Tourist(const Tourist& other);
    Tourist& operator=(const Tourist& other);
    ~Tourist();

    string getPassportData();
    int getSize() const;
    int getCapacity() const;

    void setPassportData(string_view pasData);

    void editBorderCross(int index, string_view date, string_view country);
    borderCrossing getBorderCross(int index) const;

    void AddBorderCross(string_view date, string_view country);
    void removeBorderCross(int index);
    void resizeBorderArray();
    void displayTourist();
    void inputTourist();
};