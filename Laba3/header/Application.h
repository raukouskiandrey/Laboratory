#pragma once
#include "Canoe.h"

class App {
private:
    Canoe* canoes = nullptr;
    int size = 0;
    int capacity = 0;

    void resize();
    void showMenu() const;
    void addCanoe();
    void listCanoe() const;
    void deleteCanoe();
    void editCanoe();

public:
    App() = default;
    ~App() { delete[] canoes; }
    void run();
};