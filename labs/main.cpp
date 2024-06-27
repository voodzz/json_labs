#include <iostream>
#include <ctime>
#include "lab.h"
#include "readAndParse.h"

int main(int argc, char* argv[]) {
    std::string path_str = argv[1];
    std::filesystem::path path(path_str);

    std::cout << '\n';

    CheckArgumentsAmount(argc);
    CheckInputPathLab3(path);
    tm time = GetRequiredDateTime();
    nlohmann::json json = TmToJson(time);
    outputForLab3(json, path_str);
    return 0;
}
