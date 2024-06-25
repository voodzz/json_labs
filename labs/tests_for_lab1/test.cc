#include <gtest/gtest.h>
#include "../lab01.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <json.hpp>

nlohmann::json readAndParseFile(const std::string& filePath) {
    std::ifstream fin(filePath, std::ios::in);
    // fancy way I've found to read data inside a file
    std::string file_content((std::istreambuf_iterator<char>(fin)), std::istreambuf_iterator<char>());
    fin.close();
    // create a json object and parse data from file into it
    nlohmann::json json;
    try {
        json = nlohmann::json::parse(file_content);
    } catch (nlohmann::json::parse_error& error) {
        std::cout << "Parsing error: " << error.what() << std::endl;
    }
    return json;
}

TEST(Lab01_tests, invalid_array) {
    std::string filePath(R"(C:\Task_Bar\Two\Studying\summer_prac\json_labs\labs\tests_for_lab1\testing_files_for_lab1\invalid_array.json)");
    EXPECT_NO_THROW(CheckInputPath(filePath));

    nlohmann::json json = readAndParseFile(filePath);
    EXPECT_FALSE(IsJsonCorrect(json));
}

TEST(Lab01_tests, ok_variant) {
    std::string filePath(R"(C:\Task_Bar\Two\Studying\summer_prac\json_labs\labs\tests_for_lab1\testing_files_for_lab1\ok_variant.json)");
    EXPECT_NO_THROW(CheckInputPath(filePath));

    nlohmann::json json = readAndParseFile(filePath);
    EXPECT_TRUE(IsJsonCorrect(json));
}

TEST(Lab01_tests, invalid_inner_array) {
    std::string filePath(R"(C:\Task_Bar\Two\Studying\summer_prac\json_labs\labs\tests_for_lab1\testing_files_for_lab1\invalid_inner_array.json)");
    EXPECT_NO_THROW(CheckInputPath(filePath));

    nlohmann::json json = readAndParseFile(filePath);
    EXPECT_FALSE(IsJsonCorrect(json));
}

TEST(Lab01_tests, invalid_number) {
    std::string filePath(R"(C:\Task_Bar\Two\Studying\summer_prac\json_labs\labs\tests_for_lab1\testing_files_for_lab1\invalid_number.json)");
    EXPECT_NO_THROW(CheckInputPath(filePath));

    nlohmann::json json = readAndParseFile(filePath);
    EXPECT_FALSE(IsJsonCorrect(json));
}

TEST(Lab01_tests, invalid_string) {
    std::string filePath(R"(C:\Task_Bar\Two\Studying\summer_prac\json_labs\labs\tests_for_lab1\testing_files_for_lab1\invalid_string.json)");
    EXPECT_NO_THROW(CheckInputPath(filePath));

    nlohmann::json json = readAndParseFile(filePath);
    EXPECT_FALSE(IsJsonCorrect(json));
}

TEST(Lab01_tests, no_array) {
    std::string filePath(R"(C:\Task_Bar\Two\Studying\summer_prac\json_labs\labs\tests_for_lab1\testing_files_for_lab1\no_array.json)");
    EXPECT_NO_THROW(CheckInputPath(filePath));

    nlohmann::json json = readAndParseFile(filePath);
    EXPECT_FALSE(IsJsonCorrect(json));
}

TEST(Lab01_tests, no_object) {
    std::string filePath(R"(C:\Task_Bar\Two\Studying\summer_prac\json_labs\labs\tests_for_lab1\testing_files_for_lab1\no_object.json)");
    EXPECT_NO_THROW(CheckInputPath(filePath));

    nlohmann::json json = readAndParseFile(filePath);
    EXPECT_FALSE(IsJsonCorrect(json));
}