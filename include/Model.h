#pragma once

#include <map>

#include "Vec3.h"
#include "Cell.h"
#include "Result.h"

struct simpleResult
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

    simpleResult parseVertex(std::string line);

    simpleResult parseMaterial(std::string line);

    simpleResult parseCell(std::string line);

public:
    Model() = default;

    explicit Model(std::string fileName);

    Result<Model> load();

    uint64_t numVertices();

    uint64_t numCells();

    uint64_t numMaterials();

    void describeCells();

    void describeVertices();

    void describeMaterials();

    std::vector<int> cellIDs();

    bool cellExists(int id);

    Result<Cell> getCell(int id);

};

