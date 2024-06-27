#include <filesystem>
#include <set>
#include <utility>
#include "FilesStorage.h"
#include "lab.h"

FilesStorage::FilesStorage(std::filesystem::path  path_to_directory) : path_to_directory_(std::move(path_to_directory)) {}

void FilesStorage::InitStorage() {
    for (const auto& entry : std::filesystem::directory_iterator(path_to_directory_)) {
        if (is_regular_file(entry.path())) {
            files_content_storage_.insert(ReadFileContent(entry.path()));
        }
    }
}

void FilesStorage::CopyFile(const std::filesystem::path& path_to_file) {
    if (is_regular_file(path_to_file)) {
        std::string fileContent = ReadFileContent(path_to_file);
        auto check = files_content_storage_.find(fileContent);
        if (check == files_content_storage_.end()) {
            files_content_storage_.insert(fileContent);
            std::filesystem::copy_file(path_to_file, path_to_directory_ / path_to_file.filename());
            std::string outMessage = "File by path " + path_to_file.string() +
                                     " has been copied to directory by path " +
                                     path_to_directory_.string();
            std::cout << outMessage << '\n';
        }
    }
}
