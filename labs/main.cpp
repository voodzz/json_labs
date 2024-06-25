#include <iostream>
#include "lab01.h"

int main() {
    std::cout << "Input the path to the file." << std::endl;
    std::string path_str;
    std::getline(std::cin, path_str);
    std::filesystem::path path(path_str);

    CheckInputPath(path);
    return 0;
}
