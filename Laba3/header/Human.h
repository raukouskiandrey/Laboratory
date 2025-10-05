    #pragma once
#include <string>
using namespace std;

class Human {
private:
    string name;
    string surname;
    string patronymic;
    int birthYear;

public:
    Human();
    Human(string n, string sn, string p, int by);
    Human(const Human& other);

    Human& operator=(const Human& other);

    string getName();
    string getSurname();
    string getPatronymic();
    int getBirthYear();

    void setName(string_view n);
    void setSurname(string_view sn);
    void setPatronymic(string_view p);
    void setBirthYear(const int& by);

    void displayHuman();
    void inputHuman();
};
