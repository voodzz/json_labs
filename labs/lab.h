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
void outputForLab2(nlohmann::json& json);

tm GetRequiredDateTime(); // variant 2
nlohmann::json TmToJson(tm date_time);
void outputForLab3(const nlohmann::json& json, const std::string& filePath);
void CheckInputPathLab3(const std::filesystem::path& path_to_filesystem_object);

void CheckInputPathLab4(const std::filesystem::path& path_to_filesystem_object);
std::size_t Size (const std::filesystem::path& path_to_filesystem_object);
nlohmann::json GetRegularFileInfo (const std::filesystem::path& path_to_file);
nlohmann::json GetDirectoryInfo (const std::filesystem::path& path_to_directory);
nlohmann::json GetFsObjectInfo (const std::filesystem::path& path_to_filesystem_object);
void outputForLab4(const nlohmann::json& json);

#endif //LABS_LAB_H
