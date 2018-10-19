#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>

#include "Vec3.h"

enum class Shape {
    HEXAHEDRAL, PYRAMIDAL, TETRAHEDRAl
};

std::ostream &operator<<(std::ostream &os, const Shape &shape);

class Material {
public:
    friend std::ostream &operator<<(std::ostream &os, const Material &mat);

    friend std::istream &operator>>(std::istream &in, Material &out);

    int density;
    std::string name;
};

class Cell {
public:
    Cell(Shape shape, Material material) :
            shape(shape), material(material), vertices() {}
    Cell(Cell& other);

    friend std::ostream &operator<<(std::ostream &os, const Cell &cell);

    Shape shape;
    Material material;
    std::vector<Vec3> vertices;
};

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

    void parseVertex(std::string line, int lineNum);

    void parseMaterial(std::string line, int lineNum);

    void parseCell(std::string line, int lineNum);

public:
    explicit ModFile(std::string fileName);

    ModFileResult load();

};

