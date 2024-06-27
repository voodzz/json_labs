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

void CheckInputPathLab5(const std::filesystem::path& path_to_filesystem_object);
namespace filesystem_object {
    std::size_t Size (const std::filesystem::path& path_to_filesystem_object);

    struct Info {
        std::string name; // name without extension
        std::string type; // type (directory, file without extension, extention)
        size_t size{}; // literally just size of the object
        std::filesystem::path path_to_directory; // literally path to directory

        Info() = delete;
        explicit Info(const std::filesystem::path& path_to_filesystem_object) : name(path_to_filesystem_object.filename().string()) {
            if (is_directory(path_to_filesystem_object)) {
                type = "directory";
                path_to_directory = path_to_filesystem_object;
            } else if (path_to_filesystem_object.has_extension()) {
                type = path_to_filesystem_object.extension().string();
                path_to_directory = path_to_filesystem_object.parent_path();
            } else {
                type = "file with no extension";
                path_to_directory = path_to_filesystem_object.parent_path();
            }
        }

        Info(const Info& other) {
            name = other.name;
            type = other.type;
            size = other.size;
            path_to_directory = other.path_to_directory;
        }
        Info& operator =(const Info& other) {
            if (this == &other) {
                return *this;
            }

            name = other.name;
            type = other.type;
            size = other.size;
            path_to_directory = other.path_to_directory;

            return *this;
        }

        Info(Info&& other)  noexcept {
            name = other.name;
            type = other.type;
            size = other.size;
            path_to_directory = other.path_to_directory;
        }
        Info& operator =(Info&& other)  noexcept {
            if (this != &other) {
                name = other.name;
                type = other.type;
                size = other.size;
                path_to_directory = other.path_to_directory;
            }
            return *this;
        }

        ~Info() = default;

        friend std::ostream& operator<<(std::ostream& os, const Info& obj) {
            os << std::left << std::setw(20) << std::setfill(' ') << obj.name
               << std::left << std::setw(20) << std::setfill(' ') << obj.type
               << std::left << std::setw(20) << std::setfill(' ') << obj.size
               << std::left << std::setw(50) << std::setfill(' ') << obj.path_to_directory;
            return os;
        }
    };

    Info GetInfo (const std::filesystem::path& path_to_filesystem_object);
}
namespace directory_content {
    struct Info {
        std::filesystem::path path_to_directory; // path to directory
        size_t size{}; // literally just size of the object
        uint32_t files_amount{}; // the number of files in the directory at the first nesting level
        uint32_t directories_amount{}; // the number of nested directories at the first nesting level

        Info() = delete;
        explicit Info(const std::filesystem::path& path_to_filesystem_object) {
            try {
                if (!is_directory(path_to_filesystem_object)) {
                    std::string errorMessage =
                            "Filesystem object by path " + path_to_filesystem_object.string()
                            + " is not a directory!";
                    throw std::invalid_argument(errorMessage);
                } else {
                    path_to_directory = path_to_filesystem_object;

                    // Initializing size using filesystem_object::Size function
                    size = filesystem_object::Size(path_to_filesystem_object);

                    // Counting the number of files and directories in the directory at the first nesting level
                    for (const auto& entry: std::filesystem::directory_iterator(
                            path_to_filesystem_object)) {
                        if (is_regular_file(entry.path())) {
                            ++files_amount;
                        } else if (is_directory(entry.path())) {
                            ++directories_amount;
                        }
                    }
                }
            } catch (const std::exception& error) {
                std::cerr << error.what() << '\n';
            }
        }

        Info(const Info& other) {
            path_to_directory = other.path_to_directory;
            size = other.size;
            files_amount = other.files_amount;
            directories_amount = other.directories_amount;
        }
        Info& operator =(const Info& other) {
            if (this == &other) {
                return *this;
            }

            path_to_directory = other.path_to_directory;
            size = other.size;
            files_amount = other.files_amount;
            directories_amount = other.directories_amount;

            return *this;
        }

        Info(Info&& other)  noexcept {
            path_to_directory = other.path_to_directory;
            size = other.size;
            files_amount = other.files_amount;
            directories_amount = other.directories_amount;
        }
        Info& operator =(Info&& other)  noexcept {
            if (this != &other) {
                path_to_directory = other.path_to_directory;
                size = other.size;
                files_amount = other.files_amount;
                directories_amount = other.directories_amount;
            }
            return *this;
        }

        ~Info() = default;

        friend std::ostream& operator <<(std::ostream& os, const Info& obj) {
            os << std::left << std::setw(50) << std::setfill(' ') << "path_to_directory:"
               << std::left << std::setw(20) << std::setfill(' ') << obj.path_to_directory
               << std::left << std::setw(50) << std::setfill(' ') << "size:"
               << std::left << std::setw(20) << std::setfill(' ') << obj.size
               << std::left << std::setw(50) << std::setfill(' ') << "files_amount:"
               << std::left << std::setw(20) << std::setfill(' ') << obj.files_amount
               << std::left << std::setw(50) << std::setfill(' ') << "directories_amount:"
               << std::left << std::setw(20) << std::setfill(' ') << obj.directories_amount;
            return os;
        }
    };
}

#endif //LABS_LAB_H
