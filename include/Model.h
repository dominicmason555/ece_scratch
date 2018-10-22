#pragma once

#include <map>

#include "Vec3.h"
#include "Cell.h"

struct Result
{
    bool success = false;
    std::string error = "Unknown Error";
};

class Model
{
private:
    std::string fileName;
    std::map<int, Vec3> vertices;
    std::map<int, Material> materials;
    std::map<int, Cell> cells;

    Result parseVertex(const std::string line);

    Result parseMaterial(std::string line);

    Result parseCell(std::string line);

public:
    explicit Model(std::string fileName);

    Result load();

    uint64_t numVertices();

    uint64_t numCells();

    uint64_t numMaterials();

    void describeCells();

    void describeVertices();

    void describeMaterials();

    std::vector<int> cellIDs();

    bool cellExists(int id);

    Cell getCell(int id);

};

