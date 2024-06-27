#include <iostream>
#include <ctime>
#include "lab.h"
#include "readAndParse.h"

int main(int argc, char* argv[]) {
    try {
        std::string source_path = argv[1];
        std::string destination_path = argv[2];
        std::filesystem::path source(source_path);
        std::filesystem::path destination(destination_path);

        std::cout << '\n';

        CheckArgumentsAmountLab6(argc);
        CheckDirectoryPath(source);
        CheckDirectoryPath(destination);
        std::set<std::string> content = GetFilesContentFromDirectory(destination);
        for (const auto& entry: std::filesystem::directory_iterator(source)) {
            if (is_regular_file(entry.path())) {
                std::string fileContent = ReadFileContent(entry.path());
                auto check = content.find(fileContent);
                if (check == content.end()) {
                    content.insert(fileContent);
                    std::filesystem::copy_file(entry.path(), destination / entry.path().filename());
                    std::string outMessage = "File by path " + entry.path().string() +
                                             " has been copied to directory by path " +
                                             destination.string();
                    std::cout << outMessage << '\n';
                }
            }
        }
        return 0;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
    }
}
