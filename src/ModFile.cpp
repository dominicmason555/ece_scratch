#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

#include "ModFile.h"
#include "Vec3.h"


ModFileResult ModFile::parseVertex(const std::string line, int lineNum)
{
    std::stringstream in(line);
    int num;
    Vec3 v;
    in.ignore(1, ' ');
    in >> num >> v;
    vertices[num] = v;
    std::cout << "Line " << lineNum << ": parsed vertex " << num << " " << vertices.at(num) << std::endl;
    return {true, "Success"};
}

ModFileResult ModFile::parseMaterial(std::string line, int lineNum)
{
    std::stringstream in(line);
    int num;
    Material mat;
    in.ignore(1, ' ');
    in >> num >> mat;
    materials[num] = mat;
    std::cout << "Line " << lineNum << ": parsed material " << num << " " << materials.at(num) << std::endl;
    return {true, "Success"};
}

ModFileResult ModFile::parseCell(std::string line, int lineNum)
{
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
            shape = Shape::TETRAHEDRAL;
            break;
        default:
            return {false, "Invalid Shape"};
    }

    if (materials.count(materialNum) == 0)
        return {false, "Invalid material number in file"};

    Material material = materials.at(materialNum);
    Cell cell(shape, material);
    int vertexNum;
    while (in >> vertexNum) {
        if (vertices.count(vertexNum != 0)) {
            Vec3 vertex = vertices.at(vertexNum);
            cell.vertices.push_back(vertex);
        } else
            return {false, "Invalid vertex number in file"};
    }
    cells.emplace(num, cell);
    std::cout << "Line " << lineNum << ": parsed Cell " << num << " " << cells.at(num) << std::endl;
    return {true, "Success"};
}

ModFile::ModFile(const std::string fileName) :
        fileName(fileName)
{};

ModFileResult ModFile::load()
{
    std::ifstream file(fileName);
    if (!file.is_open())
        return {false, "File Not Found"};

    std::string line;
    int lineNum = 0;
    ModFileResult result;

    while (std::getline(file, line)) {
        lineNum++;
        switch (line.front()) {
            case '\n':
            case '\r':
            case '\0':
            case '#':
                result = {true, "Success"};
                break;
            case 'm':
                result = parseMaterial(line, lineNum);
                break;
            case 'v':
                result = parseVertex(line, lineNum);
                break;
            case 'c':
                result = parseCell(line, lineNum);
                break;
            default:
                result = {false, "Invalid start character in file"};
                break;
        }
        if (!result.success){
            result.error += " at line ";
            result.error += std::to_string(lineNum);
            return result;
        }
    }
    return {true, "Success"};
}