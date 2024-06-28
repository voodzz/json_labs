#include <iostream>
#include <ctime>
#include "lab.h"
#include "readAndParse.h"
#include "FilesStorage.h"
#include "Mains.h"

int main(int argc, char* argv[]) {
    std::cout << "Write the number of a lab: ";
    uint16_t number;
    std::cin >> number;
    Mains labMain(number);
    return labMain.execute(argc, argv);
}