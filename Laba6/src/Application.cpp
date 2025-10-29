#include "Application.h"
#include "Utilities.h"
#include <iostream>
using namespace std;

App::App() : shuttles(nullptr), size(0), capacity(0) {}

void App::resize() {
    int newCapacity = (capacity == 0) ? 2 : capacity * 2;
    auto newArr = new Shuttle[newCapacity];

    for (int i = 0; i < size; ++i) {
        newArr[i] = shuttles[i];
    }

    delete[] shuttles;
    shuttles = newArr;
    capacity = newCapacity;

    cout << "Array resized to capacity: " << capacity << endl;
}

void App::showMenu() const {
    cout << "Menu: " << endl;
    cout << "1. Add shuttle" << endl;
    cout << "2. Delete shuttle" << endl;
    cout << "3. View all shuttles" << endl;
    cout << "4. Edit shuttle" << endl;
    cout << "5. Exit" << endl;
}

static string securelyInputWord(const string& prompt) {
    while (true) {
        try {
            return safeInputWord(prompt);
        }
        catch (const InputValidationError& e) {
            cout << "Invalid argument: " << e.what() << ". Please try again.\n";
        }
        catch (const out_of_range& e) {
            cout << "Value out of range: " << e.what() << ". Please try again.\n";
        }
    }
}

static int securelyInputPositiveInt(const string& prompt) {
    while (true) {
        try {
            return safePositiveInputInt(prompt);
        }
        catch (const InputValidationError& e) {
            cout << "Invalid argument: " << e.what() << ". Please try again.\n";
        }
        catch (const out_of_range& e) {
            cout << "Value out of range: " << e.what() << ". Please try again.\n";
        }
    }
}

static int securelyInputInt(const string& prompt) {
    while (true) {
        try {
            return safeInputInt(prompt);
        }
        catch (const InputValidationError& e) {
            cout << "Invalid argument: " << e.what() << ". Please try again.\n";
        }
        catch (const out_of_range& e) {
            cout << "Value out of range: " << e.what() << ". Please try again.\n";
        }
    }

}
void App::addShuttle() {
    cout << "Adding shuttle #" << size + 1 << endl;

    cout << "Choose input method:" << endl;
    cout << "1. Manual input" << endl;
    cout << "2. Test values (adds 3 shuttles at once)" << endl;

    int inputChoice = securelyInputInt("Choice: ");

    if (inputChoice == 1) {
        Shuttle c;
        c.input();

        if (size >= capacity) {
            resize();
        }

        shuttles[size] = c;
        ++size;
        cout << "Shuttle added." << endl;
    }
    else if (inputChoice == 2) {
        while (size + 3 >= capacity) {
            resize();
        }

        Shuttle c1;
        c1.setName("Alexandr");
        c1.setSurname("Gurich");
        c1.setPatronymic("Alexandrovich");
        c1.setBirthYear(1985);
        c1.setLicenseNumber(1001);
        c1.setRegAddress(" Street 123, Oslo");
        c1.setTaxID(55001);
        c1.setPassportData("NO123456");

        int taxSize1 = c1.Entrepreneur::getTaxPaymentSize();
        for (int i = taxSize1 - 1; i >= 0; i--) {
            c1.removeTaxPayment(i);
        }
        c1.AddTaxPayment("2024-03-10", 1200.0f);
        c1.AddTaxPayment("2024-06-15", 1800.0f);

        int borderSize1 = c1.Tourist::getBorderCrossingSize();
        for (int i = borderSize1 - 1; i >= 0; i--) {
            c1.removeBorderCross(i);
        }
        c1.AddBorderCross("2024-01-15", "Norway");
        c1.AddBorderCross("2024-07-20", "Sweden");

        c1.AddShopAddress(" Store, Oslo");
        c1.AddShopAddress("Adventure Equipment, Bergen");

        Shuttle c2;
        c2.setName("Maria");
        c2.setSurname("Schmidt");
        c2.setPatronymic("Annavna");
        c2.setBirthYear(1978);
        c2.setLicenseNumber(2002);
        c2.setRegAddress("Business Avenue 45, Berlin");
        c2.setTaxID(66002);
        c2.setPassportData("DE987654");

        int taxSize2 = c2.Entrepreneur::getTaxPaymentSize();
        for (int i = taxSize2 - 1; i >= 0; i--) {
            c2.removeTaxPayment(i);
        }
        c2.AddTaxPayment("2024-01-05", 2500.0f);
        c2.AddTaxPayment("2024-04-10", 3200.0f);
        c2.AddTaxPayment("2024-09-15", 2800.0f);

        int borderSize2 = c2.Tourist::getBorderCrossingSize();
        for (int i = borderSize2 - 1; i >= 0; i--) {
            c2.removeBorderCross(i);
        }
        c2.AddBorderCross("2024-02-14", "Germany");
        c2.AddBorderCross("2024-05-22", "France");
        c2.AddBorderCross("2024-08-30", "Netherlands");

        c2.AddShopAddress("Business Center, Berlin");
        c2.AddShopAddress("Trade Plaza, Paris");
        c2.AddShopAddress("Commerce Hub, Amsterdam");

        Shuttle c3;
        c3.setName("James");
        c3.setSurname("Chen");
        c3.setPatronymic("Wei");
        c3.setBirthYear(1992);
        c3.setLicenseNumber(3003);
        c3.setRegAddress("World Street 789, Tokyo");
        c3.setTaxID(77003);
        c3.setPassportData("JP456789");

        int taxSize3 = c3.Entrepreneur::getTaxPaymentSize();
        for (int i = taxSize3 - 1; i >= 0; i--) {
            c3.removeTaxPayment(i);
        }
        c3.AddTaxPayment("2024-01-20", 1500.0f);
        c3.AddTaxPayment("2024-03-25", 2200.0f);
        c3.AddTaxPayment("2024-07-12", 1900.0f);
        c3.AddTaxPayment("2024-11-05", 2600.0f);

        int borderSize3 = c3.Tourist::getBorderCrossingSize();
        for (int i = borderSize3 - 1; i >= 0; i--) {
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

        shuttles[size++] = c1;
        shuttles[size++] = c2;
        shuttles[size++] = c3;

        cout << "3 test shuttles added." << endl;
    }
    else {
        cout << "Invalid choice. Using manual input." << endl;
        Shuttle c;
        c.input();

        if (size >= capacity) {
            resize();
        }

        shuttles[size] = c;
        ++size;
        cout << "Shuttle added." << endl;
    }
}

void App::listShuttle() const {
    if (size == 0) {
        cout << "The list is empty." << endl;
        return;
    }
    cout << "Shuttle list" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "\n#" << (i + 1) << "\n";
        shuttles[i].display();
    }
}

