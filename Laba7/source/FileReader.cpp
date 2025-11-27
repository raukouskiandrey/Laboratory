#include "FileReader.h"
#include <iostream>
#include <fstream>
#include <string_view>
#include <cstring>
#include <format>

FileReader::~FileReader() {
    closeFile();
}

bool FileReader::fileExists(std::string_view path) const {
    std::ifstream testFile;
    testFile.open(std::string(path));
    return testFile.is_open();
}

int FileReader::openFile(std::string_view path) {
    closeFile();
    filePath = path;

    bool exists = fileExists(path);

    try {
        file.open(filePath, std::ios::in | std::ios::out);

        if (!file.is_open() && !exists) {
            std::ofstream createFile(filePath);
            if (createFile.is_open()) {
                createFile.close();
                file.open(filePath, std::ios::in | std::ios::out);
            }
        }

        isOpen = file.is_open();

        if (isOpen) {
            return exists ? 1 : 2;
        }
        return 0;
    }
    catch (const std::ios_base::failure& e) {
        std::cerr << "Error opening file: " << e.what() << std::endl;
        return 0;
    }
}

void FileReader::closeFile() {
    if (file.is_open()) {
        file.close();
    }
    isOpen = false;
}

bool FileReader::writeString(const std::string& text) {
    if (!isOpen) {
        std::cerr << "Error: file is not open!" << std::endl;
        return false;
    }

    try {
        file.seekp(0, std::ios::end);

        if (file.fail()) {
            throw std::ios_base::failure("Cannot write to file - file may be corrupted or read-only");
        }

        file.write(text.c_str(), text.length());

        if (file.fail()) {
            throw std::ios_base::failure("Write operation failed");
        }

        file.clear();
        return true;
    }
    catch (const std::ios_base::failure& e) {
        std::cerr << "Error writing to file: " << e.what() << std::endl;
        file.clear();
        return false;
    }
}

char FileReader::operator[](size_t position) {
    if (!isOpen) {
        std::cerr << "Error: file is not open!" << std::endl;
        return '\0';
    }

    std::streampos currentPos = file.tellg();

    try {
        file.seekg(position, std::ios::beg);

        if (file.fail()) {
            throw std::out_of_range(std::format("Index out of file range ({} >= {})", position, getFileSize()));
        }

        char ch;
        file.get(ch);

        file.seekg(currentPos);

        return ch;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        file.clear();
        file.seekg(currentPos);
        return '\0';
    }
    catch (const std::ios_base::failure& e) {
        std::cerr << "File access error: " << e.what() << std::endl;
        file.clear();
        file.seekg(currentPos);
        return '\0';
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
        file.clear();
        file.seekg(currentPos);
        return '\0';
    }
}

size_t FileReader::getFileSize() {
    if (!isOpen) {
        return 0;
    }

    std::streampos currentPos = file.tellg();

    file.seekg(0, std::ios::end);

    std::streampos size = file.tellg();

    file.seekg(currentPos);

    return static_cast<size_t>(size);
}

bool FileReader::isFileOpen() const {
    return isOpen;
}

std::string FileReader::getFilePath() const {
    return filePath;
}