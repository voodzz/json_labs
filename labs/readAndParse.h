#ifndef LABS_READANDPARSE_H
#define LABS_READANDPARSE_H

#include <json.hpp>
#include <string>
#include <fstream>
#include <iostream>

nlohmann::json readAndParseFile(const std::string& filePath);

#endif //LABS_READANDPARSE_H
