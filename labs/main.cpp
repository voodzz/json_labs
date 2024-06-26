#include <iostream>
#include "lab.h"
#include "readAndParse.h"

int main(int argc, char* argv[]) {
    std::string path_str = argv[1];
    std::filesystem::path path(path_str);

    std::cout << '\n';
    CheckArgumentsAmount(argc);
    CheckInputPath(path);
    nlohmann::json json = readAndParseFile(path_str);
    creatingAndWritingFile(json);
    return 0;
}
