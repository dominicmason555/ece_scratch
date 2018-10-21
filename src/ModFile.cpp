#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

#include "ModFile.h"


ModFileResult ModFile::parseVertex(const std::string line, int lineNum)
{
    std::stringstream in(line);
    int num;
    Vec3 v;
    in.ignore(1, ' ');
    if (not(in >> num >> v))
        return {false, "Error parsing vertex in file"};
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
    if (not(in >> num >> mat))
        return {false, "Error parsing material in file"};
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
    if (not(in >> num >> shapeLetter >> materialNum))
        return {false, "Error parsing cell in file"};

    int numberOfVertices = 0;
    switch (shapeLetter) {
        case 'h':
            shape = Shape::HEXAHEDRAL;
            numberOfVertices = 8;
            break;
        case 'p':
            shape = Shape::PYRAMIDAL;
            numberOfVertices = 5;
            break;
        case 't':
            shape = Shape::TETRAHEDRAL;
            numberOfVertices = 4;
            break;
        default:
            return {false, "Invalid shape in file"};
    }
    if (materials.count(materialNum) == 0)
        return {false, "Invalid material number in file"};

    Cell cell(shape, materials.at(materialNum));

    int vertexNum;
    while (in >> vertexNum) {
        if (vertices.find(vertexNum) != vertices.end()) {
            cell.vertices.push_back(vertices.at(vertexNum));
        } else
            return {false, "Invalid vertex number in file"};
    }
    if (cell.vertices.size() != numberOfVertices)
        return {false, "Wrong number of vertices for shape in file"};

    cells.emplace(num, std::move(cell));
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
        if (not result.success) {
            result.error += " at line ";
            result.error += std::to_string(lineNum);
            return result;
        }
    }
    return {true, "Success"};
}