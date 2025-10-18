#pragma once
#include "Entrepreneur.h"
#include "Tourist.h"
#include "ShopAddressList.h"
#include <string>

class Canoe : public Entrepreneur, public Tourist {
private:
    ShopAddressList shopAddresses; 

public:
    Canoe() = default;
    Canoe(const Canoe& other);
    Canoe& operator=(const Canoe& other);
    ~Canoe() = default;

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