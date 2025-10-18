#include "Application.h"
#include "Utilities.h"
#include <iostream>
using namespace std;

void App::resize() {
    int newCapacity = (capacity == 0) ? 2 : capacity * 2;
    auto newArr = new Canoe[newCapacity];

    for (int i = 0; i < size; ++i) {
        newArr[i] = canoes[i];
    }

    delete[] canoes;
    canoes = newArr;
    capacity = newCapacity;

    cout << "Array resized to capacity: " << capacity << endl;
}

void App::showMenu() const {
    cout << "Menu: " << endl;
    cout << "1. Add canoe" << endl;
    cout << "2. Delete canoe" << endl;
    cout << "3. View all canoes" << endl;
    cout << "4. Edit canoe" << endl;
    cout << "5. Exit" << endl;
}

void App::addCanoe() {
    cout << "Adding canoe #" << size + 1 << endl;

    cout << "Choose input method:" << endl;
    cout << "1. Manual input" << endl;
    cout << "2. Test values (adds 3 canoes at once)" << endl;

    int inputChoice = safeInputInt("Choice: ");

    if (inputChoice == 1) {
        Canoe c;
        c.input();

        while (size >= capacity)
            resize();
        ++size;
        canoes[size - 1] = c;
        cout << "Canoe added." << endl;
    }
    else if (inputChoice == 2) {

        Canoe c1;
        c1.setName("Alexandr");
        c1.setSurname("Gurich");
        c1.setPatronymic("Alexandrovich");
        c1.setBirthYear(1985);
        c1.setLicenseNumber(1001);
        c1.setRegAddress(" Street 123, Oslo");
        c1.setTaxID(55001);
        c1.setPassportData("NO123456");

        for (int i = c1.Entrepreneur::getTaxPaymentSize() - 1; i >= 0; i--) {
            c1.removeTaxPayment(i);
        }
        c1.AddTaxPayment("2024-03-10", 1200.0f);
        c1.AddTaxPayment("2024-06-15", 1800.0f);

        for (int i = c1.Tourist::getBorderCrossingSize() - 1; i >= 0; i--) {
            c1.removeBorderCross(i);
        }
        c1.AddBorderCross("2024-01-15", "Norway");
        c1.AddBorderCross("2024-07-20", "Sweden");

        c1.AddShopAddress(" Store, Oslo");
        c1.AddShopAddress("Adventure Equipment, Bergen");

        Canoe c2;
        c2.setName("Maria");
        c2.setSurname("Schmidt");
        c2.setPatronymic("Annavna");
        c2.setBirthYear(1978);
        c2.setLicenseNumber(2002);
        c2.setRegAddress("Business Avenue 45, Berlin");
        c2.setTaxID(66002);
        c2.setPassportData("DE987654");

        for (int i = c2.Entrepreneur::getTaxPaymentSize() - 1; i >= 0; i--) {
            c2.removeTaxPayment(i);
        }
        c2.AddTaxPayment("2024-01-05", 2500.0f);
        c2.AddTaxPayment("2024-04-10", 3200.0f);
        c2.AddTaxPayment("2024-09-15", 2800.0f);

        for (int i = c2.Tourist::getBorderCrossingSize() - 1; i >= 0; i--) {
            c2.removeBorderCross(i);
        }
        c2.AddBorderCross("2024-02-14", "Germany");
        c2.AddBorderCross("2024-05-22", "France");
        c2.AddBorderCross("2024-08-30", "Netherlands");

        c2.AddShopAddress("Business Center, Berlin");
        c2.AddShopAddress("Trade Plaza, Paris");
        c2.AddShopAddress("Commerce Hub, Amsterdam");

        Canoe c3;
        c3.setName("James");
        c3.setSurname("Chen");
        c3.setPatronymic("Wei");
        c3.setBirthYear(1992);
        c3.setLicenseNumber(3003);
        c3.setRegAddress("World Street 789, Tokyo");
        c3.setTaxID(77003);
        c3.setPassportData("JP456789");

        for (int i = c3.Entrepreneur::getTaxPaymentSize() - 1; i >= 0; i--) {
            c3.removeTaxPayment(i);
        }
        c3.AddTaxPayment("2024-01-20", 1500.0f);
        c3.AddTaxPayment("2024-03-25", 2200.0f);
        c3.AddTaxPayment("2024-07-12", 1900.0f);
        c3.AddTaxPayment("2024-11-05", 2600.0f);

        for (int i = c3.Tourist::getBorderCrossingSize() - 1; i >= 0; i--) {
            c3.removeBorderCross(i);
        }
        c3.AddBorderCross("2024-01-10", "Japan");
        c3.AddBorderCross("2024-04-18", "Australia");
        c3.AddBorderCross("2024-08-05", "Brazil");
        c3.AddBorderCross("2024-12-15", "South Africa");

        c3.AddShopAddress("Global Market, Tokyo");
        c3.AddShopAddress("Travel Goods, Sydney");
        c3.AddShopAddress("Souvenir Center, Rio");
        c3.AddShopAddress("Cultural Store, Cape Town");

        while (size + 3 >= capacity)
            resize();

        canoes[size++] = c1;
        canoes[size++] = c2;
        canoes[size++] = c3;

    }
    else {
        cout << "Invalid choice. Using manual input." << endl;
        Canoe c;
        c.input();

        while (size >= capacity)
            resize();
        ++size;
        canoes[size - 1] = c;
        cout << "Canoe added." << endl;
    }
}

void App::listCanoe() const {
    if (size == 0) {
        cout << "The list is empty." << endl;
        return;
    }
    cout << "Canoe list" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "\n#" << (i + 1) << "\n";
        canoes[i].display();
    }
}

void App::deleteCanoe() {
    if (size == 0) {
        cout << "There is nothing to delete, the list is empty." << endl;
        return;
    }
    int number = safeInputInt("Enter canoe number to delete: ");
    if (number > 0 && number <= size) {
        for (int i = number - 1; i < size - 1; ++i)
            canoes[i] = canoes[i + 1];
        --size;
        cout << "Canoe deleted." << endl;
    }
    else {
        cout << "No such number!!!" << endl;
    }
}

void App::editCanoe() {
    if (size == 0) {
        cout << "There is nothing to edit, the list is empty." << endl;
        return;
    }
    int number = safePositiveInputInt("Enter canoe number to edit: ");
    if (number > 0 && number <= size) {
        canoes[number - 1].edit(number);
    }
    else {
        cout << "No such number!!!" << endl;
    }
}

void App::run() {
    while (true) {
        showMenu();
        int choice = safeInputInt("Choice: ");
        switch (choice) {
        case 1:
            addCanoe();
            break;
        case 2:
            deleteCanoe();
            break;
        case 3:
            listCanoe();
            break;
        case 4:
            editCanoe();
            break;
        case 5:
            cout << "Exit." << endl;
            return;
        default:
            cout << "Invalid menu item. " << endl;
        }
    }
}