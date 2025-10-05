#pragma once
#include <string>

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

    string getName() const;
    string getSurname() const;
    string getPatronymic() const;
    int getBirthYear() const;

    void setName(string_view n);
    void setSurname(string_view sn);
    void setPatronymic(string_view p);
    void setBirthYear(const int& by);

    void displayHuman() const;
    void inputHuman();
};