#pragma once
#include "Entrepreneur.h"
#include "Tourist.h"
#include <string>

class Canoe : public Entrepreneur, public Tourist {
private:
    string* shopAddress = nullptr;
    int shopSize = 0;
    int shopCapacity = 3;

    void editShopAddressAdd();
    void editShopAddressDelete();
    void editShopAddresses();

public:
    Canoe();
    Canoe(const Canoe& other);
    Canoe& operator=(const Canoe& other);
    ~Canoe();

    int getShopSize() const;
    int getShopCapacity() const;

    void AddShopAddress(string_view Address);
    void resizeShopArray();

    void display() const override;
    void input() override;
    void edit(int number);
};