#ifndef LABS_LAB_H
#define LABS_LAB_H

#include <string>
#include <filesystem>
#include <json.hpp>
#include <iostream>
#include <vector>
#include <ctime>

void CheckArgumentsAmount(int arguments_amount);
void CheckInputPathLabs1And2(const std::filesystem::path& path_to_filesystem_object);
bool IsJsonCorrect(const nlohmann::json& json); // works for variant 1
void ModifyJsonObject(nlohmann::json& json_object); // works for variant 8
void creatingAndWritingFile(nlohmann::json& json);
tm GetRequiredDateTime(); // variant 2
nlohmann::json TmToJson(tm date_time);
void outputForLab3(const nlohmann::json& json, const std::string& filePath);
void CheckInputPathLab3(const std::filesystem::path& path_to_filesystem_object);
void CheckInputPathLab4(const std::filesystem::path& path_to_filesystem_object);
std::size_t Size (const std::filesystem::path& path_to_filesystem_object);

#endif //LABS_LAB_H
