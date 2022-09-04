#pragma once

#include <string>

class Part {
private:
    std::string name;
    std::string path;
    std::string externPath;
    std::string group;
    int revision;
    int iteration;
    bool external;
public:
    Part(const std::string& c_name, const std::string& c_path, bool c_external) : name(c_name), path(c_path), external(c_external), revision(1), iteration(0) {}
    Part(const std::string& c_name, const std::string& c_path) : name(c_name), path(c_path), external(false), revision(1), iteration(0) {}
    std::string getName() const { return name; }
    std::string getPath() const { return path; }
    std::string getExternalPath() const { return externPath; }
    std::string getGroup() const { return group; }
    bool isExternal() const { return external; }
    std::string getVersion() const { return std::to_string(revision) + '.' + std::to_string(iteration); }
    int getIteration() const { return iteration; }
    int getRevision() const { return revision; }
    int iterate() { return ++iteration; }
    int revise() { return ++revision; }
};

class HashPart {
public:
    size_t operator()(const Part & part) const {
        return std::hash<std::string>()(part.getName()); // Name must be unique so its ok only using that for hashing
    }
};