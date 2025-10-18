#pragma once
#include "Canoe.h"

class App {
private:
    Canoe* canoes;
    int size;
    int capacity;

    void resize();
    void showMenu() const;
    void addCanoe();
    void listCanoe() const;
    void deleteCanoe();
    void editCanoe();

public:
    App();
    ~App() { delete[] canoes; }
    void run();
};