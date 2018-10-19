#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>

#include "ModFile.h"
#include "Vec3.h"


void ModFile::parseVertex(const std::string line, int lineNum) {
    std::stringstream in(line);
    int num;
    Vec3 v;
    in.ignore(1, ' ');
    in >> num >> v;
    vertices[num] = v;
    std::cout << "Line " << lineNum << ": parsed vertex " << num << " " << vertices[num] << std::endl;
}

void ModFile::parseMaterial(std::string line, int lineNum) {
    std::stringstream in(line);
    int num;
    Material mat;
    in.ignore(1, ' ');
    in >> num >> mat;
    materials[num] = mat;
    std::cout << "Line " << lineNum << ": parsed material " << num << " " << materials[num] << std::endl;
}

void ModFile::parseCell(std::string line, int lineNum) {
    std::stringstream in(line);
    int num;
    char shapeLetter;
    int materialNum;
    Shape shape;
    in.ignore(1, ' ');
    in >> num >> shapeLetter >> materialNum;
    switch (shapeLetter) {
        case 'h':
            shape = Shape::HEXAHEDRAL;
            break;
        case 'p':
            shape = Shape::PYRAMIDAL;
            break;
        case 't':
            shape = Shape::TETRAHEDRAl;
            break;
        default:
            return;
    }
    /*
    if (materials.count(materialNum) == 0)
        return;
    Material material = materials.at(materialNum);
    Cell cell(shape, material);
    int vertNum;
    while (in >> vertNum)
    {
        if (vertices.count(vertNum != 0))
        {
            Vec3 vert = vertices.at(vertNum);
            cell.vertices.push_back(vert);
        }
    }
    */
    std::cout << "Line " << lineNum << ": parsed Cell " << num << " " << cells[num] << std::endl;
}

ModFile::ModFile(const std::string fileName) :
        fileName(fileName) {};

ModFileResult ModFile::load() {
    std::ifstream file(fileName);
    if (!file.is_open())
        return {false, "File Not Found"};

    std::string line;
    int lineNum = 0;

    while (std::getline(file, line)) {
        lineNum++;
        switch (line.front()) {
            case '\n':
            case '\r':
            case '\0':
            case '#':
                break;
            case 'm':
                parseMaterial(line, lineNum);
                break;
            case 'v':
                parseVertex(line, lineNum);
                break;
            case 'c':
                parseCell(line, lineNum);
                break;
            default:
                std::cout << "File Machine Broke" << std::endl;
                break;
        }
    }
    return {true, "Success"};
}

std::ostream &operator<<(std::ostream &os, const Cell &cell) {
    os << "Cell: shape: " << cell.shape << " material: " << cell.material << " vertices: " << cell.vertices.size();
    return os;
}

std::ostream &operator<<(std::ostream &os, const Shape &shape) {
    switch (shape) {
        case Shape::HEXAHEDRAL:
            os << "Hexahedral";
            break;
        case Shape::PYRAMIDAL:
            os << "Pyramidal";
            break;
        case Shape::TETRAHEDRAl:
            os << "Tetrahedral";
            break;
        default:
            os << "Broken Shape";
    }
}

std::istream &operator>>(std::istream &in, Material &out) {
    in >> out.density;
    in >> out.name;
    return in;
}

std::ostream &operator<<(std::ostream &out, const Material &mat) {
    out << mat.name << " with density: " << mat.density;
    return out;
}

Cell::Cell(Cell &other):
shape(other.shape), material(other.material), vertices(other.vertices)
{}