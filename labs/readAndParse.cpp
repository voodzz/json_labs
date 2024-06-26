#include "readAndParse.h"
#include <json.hpp>
#include <string>
#include <fstream>
#include <iostream>

nlohmann::json readAndParseFile(const std::string& filePath)  {
    std::ifstream fin(filePath, std::ios::in);
    // fancy way I've found to read data inside a file
    std::string file_content((std::istreambuf_iterator<char>(fin)), std::istreambuf_iterator<char>());
    fin.close();
    // create a json object and parse data from file into it
    nlohmann::json json;
    try {
        json = nlohmann::json::parse(file_content);
    } catch (nlohmann::json::parse_error& error) {
        std::cerr << "Parsing error: " << error.what() << std::endl;
    }
    return json;
}
