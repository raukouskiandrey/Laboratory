#pragma once
#include "Entrepreneur.h"
#include "Tourist.h"
#include "ShopAddressList.h"
#include <string>

class Shuttle : public Entrepreneur, public Tourist {
private:
    ShopAddressList shopAddresses;

public:
    Shuttle();
    Shuttle(const Shuttle& other);
    Shuttle& operator=(const Shuttle& other);
    ~Shuttle();

    int getShopSize() const;
    int getShopCapacity() const;

    void AddShopAddress(std::string_view Address);
    void removeShopAddress(int index);
    std::string getShopAddress(int index) const;

    void display() const override;
    void input() override;
    void edit(int number);

private:
    void editShopAddressAdd();
    void editShopAddressDelete();
    void editShopAddresses();
};