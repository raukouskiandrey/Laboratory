#include "ShopAddressList.h"
#include <iostream>
using namespace std;

ShopAddressList::ShopAddressList() {
    shopAddress = new string[shopCapacity];
}

ShopAddressList::ShopAddressList(const ShopAddressList& other)
    : shopSize(other.shopSize), shopCapacity(other.shopCapacity) {
    shopAddress = new string[shopCapacity];
    for (int i = 0; i < shopSize; i++) {
        shopAddress[i] = other.shopAddress[i];
    }
}

ShopAddressList& ShopAddressList::operator=(const ShopAddressList& other) {
    if (this != &other) {
        shopSize = other.shopSize;
        shopCapacity = other.shopCapacity;

        delete[] shopAddress;
        shopAddress = new string[shopCapacity];
        for (int i = 0; i < shopSize; i++) {
            shopAddress[i] = other.shopAddress[i];
        }
    }
    return *this;
}

ShopAddressList::~ShopAddressList() {
    delete[] shopAddress;
}

int ShopAddressList::getSize() const { return shopSize; }
int ShopAddressList::getCapacity() const { return shopCapacity; }

void ShopAddressList::AddShopAddress(string_view Address) {
    if (shopSize >= shopCapacity) {
        resizeShopArray();
    }
    shopAddress[shopSize] = string(Address);
    shopSize++;
}

void ShopAddressList::removeShopAddress(int index) {
    if (index < 0 || index >= shopSize) return;

    for (int i = index; i < shopSize - 1; i++) {
        shopAddress[i] = shopAddress[i + 1];
    }
    shopSize--;
}

string ShopAddressList::getShopAddress(int index) const {
    if (index >= 0 && index < shopSize) {
        return shopAddress[index];
    }
    return string();
}

void ShopAddressList::resizeShopArray() {
    shopCapacity = (shopCapacity == 0) ? 3 : shopCapacity * 2;
    auto newShopAddress = new string[shopCapacity];
    for (int i = 0; i < shopSize; i++) {
        newShopAddress[i] = shopAddress[i];
    }
    delete[] shopAddress;
    shopAddress = newShopAddress;
}