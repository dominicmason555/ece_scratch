#pragma once

#include <map>

#include "Vec3.h"
#include "Cell.h"
#include "Result.h"


class Model
{
private:
    std::string fileName;
    std::map<int, Vec3> vertices;
    std::map<int, Material> materials;
    std::map<int, Cell> cells;

    bool parseVertex(std::string line, std::string& error);

    bool parseMaterial(std::string line, std::string& error);

    bool parseCell(std::string line, std::string& error);

public:
    Model() = default;
    ~Model() = default;

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

