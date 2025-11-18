#ifndef MENUACTIONS_H
#define MENUACTIONS_H

#include "FileReader.h"
#include <string>

void printMenu();
void run();
void handleCreateFile(FileReader& fileReader, std::string& filePath);
void handleWriteString(FileReader& fileReader);
void handleReadChar(FileReader& fileReader);
void handleShowFileSize(FileReader& fileReader);

#endif