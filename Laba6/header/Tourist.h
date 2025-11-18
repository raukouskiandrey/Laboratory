#pragma once
#include "Human.h"
#include "BorderCrossingList.h"
#include <string>

class Tourist : public virtual Human {
private:
    std::string passportData = "8545199";
    BorderCrossingList borderCrossings;

public:
    Tourist();
    Tourist(const Tourist& other);
    Tourist& operator=(const Tourist& other);
    ~Tourist();

    std::string getPassportData() const;
    int getBorderCrossingSize() const;

    void setPassportData(std::string_view pasData);

    void editPassport();
    void editBorderCrossings();
    void editBorderCrossingEdit();
    void editBorderCrossingAdd();
    void editBorderCrossingDelete();
    void editTouristDetails();

    void editBorderCross(int index, std::string_view date, std::string_view country);
    borderCrossing getBorderCross(int index) const;

    void AddBorderCross(std::string_view date, std::string_view country);
    void removeBorderCross(int index);

    void display() const override;
    void input() override;
};