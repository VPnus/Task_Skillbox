#include <iostream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;


int main() {
    std::string path = "O:\\QZskillbox_study\\Module_35_3";
    std::string extension = ".txt";

    auto recursiveGetFileNamesByExtension = [](std::filesystem::path path, const std::string extension) {
        std::vector<std::string> fileNames;

        for (const auto& p : fs::recursive_directory_iterator(path)) {
            if (p.is_regular_file() && p.path().extension() == extension) {
                fileNames.push_back(p.path().filename().string());
            }
        }

        return fileNames;
    };

    auto fileNames = recursiveGetFileNamesByExtension(path, extension);

    for (const auto& fileName : fileNames) {
        std::cout << fileName << std::endl;
    }

    return 0;
}