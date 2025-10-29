#pragma once
#include "Shuttle.h"

class App {
private:
    Shuttle* shuttles;
    int size;
    int capacity;

    void resize();
    void showMenu() const;
    void addShuttle();
    void listShuttle() const;
    void deleteShuttle();
    void editShuttle();

public:
    App();
    ~App() { delete[] shuttles; }
    void run();
};