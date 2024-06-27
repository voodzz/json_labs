#ifndef LABS_FILESSTORAGE_H
#define LABS_FILESSTORAGE_H


#include <filesystem>
#include <set>
#include "lab.h"

class FilesStorage {
public:
    explicit FilesStorage(std::filesystem::path  path_to_directory);
    void InitStorage();
    void CopyFile(const std::filesystem::path& path_to_file);
private:
    std::filesystem::path path_to_directory_;
    std::set<std::string> files_content_storage_;
};


#endif //LABS_FILESSTORAGE_H
