#pragma once
#include <string>

class ShopAddressList {
private:
    std::string* shopAddress = nullptr;
    int shopSize = 0;
    int shopCapacity = 3;

public:
    ShopAddressList();
    ShopAddressList(const ShopAddressList& other);
    ShopAddressList& operator=(const ShopAddressList& other);
    ~ShopAddressList();

    int getSize() const;
    int getCapacity() const;

    void AddShopAddress(std::string_view Address);
    void removeShopAddress(int index);
    std::string getShopAddress(int index) const;
    void resizeShopArray();
};