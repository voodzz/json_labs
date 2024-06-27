#include <gtest/gtest.h>
#include "../readAndParse.h"
#include "../lab.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <json.hpp>


TEST(Lab01_tests, invalid_array) {
    std::string filePath(R"(C:\Task_Bar\Two\Studying\summer_prac\json_labs\labs\tests_for_labs\testing_files_for_lab1\invalid_array.json)");
    EXPECT_NO_THROW(CheckInputPathLabs1And2(filePath));

    nlohmann::json json = readAndParseFile(filePath);
    EXPECT_FALSE(IsJsonCorrect(json));
}

TEST(Lab01_tests, ok_variant) {
    std::string filePath(R"(C:\Task_Bar\Two\Studying\summer_prac\json_labs\labs\tests_for_labs\testing_files_for_lab1\ok_variant.json)");
    EXPECT_NO_THROW(CheckInputPathLabs1And2(filePath));

    nlohmann::json json = readAndParseFile(filePath);
    EXPECT_TRUE(IsJsonCorrect(json));
}

TEST(Lab01_tests, invalid_inner_array) {
    std::string filePath(R"(C:\Task_Bar\Two\Studying\summer_prac\json_labs\labs\tests_for_labs\testing_files_for_lab1\invalid_inner_array.json)");
    EXPECT_NO_THROW(CheckInputPathLabs1And2(filePath));

    nlohmann::json json = readAndParseFile(filePath);
    EXPECT_FALSE(IsJsonCorrect(json));
}

TEST(Lab01_tests, invalid_number) {
    std::string filePath(R"(C:\Task_Bar\Two\Studying\summer_prac\json_labs\labs\tests_for_labs\testing_files_for_lab1\invalid_number.json)");
    EXPECT_NO_THROW(CheckInputPathLabs1And2(filePath));

    nlohmann::json json = readAndParseFile(filePath);
    EXPECT_FALSE(IsJsonCorrect(json));
}

TEST(Lab01_tests, invalid_string) {
    std::string filePath(R"(C:\Task_Bar\Two\Studying\summer_prac\json_labs\labs\tests_for_labs\testing_files_for_lab1\invalid_string.json)");
    EXPECT_NO_THROW(CheckInputPathLabs1And2(filePath));

    nlohmann::json json = readAndParseFile(filePath);
    EXPECT_FALSE(IsJsonCorrect(json));
}

TEST(Lab01_tests, no_array) {
    std::string filePath(R"(C:\Task_Bar\Two\Studying\summer_prac\json_labs\labs\tests_for_labs\testing_files_for_lab1\no_array.json)");
    EXPECT_NO_THROW(CheckInputPathLabs1And2(filePath));

    nlohmann::json json = readAndParseFile(filePath);
    EXPECT_FALSE(IsJsonCorrect(json));
}

TEST(Lab01_tests, no_object) {
    std::string filePath(R"(C:\Task_Bar\Two\Studying\summer_prac\json_labs\labs\tests_for_labs\testing_files_for_lab1\no_object.json)");
    EXPECT_NO_THROW(CheckInputPathLabs1And2(filePath));

    nlohmann::json json = readAndParseFile(filePath);
    EXPECT_FALSE(IsJsonCorrect(json));
}

TEST(GetPathToMoveTests, correctVariant) {
    std::filesystem::path path(R"(C:\Task_Bar\Two\Studying\summer_prac\json_labs\labs\files_for_lab9\0019_12_13_correct.txt)");
    EXPECT_NO_THROW(GetPathToMove(path));
}

TEST(GetPathToMoveTests, leapYear) {
    std::filesystem::path path(R"(C:\Task_Bar\Two\Studying\summer_prac\json_labs\labs\files_for_lab9\2016_02_29_actuallyLeap.txt)");
    EXPECT_NO_THROW(GetPathToMove(path));
}

TEST(GetPathToMoveTests, wrongYear) {
    std::filesystem::path path(R"(C:\Task_Bar\Two\Studying\summer_prac\json_labs\labs\files_for_lab9\for_tests\0000_02_21_wrongYear.txt)");
    EXPECT_ANY_THROW(GetPathToMove(path));
}

TEST(GetPathToMoveTests, wrongYearAndDay) {
    std::filesystem::path path(R"(C:\Task_Bar\Two\Studying\summer_prac\json_labs\labs\files_for_lab9\for_tests\10_02_42_wrongYearAndDay.txt)");
    EXPECT_ANY_THROW(GetPathToMove(path));
}

TEST(GetPathToMoveTests, wrongYearAndMonth) {
    std::filesystem::path path(R"(C:\Task_Bar\Two\Studying\summer_prac\json_labs\labs\files_for_lab9\for_tests\19_13_01_wrongYearAndMonth.txt)");
    EXPECT_ANY_THROW(GetPathToMove(path));
}

TEST(GetPathToMoveTests, wrongDay) {
    std::filesystem::path path(R"(C:\Task_Bar\Two\Studying\summer_prac\json_labs\labs\files_for_lab9\for_tests\2024_07_69_wrongDay.txt)");
    EXPECT_ANY_THROW(GetPathToMove(path));
}

TEST(GetPathToMoveTests, wrongMonth) {
    std::filesystem::path path(R"(C:\Task_Bar\Two\Studying\summer_prac\json_labs\labs\files_for_lab9\for_tests\2024_31_12_wrongMonth.txt)");
    EXPECT_ANY_THROW(GetPathToMove(path));
}

TEST(GetPathToMoveTests, wrongMonthAndDay) {
    std::filesystem::path path(R"(C:\Task_Bar\Two\Studying\summer_prac\json_labs\labs\files_for_lab9\for_tests\2024_32_32_wrongMonthAndDay.txt)");
    EXPECT_ANY_THROW(GetPathToMove(path));
}

TEST(GetPathToMoveTests, everythingIsWrong) {
    std::filesystem::path path(R"(C:\Task_Bar\Two\Studying\summer_prac\json_labs\labs\files_for_lab9\for_tests\0000_15_32_everythingIsWrong.txt)");
    EXPECT_ANY_THROW(GetPathToMove(path));
}