#include "FileName.h"

#include <utility>
#include <regex>
#include <iostream>

FileName::FileName(std::filesystem::path path_to_file) : path_to_current_file(std::move(path_to_file)) {}

void FileName::Parse() {
    try {
        std::string year_str;
        std::string month_str;
        std::string day_str;
        std::string fileName = path_to_current_file.filename().string();
        std::string nameWithExtension;

        // год_месяц_число_имя.расширение, (например, 2022_08_13_filename.pdf)
        std::regex pattern(R"(^(\d{4})_(\d{2})_(\d{2})_(.+))");
        std::smatch matches;
        if (std::regex_match(fileName, matches, pattern)) {
            if (matches.size() == 5) {
                year_str = matches[1].str();
                month_str = matches[2].str();
                day_str = matches[3].str();
                nameWithExtension = matches[4].str();
                year = std::stoul(year_str);
                month = std::stoul(month_str);
                day = std::stoul(day_str);

                // Check if the year_str is legit
                if (year < 1) {
                    throw std::invalid_argument(
                            "Invalid filename. File path: " + path_to_current_file.string());
                } else {
                    switch (month) {
                        case 1:
                        case 3:
                        case 5:
                        case 7:
                        case 8:
                        case 10:
                        case 12:
                            if (day < 1 || day > 31) {
                                throw std::invalid_argument(
                                        "Invalid filename. File path: " + path_to_current_file.string());
                            }
                            break;
                        case 4:
                        case 6:
                        case 9:
                        case 11:
                            if (day < 1 || day > 30) {
                                throw std::invalid_argument(
                                        "Invalid filename. File path: " + path_to_current_file.string());
                            }
                            break;
                        case 2: {
                            // if the year_str is leap
                            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
                                if (day < 1 || day > 29) {
                                    throw std::invalid_argument(
                                            "Invalid filename. File path: " + path_to_current_file.string());
                                }
                            } else {
                                if (day < 1 || day > 28) {
                                    throw std::invalid_argument(
                                            "Invalid filename. File path: " + path_to_current_file.string());
                                }
                            }
                            break;
                        }
                        default:
                            throw std::invalid_argument(
                                    "Invalid filename. File path: " + path_to_current_file.string());
                            break;
                    }
                }
            } else {
                throw std::invalid_argument(
                        "Invalid filename. File path: " + path_to_current_file.string());
            }
        } else {
            throw std::invalid_argument("Invalid filename. File path: " + path_to_current_file.string());
        }
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
    }
}

bool FileName::IsRemoveRequired() const {
    if (day % 5 == 0 && year % 5 == 0) {
        return true;
    } else {
        return false;
    }
}
