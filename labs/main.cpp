#include <iostream>
#include <ctime>
#include "lab.h"
#include "readAndParse.h"
#include "FilesStorage.h"

int main(int argc, char* argv[]) {
    try {
        std::string source_path = argv[1];
        std::string destination_path = argv[2];
        std::filesystem::path source(source_path);
        std::filesystem::path destination(destination_path);

        std::cout << '\n';

        CheckArgumentsAmountLab6And7(argc);
        CheckDirectoryPath(source);
        CheckDirectoryPath(destination);
        FilesStorage filesStorage(destination);
        filesStorage.InitStorage();
        for (const auto& entry : std::filesystem::directory_iterator(source)) {
            filesStorage.CopyFile(entry.path());
        }

        return 0;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
    }
}
