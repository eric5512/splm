#include "parser_helper.h"

#include <iostream>

#include "serializer.h"
#include "file_helper.h"

void ParserHelper::parseInitFile(const std::string& filepath, Parts& parts) {
    std::vector<std::string> lines;
    FileHelper::readFile(filepath, lines);

    if (lines.size() <= 1) {
        throw new std::runtime_error("Empty init file");
    }

    std::string header = lines[0];

    for (int i = 1; i < (int) lines.size(); i++) return;
}

bool ParserHelper::containsAnyChar(const std::string& str, const std::vector<char>& vec) {
    for (const char chr : str) {
        if (inVector(vec, chr)) return true;
    }
    
    return false;
}

void ParserHelper::serializeParts(const Parts& parts, const std::string& filename) {
    std::string ser = Serializer::serialize(parts);
    FileHelper::writeFile(filename, std::string(ser));
}

void ParserHelper::unserializeParts(Parts& parts, const std::string& filename) {
    std::string ser = FileHelper::readFile(filename);
    Serializer::unserialize(ser, parts);
}

std::string ParserHelper::filterChars(const std::string& str, const std::vector<char>& vec) {
    std::string filtered;

    for (const char chr : str) {
        if (!inVector(vec, chr))
            filtered += chr;
    }

    return filtered;
}

bool ParserHelper::inVector(const auto&vec, const auto& elem) {
    for (const auto& match : vec) {
        if (match == elem) {
            return true;
        }
    }

    return false;
}

std::vector<std::string> ParserHelper::splitString(const std::string& string, char separator) {
    std::vector<std::string> ret = std::vector<std::string>();

    int b = 0;
    for (size_t i = 0; i < string.length(); i++) {
        if (string[i] == separator) {
            ret.emplace_back(string.substr(b, i-b));
        }
    }
    
    return ret;
}