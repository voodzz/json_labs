#include <gtest/gtest.h>
#include "../readAndParse.h"
#include "../lab01.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <json.hpp>


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