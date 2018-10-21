#pragma once

#include <map>

#include "Vec3.h"
#include "Cell.h"

struct ModFileResult {
    bool success = false;
    std::string error = "Unknown Error";
};

class ModFile {
private:
    std::string fileName;
    std::map<int, Vec3> vertices;
    std::map<int, Material> materials;
    std::map<int, Cell> cells;

    ModFileResult parseVertex(std::string line, int lineNum);

    ModFileResult parseMaterial(std::string line, int lineNum);

    ModFileResult parseCell(std::string line, int lineNum);

public:
    explicit ModFile(std::string fileName);

    ModFileResult load();

};

