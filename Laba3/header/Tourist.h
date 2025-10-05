#pragma once
#include "Human.h"
#include <string>

struct borderCrossing {
    string crossingDate;
    string country;
};

class Tourist : public Human {
private:
    string passportData = "8545199";
    borderCrossing* borderCross = nullptr;
    int size = 0;
    int capacity = 3;

public:
    Tourist();
    Tourist(const Tourist& other);
    Tourist& operator=(const Tourist& other);
    ~Tourist();

    string getPassportData() const;
    int getSize() const;
    int getCapacity() const;

    void setPassportData(string_view pasData);

    void editBorderCross(int index, string_view date, string_view country);
    borderCrossing getBorderCross(int index) const;

    void AddBorderCross(string_view date, string_view country);
    void removeBorderCross(int index);
    void resizeBorderArray();
    void displayTourist() const;
    void inputTourist();
};