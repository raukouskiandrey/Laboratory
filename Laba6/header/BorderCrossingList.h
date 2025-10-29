#pragma once
#include <string>

struct borderCrossing {
    std::string crossingDate;
    std::string country;
};

class BorderCrossingList {
private:
    borderCrossing* borderCross = nullptr;
    int size = 0;
    int capacity = 3;

public:
    BorderCrossingList();
    BorderCrossingList(const BorderCrossingList& other);
    BorderCrossingList& operator=(const BorderCrossingList& other);
    ~BorderCrossingList();

    int getSize() const;
    int getCapacity() const;

    void editBorderCross(int index, std::string_view date, std::string_view country);
    borderCrossing getBorderCross(int index) const;

    void AddBorderCross(std::string_view date, std::string_view country);
    void removeBorderCross(int index);
    void resizeBorderArray();
};