void App::deleteShuttle() {
    if (size == 0) {
        cout << "There is nothing to delete, the list is empty." << endl;
        return;
    }
    while (true) {
        try {
            int number = securelyInputPositiveInt("Enter shuttle number to delete: ");
            if (number > size) {
                throw InputValidationError("Number must be smaller size: '" + to_string(number) + "'");
            }
            for (int i = number - 1; i < size - 1; ++i) {
                shuttles[i] = shuttles[i + 1];
            }
            --size;
            cout << "Shuttle deleted." << endl;
            break;
        }
        catch (InputValidationError& e) {
            cout << "Invalid argument: " << e.what() << ". Please try again.\n";
        }
    }
}

void App::editShuttle() {
    if (size == 0) {
        cout << "There is nothing to edit, the list is empty." << endl;
        return;
    }
    while (true) {
        try {
            int number = securelyInputPositiveInt("Enter shuttle number to edit: ");
            if (number > size) {
                throw InputValidationError("Number must be smaller size: '" + to_string(number) + "'");
            }
            shuttles[number - 1].edit(number);
            break;
        }
        catch (InputValidationError& e) {
                cout << "Invalid argument: " << e.what() << ". Please try again.\n";
        }
    }
}

void App::run() {
    while (true) {
        showMenu();
        try {
            int choice = securelyInputInt("Choice: ");
            switch (choice) {
            case 1:
                addShuttle();
                break;
            case 2:
                deleteShuttle();
                break;
            case 3:
                listShuttle();
                break;
            case 4:
                editShuttle();
                break;
            case 5:
                cout << "Exit." << endl;
                return;
            default:
                cout << "Invalid menu item. " << endl;
            }
        }
        catch (const InputValidationError& e) {
            cout << "Invalid argument: " << e.what() << "\nPlease try again.\n";
        }
       
    }
}