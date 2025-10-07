#pragma once
#include <string>
using namespace std;


class Human {
private:
    string name = "Fyodor";
    string surname = "Konyukhov";
    string patronymic = "Filippovich";
    int birthYear = 1951;

public:
    Human();
    Human(const string& n, const string& sn, const string& p, int by);
    Human(const Human& other);

    Human& operator=(const Human& other);

    virtual ~Human() = default;

    string getName() const;
    string getSurname() const;
    string getPatronymic() const;
    int getBirthYear() const;

    void setName(string_view n);
    void setSurname(string_view sn);
    void setPatronymic(string_view p);
    void setBirthYear(const int& by);

    void editName();
    void editSurname();
    void editPatronymic();
    void editBirthYear();
    void editHumanDetails();

    void virtual display() const;
    void virtual input();
};