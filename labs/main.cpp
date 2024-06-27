#include <iostream>
#include <ctime>
#include "lab.h"
#include "readAndParse.h"
#include "FilesStorage.h"

int main(int argc, char* argv[]) {
    try {
        std::string path_str = argv[1];
        //std::string destination_path = argv[2];
        std::filesystem::path path(path_str);
        //std::filesystem::path destination(destination_path);

        std::cout << '\n';

        //CheckArgumentsAmount(argc);
        //CheckDirectoryPath(path);
        //RemoveDuplicatesFromDirectory(path);
        std::filesystem::path test(R"(C:\Task_Bar\Two\Studying\summer_prac\json_labs\labs\files_for_lab9\-19_13_01_wrongYearAndMonth.txt)");
        GetPathToMove(test);
        return 0;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
    }
}
