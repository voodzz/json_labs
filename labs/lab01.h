#ifndef LABS_LAB01_H
#define LABS_LAB01_H

#include <string>
#include <filesystem>
#include <json.hpp>
#include <iostream>

void CheckArgumentsAmount(int arguments_amount);
void CheckInputPath(const std::filesystem::path& path_to_filesystem_object);
bool IsJsonCorrect(const nlohmann::json& json); // works for variant 1

#endif //LABS_LAB01_H
