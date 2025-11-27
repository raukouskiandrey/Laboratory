#include"Menu.h"
#include"DoublyLinkedList.h"
#include "Utilities.h"
#include"Algorithm.h"
#include<iostream>
using namespace std;

void readValue(int& val) {
    val = safeInputInt("");
}

void readValue(float& val) {
    val = safeInputFloat("");
}

void readValue(string& val) {
    val = readLineTrimmed("");
    while (val.empty()) {
        cout << "String cannot be empty! Please enter text: ";
        val = readLineTrimmed("");
    }
}

void readValue(char& val) {
    while (true) {
        string input = readLineTrimmed("");
        if (input.length() == 1) {
            val = input[0];
            break;
        }
        else {
            cout << "Please enter exactly one character: ";
        }
    }
}

void showMenu() {
    cout << "Menu :" << endl;
    cout << "1. Создать новый список" << endl;
    cout << "2. Добавить в начало" << endl;
    cout << "3. Добавить в конец" << endl;
    cout << "4. Удалить начальный элемент" << endl;
    cout << "5. Удалить последний элемент" << endl;
    cout << "6. Поиск" << endl;
    cout << "7. Сортировка" << endl;
    cout << "8. Показать весь список" << endl;
    cout << "9. Удалить весь список" << endl;
    cout << "10. Выход" << endl;
}

void createList() {
    int typeChoice;
    bool validChoice = false;

    do {
        cout << "Типы:" << endl;
        cout << "1. int" << endl;
        cout << "2. float" << endl;
        cout << "3. string" << endl;
        cout << "4. char" << endl;

        typeChoice = safeInputInt("Выберите тип: ");

        switch (typeChoice) {
        case 1:
            runMenu<int>();
            validChoice = true;
            break;
        case 2:
            runMenu<float>();
            validChoice = true;
            break;
        case 3:
            runMenu<string>();
            validChoice = true;
            break;
        case 4:
            runMenu<char>();
            validChoice = true;
            break;
        default:
            cout << "Неверный выбор! Пожалуйста, выберите от 1 до 4." << endl;
        }
    } while (!validChoice);
}

template<typename t>
void runMenu() {
    DoublyLinkedList<t> list;
    Algorithm<t> algo;
    t value;
    int choice;

    while (true) {
        showMenu();
        
        choice = safeInputInt("Выберите: ");

            switch (choice) {
            case 1:
                list.clear();
                cout << "Список очищен. Создайте новый список." << endl;
                createList();
                break;
            case 2:
                cout << "Введите данные: ";
                readValue(value);
                list.pushFront(value);
                cout << "Элемент добавлен в начало." << endl;
                break;
            case 3:
                cout << "Введите данные: ";
                readValue(value);
                list.pushBack(value);
                cout << "Элемент добавлен в конец." << endl;
                break;
            case 4:
                if (list.empty()) {
                    cout << "Список пустой! Нечего удалять." << endl;
                }
                else {
                    list.popFront();
                    cout << "Первый элемент удален." << endl;
                }
                break;
            case 5:
                if (list.empty()) {
                    cout << "Список пустой! Нечего удалять." << endl;
                }
                else {
                    list.popBack();
                    cout << "Последний элемент удален." << endl;
                }
                break;
            case 6:
                if (list.empty()) {
                    cout << "Список пустой! Нечего искать." << endl;
                }
                else {
                    cout << "Введите данные для поиска: ";
                    readValue(value);
                    if (algo.find(list, value)) {
                        cout << "Значение найдено в списке." << endl;
                    }
                    else {
                        cout << "Не найдено." << endl;
                    }
                }
                break;
            case 7:
                if (list.empty()) {
                    cout << "Список пустой! Нечего сортировать." << endl;
                }
                else if (list.getSize() == 1) {
                    cout << "В списке только один элемент - сортировка не требуется." << endl;
                }
                else {
                    algo.sort(list);
                    cout << "Список отсортирован." << endl;
                }
                break;
            case 8:
                if (list.empty()) {
                    cout << "Список пустой!" << endl;
                }
                else {
                    cout << "Содержимое списка:" << endl;
                    for (auto it = list.begin(); it != list.end(); ++it) {
                        cout << *it << " ";
                    }
                    cout << endl;
                }
                break;
            case 9:
                if (list.empty()) {
                    cout << "Список уже пустой!" << endl;
                }
                else {
                    list.clear();
                    cout << "Список удален." << endl;
                }
                break;
            case 10:
                cout << "Выход." << endl;
                return;
            default:
                cout << "Неверный выбор! Пожалуйста, выберите от 1 до 10." << endl;
            }
    }
}