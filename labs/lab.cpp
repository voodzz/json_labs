#include <string>
#include <filesystem>
#include <json.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include "lab.h"
#include "readAndParse.h"

void CheckArgumentsAmount(int arguments_amount) {
    try {
        if (arguments_amount != 2) {
            std::string errorMessage = "Invalid command line arguments amount: "
                                       "current is " + std::to_string(arguments_amount) +
                                       ", required is 2";
            throw std::invalid_argument(errorMessage);
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

void CheckInputPathLabs1And2(const std::filesystem::path& path_to_filesystem_object) {
    try {
        if (!exists(path_to_filesystem_object)) {
            std::string errorMessage =
                    "Filesystem object by path " + path_to_filesystem_object.string()
                    + " does not exist!";
            throw std::invalid_argument(errorMessage);
        }
        if (!is_regular_file(path_to_filesystem_object)) {
            std::string errorMessage =
                    "Filesystem object by path " + path_to_filesystem_object.string()
                    + " is not a regular file!";
            throw std::invalid_argument(errorMessage);
        }
        if (path_to_filesystem_object.extension().string() != ".json") {
            std::string errorMessage =
                    "Filesystem object by path " + path_to_filesystem_object.string()
                    + " has invalid extension!";
            throw std::invalid_argument(errorMessage);
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

bool IsJsonCorrect(const nlohmann::json& json) {
     /* Object from variant 1:
      * {
      *      "object" :
      *      {
      *          "string" : значение типа строка,
      *          "number" : значение типа число,
      *          "inner_array" : []
      *      },
      *      "array" :
      *      [
      *          false,
      *          null,
      *          {...}
      *      ]
      * }*/

    // check if our initial object contains needed elements
    if (!json.contains("object") || !json["object"].is_object()) {
        return false;
    }
    if (!json.contains("array") || !json["array"].is_array()) {
        return false;
    }

    //check if element "object" is structured properly
    const auto& object = json["object"];
    if (!object.contains("string") || !object["string"].is_string()) {
        return false;
    }
    if (!object.contains("number") || !object["number"].is_number()) {
        return false;
    }
    if (!object.contains("inner_array") || !object["inner_array"].is_array()
        || !object["inner_array"].empty()) {
        return false;
    }

    //check if element "array" is structured properly
    const auto& array = json["array"];
    if (array.size() != 3) {
        return false;
    }
    if (array[0] != false) {
        return false;
    }
    if (!array[1].is_null()) {
        return false;
    }
    if (!array[2].is_object()) {
        return false;
    }

    return true;
}

void ModifyJsonObject(nlohmann::json& json_object) {
    try {
        std::vector<std::string> keysToRemove;

        for (auto it = json_object.begin(); it != json_object.end(); ++it) {
            if (it.value().is_array()) {
                const auto& array = it.value();
                int counter = 0;
                for (const auto& element: array) {
                    if (element.is_object()) {
                        ++counter;
                    }
                    if (counter >= 2) {
                        keysToRemove.push_back(it.key());
                        break;
                    }
                }
            }
        }

        for (const auto& key: keysToRemove) {
            json_object.erase(key);
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

void creatingAndWritingFile(nlohmann::json& json) {
    try {
        for (const auto& item: json.items()) {
            if (item.value().is_object()) {
                nlohmann::json modifiedObject = item.value();
                ModifyJsonObject(modifiedObject);

                const std::string& filePath = R"(C:\Task_Bar\Two\Studying\summer_prac\json_labs\labs\files_for_lab2\output)";
                std::filesystem::path directory(filePath);
                if (!exists(directory)) {
                    std::filesystem::create_directory(directory);
                }

                std::string outputPath = directory.string() + R"(\)" + item.key() + ".json";
                std::ofstream out(outputPath, std::ios::out);
                out << modifiedObject.dump(4);
                out.close();
            }
        }
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
    }
}

tm GetRequiredDateTime() {
    time_t currentTime = time(nullptr);
    time_t neededTime = currentTime - 87*3600;
    tm result{};
    localtime_s(&result, &neededTime);
    return result;
}

nlohmann::json TmToJson(tm date_time) {
    nlohmann::json result({{"tm_sec", date_time.tm_sec}, {"tm_min", date_time.tm_min},
                           {"tm_hour", date_time.tm_hour}, {"tm_mday", date_time.tm_mday},
                           {"tm_mon", date_time.tm_mon}, {"tm_year", date_time.tm_year},
                           {"tm_wday", date_time.tm_wday}, {"tm_yday", date_time.tm_yday},
                           {"tm_isdst", date_time.tm_isdst}});
    return result;
}

void CheckInputPathLab3(const std::filesystem::path& path_to_filesystem_object) {
    try {
        if (path_to_filesystem_object.extension().string() != ".json") {
            std::string errorMessage =
                    "Filesystem object by path " + path_to_filesystem_object.string()
                    + " has invalid extension!";
            throw std::invalid_argument(errorMessage);
        }
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
    }
}

void outputForLab3(const nlohmann::json& json, const std::string& filePath) {
    std::cout << json.dump(4) << '\n';

    std::filesystem::path path(filePath);
    std::filesystem::path directory = path.parent_path();

    if (!exists(directory)) {
        std::filesystem::create_directory(directory);
    }

    std::ofstream out(filePath, std::ios::out);
    out << json.dump(4) << '\n';
    out.close();
}

void CheckInputPathLab4(const std::filesystem::path& path_to_filesystem_object) {
    try {
        if (!exists(path_to_filesystem_object)) {
            std::string errorMessage =
                    "Filesystem object by path " + path_to_filesystem_object.string()
                    + " does not exist!";
            throw std::invalid_argument(errorMessage);
        }
        if (!is_regular_file(path_to_filesystem_object) && !is_directory(path_to_filesystem_object)) {
            std::string errorMessage =
                    "Filesystem object by path " + path_to_filesystem_object.string()
                    + " has invalid type!";
            throw std::invalid_argument(errorMessage);
        }
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
    }
}
