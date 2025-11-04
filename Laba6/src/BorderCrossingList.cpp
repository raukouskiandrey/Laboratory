#include "BorderCrossingList.h"
#include <iostream>
using namespace std;

BorderCrossingList::BorderCrossingList() {
    borderCross = new borderCrossing[capacity];
}

BorderCrossingList::BorderCrossingList(const BorderCrossingList& other)
    : size(other.size), capacity(other.capacity) {
    borderCross = new borderCrossing[capacity];
    for (int i = 0; i < size; i++) {
        borderCross[i] = other.borderCross[i];
    }
}

BorderCrossingList& BorderCrossingList::operator=(const BorderCrossingList& other) {
    if (this != &other) {
        size = other.size;
        capacity = other.capacity;

        delete[] borderCross;
        borderCross = new borderCrossing[capacity];
        for (int i = 0; i < size; i++) {
            borderCross[i] = other.borderCross[i];
        }
    }
    return *this;
}

BorderCrossingList::~BorderCrossingList() {
    delete[] borderCross;
}

int BorderCrossingList::getSize() const { return size; }
int BorderCrossingList::getCapacity() const { return capacity; }

void BorderCrossingList::editBorderCross(int index, string_view date, string_view country) {
    if (index >= 0 && index < size) {
        borderCross[index].crossingDate = date;
        borderCross[index].country = country;
    }
}

borderCrossing BorderCrossingList::getBorderCross(int index) const {
    if (index >= 0 && index < size) {
        return borderCross[index];
    }
    return borderCrossing();
}

void BorderCrossingList::AddBorderCross(string_view date, string_view country) {
    if (size >= capacity) {
        resizeBorderArray();
    }
    borderCross[size].crossingDate = date;
    borderCross[size].country = country;
    size++;
}

void BorderCrossingList::removeBorderCross(int index) {
    if (index < 0 || index >= size) return;

    for (int i = index; i < size - 1; i++) {
        borderCross[i] = borderCross[i + 1];
    }
    size--;
}

void BorderCrossingList::resizeBorderArray() {
    int newCapacity = (capacity == 0) ? 3 : capacity * 2;
    auto newBorderCross = new borderCrossing[newCapacity];

    if (borderCross != nullptr && size > 0) {
        for (int i = 0; i < size; i++) {
            newBorderCross[i] = borderCross[i];
        }
    }

    if (borderCross != nullptr) {
        delete[] borderCross;
    }

    borderCross = newBorderCross;
    capacity = newCapacity;
}