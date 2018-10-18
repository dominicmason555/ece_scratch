#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>

#include "Vec3.h"

enum class Shape
{
    HEXAHEDRAL, PYRAMIDAL, TETRAHEDRAl
};

class Material
{
public:
    int density;
    std::string name;
};

class Cell
{
public:
    Shape shape;
    Material material;
    std::vector<Vec3> vertices;
};

class ModFile
{
private:
    void parseVertex(const std::string line);

public:
    std::map<int, Vec3> vertices;

    ModFile(const std::string fileName);
};

