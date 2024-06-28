#ifndef LABS_FILENAME_H
#define LABS_FILENAME_H


#include <utility>
#include <regex>
#include <iostream>
#include <filesystem>

class FileName {
public:
    std::filesystem::path path_to_current_file;
    uint16_t year{};
    uint16_t month{};
    uint16_t day{};
    std::string only_name;

    explicit FileName(std::filesystem::path path_to_file);
    void Parse();
    bool IsRemoveRequired() const;
};


#endif //LABS_FILENAME_H
