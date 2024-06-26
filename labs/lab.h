#ifndef LABS_LAB_H
#define LABS_LAB_H

#include <string>
#include <filesystem>
#include <json.hpp>
#include <iostream>
#include <vector>
#include <time.h>

void CheckArgumentsAmount(int arguments_amount);
void CheckInputPath(const std::filesystem::path& path_to_filesystem_object);
bool IsJsonCorrect(const nlohmann::json& json); // works for variant 1
void ModifyJsonObject(nlohmann::json& json_object); // works for variant 8
void creatingAndWritingFile(nlohmann::json& json);
tm GetRequiredDateTime();

#endif //LABS_LAB_H
