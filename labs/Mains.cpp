#include "Mains.h"
#include <iostream>
#include <ctime>
#include "lab.h"
#include "readAndParse.h"
#include "FilesStorage.h"

Mains::Mains(uint8_t labNumber) : lab(labNumber) {}

int Mains::lab1(int argc, char **argv) {
    std::string path_str = argv[1];
    std::filesystem::path path(path_str);

    std::cout << '\n';
    CheckArgumentsAmount(argc);
    CheckInputPathLabs1And2(path);
    nlohmann::json json = readAndParseFile(path_str);
    if (IsJsonCorrect(json)) {
        std::string outputMessage = "Structure of JSON-file by path " + path_str + " is correct.";
        std::cout << outputMessage << '\n';
    } else {
        std::string outputMessage = "Structure of JSON-file by path " + path_str + " is incorrect.";
        std::cout << outputMessage << '\n';
    }
    return 0;
}

int Mains::lab2(int argc, char **argv) {
    std::string path_str = argv[1];
    std::filesystem::path path(path_str);

    std::cout << '\n';
    CheckArgumentsAmount(argc);
    CheckInputPathLabs1And2(path);
    nlohmann::json json = readAndParseFile(path_str);
    outputForLab2(json);
    return 0;
}

int Mains::lab3(int argc, char **argv) {
    std::string path_str = argv[1];
    std::filesystem::path path(path_str);

    std::cout << '\n';

    CheckArgumentsAmount(argc);
    CheckInputPathLab3(path);
    tm time = GetRequiredDateTime();
    nlohmann::json json = TmToJson(time);
    outputForLab3(json, path_str);
    return 0;
}

int Mains::lab4(int argc, char **argv) {
    std::string path_str = argv[1];
    std::filesystem::path path(path_str);

    std::cout << '\n';

    CheckArgumentsAmount(argc);
    CheckInputPathLab4(path);
    nlohmann::json json = GetFsObjectInfo(path_str);
    outputForLab4(json);
    return 0;
}

int Mains::lab5(int argc, char **argv) {
    std::string path_str = argv[1];
    std::filesystem::path path(path_str);

    std::cout << '\n';

    CheckArgumentsAmount(argc);
    CheckInputPathLab5(path);
    outputForLab5(path);
    return 0;
}

int Mains::lab6(int argc, char **argv) {
    try {
        std::string source_path = argv[1];
        std::string destination_path = argv[2];
        std::filesystem::path source(source_path);
        std::filesystem::path destination(destination_path);

        std::cout << '\n';

        CheckArgumentsAmountLab6And7(argc);
        CheckDirectoryPath(source);
        CheckDirectoryPath(destination);
        std::set<std::string> content = GetFilesContentFromDirectory(destination);
        for (const auto& entry: std::filesystem::directory_iterator(source)) {
            if (is_regular_file(entry.path())) {
                std::string fileContent = ReadFileContent(entry.path());
                auto check = content.find(fileContent);
                if (check == content.end()) {
                    content.insert(fileContent);
                    std::filesystem::copy_file(entry.path(), destination / entry.path().filename());
                    std::string outMessage = "File by path " + entry.path().string() +
                                             " has been copied to directory by path " +
                                             destination.string();
                    std::cout << outMessage << '\n';
                }
            }
        }
        return 0;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}

int Mains::lab7(int argc, char **argv) {
    try {
        std::string source_path = argv[1];
        std::string destination_path = argv[2];
        std::filesystem::path source(source_path);
        std::filesystem::path destination(destination_path);

        std::cout << '\n';

        CheckArgumentsAmountLab6And7(argc);
        CheckDirectoryPath(source);
        CheckDirectoryPath(destination);
        FilesStorage filesStorage(destination);
        filesStorage.InitStorage();
        for (const auto& entry : std::filesystem::directory_iterator(source)) {
            filesStorage.CopyFile(entry.path());
        }
        return 0;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}

int Mains::lab8(int argc, char **argv) {
    try {
        std::string path_str = argv[1];
        std::filesystem::path path(path_str);

        std::cout << '\n';

        CheckArgumentsAmount(argc);
        CheckDirectoryPath(path);
        RemoveDuplicatesFromDirectory(path);
        return 0;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}

int Mains::lab9(int argc, char **argv) {
    try {
        std::string directory_str = argv[1];
        std::filesystem::path directory(directory_str);

        std::cout << '\n';

        CheckArgumentsAmount(argc);
        CheckDirectoryPath(directory);
        for (const auto& entry : std::filesystem::directory_iterator(directory)) {
            if (is_regular_file(entry.path())) {
                Move(entry.path());
            }
        }
        return 0;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}

int Mains::lab10(int argc, char **argv) {
    try {
        std::string directory_str = argv[1];
        //std::string destination_path = argv[2];
        std::filesystem::path directory(directory_str);
        //std::filesystem::directory destination(destination_path);

        std::cout << '\n';

        CheckArgumentsAmount(argc);
        CheckDirectoryPath(directory);
        for (const auto& entry : std::filesystem::directory_iterator(directory)) {
            if (is_regular_file(entry.path())) {
                FileName file(entry.path());
                file.Parse();
                if (file.IsRemoveRequired()) {
                    std::filesystem::remove(file.path_to_current_file);
                } else {
                    Move(entry.path());
                }
            }
        }
        return 0;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}

int Mains::execute(int argc, char **argv) const {
    switch (lab) {
        case 1:
            return lab1(argc, argv);
        case 2:
            return lab2(argc, argv);
        case 3:
            return lab3(argc, argv);
        case 4:
            return lab4(argc, argv);
        case 5:
            return lab5(argc, argv);
        case 6:
            return lab6(argc, argv);
        case 7:
            return lab7(argc, argv);
        case 8:
            return lab8(argc, argv);
        case 9:
            return lab9(argc, argv);
        case 10:
            return lab10(argc, argv);
        default:
            return 1;
    }
}
