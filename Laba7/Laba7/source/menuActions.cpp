#include "menuActions.h"
#include "Utils.h"
#include <iostream>
#include <limits>
#include <stdexcept>
#include <filesystem>

using namespace std;

void printMenu() {
    std::cout << "\n=== File Operations Menu ===" << std::endl;
    std::cout << "1. Open file" << std::endl;
    std::cout << "2. Write string to file" << std::endl;
    std::cout << "3. Read character by position" << std::endl;
    std::cout << "4. Show file size" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

void handleCreateFile(FileReader& fileReader, string& filePath) {
    while (true) {
        try {
            cout << "Enter file path: ";
            string inputPath;
            getline(std::cin, inputPath);
            trimInplace(inputPath);

            if (!inputPath.empty()) {
                filePath = inputPath;
            }
            else {
                throw invalid_argument("File path cannot be empty");
            }

            int result = fileReader.openFile(filePath);

            if (result == 1) {
                cout << "File opened successfully: " << filePath << std::endl;
                break;
            }
            else if (result == 2) {
                cout << "File created successfully: " << filePath << std::endl;
                break;
            }
            else {
                throw runtime_error("Failed to open or create file");
            }
        }
        catch (const runtime_error& e) {
            cout << "Runtime error: " << e.what() << std::endl;
        }
        catch (const invalid_argument& e) {
            cout << "Input error: " << e.what() << std::endl;
        }
    }
}

void handleWriteString(FileReader& fileReader) {
    while (true) {
        try {
            if (!fileReader.isFileOpen()) {
                throw std::runtime_error("First open the file (option 1)!");
            }

            std::cout << "Enter string to write to file: ";
            std::string text;
            std::getline(std::cin, text);

            if (text.empty()) {
                throw std::invalid_argument("Cannot write empty string");
            }

            if (fileReader.writeString(text)) {
                std::cout << "String successfully written to file!" << std::endl;
                break;
            }
            else {
                throw std::runtime_error("Error writing to file");
            }
        }
        catch (const std::runtime_error& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Input error: " << e.what() << std::endl;
        }
    }
}

void handleReadChar(FileReader& fileReader) {
    try {
        if (!fileReader.isFileOpen()) {
            throw std::runtime_error("First open the file (option 1)!");
        }

        size_t fileSize = fileReader.getFileSize();
        std::cout << "Current file: " << fileReader.getFilePath() << std::endl;
        std::cout << "File size: " << fileSize << " bytes" << std::endl;

        if (fileSize == 0) {
            throw std::runtime_error("File is empty! First write data to file.");
        }

        std::cout << "Enter character position (1-" << fileSize << "): ";

        size_t position;
        std::cin >> position;
        clearInputBuffer();

        if (std::cin.fail()) {
            throw std::invalid_argument("Enter a valid number!");
        }

        if (position < 1 || position > fileSize) {
            throw std::out_of_range("Position is out of file bounds");
        }

        size_t internalPosition = position - 1;
        char ch = fileReader[internalPosition];

        if (ch != '\0') {
            std::cout << "Character at position " << position << ": '" << ch << "' (code: " << static_cast<int>(ch) << ")" << std::endl;
        }
        else {
            throw std::runtime_error("Failed to read character from file");
        }
    }
    catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Input error: " << e.what() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Range error: " << e.what() << std::endl;
    }
}

void handleShowFileSize(FileReader& fileReader) {
    try {
        if (!fileReader.isFileOpen()) {
            throw std::runtime_error("First open the file (option 1)!");
        }

        size_t size = fileReader.getFileSize();
        std::cout << "Current file: " << fileReader.getFilePath() << std::endl;
        std::cout << "File size: " << size << " bytes" << std::endl;

    }
    catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Unknown error: " << e.what() << std::endl;
    }
}

void run() {
    FileReader fileReader;
    std::string filePath;
    int choice;
    while (true) {
        printMenu();
        choice = safeInputInt("Select action: ");

        switch (choice) {
        case 1:
            handleCreateFile(fileReader, filePath);
            break;

        case 2:
            handleWriteString(fileReader);
            break;

        case 3:
            handleReadChar(fileReader);
            break;

        case 4:
            handleShowFileSize(fileReader);
            break;

        case 5:
            std::cout << "Exiting program..." << std::endl;
            fileReader.closeFile();
            return;

        default:
            std::cout << "Invalid choice! Try again." << std::endl;
            break;
        }
    }
}