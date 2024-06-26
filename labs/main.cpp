#include <iostream>
#include "lab01.h"
#include "readAndParse.h"

int main(int argc, char* argv[]) {
    std::string path_str = argv[1];
    std::filesystem::path path(path_str);

    std::cout << '\n';
    CheckArgumentsAmount(argc);
    CheckInputPath(path);
    nlohmann::json json = readAndParseFile(path_str);
    if (IsJsonCorrect(json)) {
        std::string outputMessage = "Structure of JSON-file by path " + path_str + " is correct.";
        std::cout << outputMessage << '\n';
    } else {
        std::string outputMessage = "Structure of JSON-file by path " + path_str + " is incorrect.";
        std::cout << outputMessage << '\n';
    }
    return 0;
}
