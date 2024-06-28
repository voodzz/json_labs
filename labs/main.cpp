#include <iostream>
#include <ctime>
#include "lab.h"
#include "readAndParse.h"
#include "FilesStorage.h"

int main(int argc, char* argv[]) {
    try {
        std::string directory_str = argv[1];
        //std::string destination_path = argv[2];
        std::filesystem::path directory(directory_str);
        //std::filesystem::directory destination(destination_path);

        std::cout << '\n';

        CheckArgumentsAmount(argc);
        CheckDirectoryPath(directory);
        for (const auto& entry : std::filesystem::directory_iterator(directory)) {
            if (is_regular_file(entry.path())) {
                FileName file(entry.path());
                file.Parse();
                if (file.IsRemoveRequired()) {
                    std::filesystem::remove(file.path_to_current_file);
                } else {
                    Move(entry.path());
                }
            }
        }
        return 0;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
    }
}
