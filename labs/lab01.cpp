#include "lab01.h"
#include <string>
#include <filesystem>
#include <json.hpp>
#include <iostream>

void CheckArgumentsAmount(int arguments_amount) {
    try {
        if (arguments_amount != 2) {
            std::string errorMessage = "Invalid command line arguments amount:"
                                       "current – " + std::to_string(arguments_amount) +
                                       ", required – 2";
            throw std::invalid_argument(errorMessage);
        }
    } catch (const char* error) {
        std::cout << error << '\n';
    }
}

void CheckInputPath(const std::filesystem::path& path_to_filesystem_object) {
    try {
        if (!exists(path_to_filesystem_object)) {
            std::string errorMessage =
                    "Filesystem object by path " + path_to_filesystem_object.string()
                    + " is not exists!";
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
    } catch (const char* error) {
        std::cout << error << '\n';
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
