//
// Created by Ruslan on 28.07.2024.
//
#include <iostream>
#include <fstream>
#include <optional>

class FS__ {
public:
    static void write(const std::string& path, std::string data, const std::optional<bool> rewrite_) {
        const bool rewrite = rewrite_.value_or(false);
        std::ofstream file;
        if (rewrite) {
            file.open(path);
        } else {
            file.open(path, std::ios::app);
        }
        if (file.is_open()) {
            file << data << std::endl;
            file.close();
        } else {
            throw MessageError__("Unable to open the file.", std::nullopt, std::nullopt);
        }
    }

    static bool exists(const std::string& path) {
        std::ifstream file(path);
        file.open(path);

        if (file.is_open()) {
            return true;
        } else {
            return false;
        }
    }

    static std::string read(const std::string &path) {
        std::ifstream file(path);
        std::string content;

        if (file.is_open()) {
            file.seekg(0, std::ios::end);
            content.resize(file.tellg());
            file.seekg(0, std::ios::beg);
            file.read(&content[0], content.size());
            file.close();
        } else {
            throw MessageError__("Unable to open the file.", std::nullopt, std::nullopt);
        }

        return content;
    }
};
