#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <Model.h>


#include "Model.h"
#include "Result.h"


simpleResult Model::parseVertex(const std::string line)
{
    std::stringstream in(line);
    int num;
    Vec3 v;
    in.ignore(1, ' ');
    if (not(in >> num >> v))
        return {false, "Error parsing vertex from file"};
    vertices.emplace(num, v);
    std::cout << "Parsed vertex " << num << " " << vertices.at(num) << std::endl;
    return {true, "Success"};
}

simpleResult Model::parseMaterial(std::string line)
{
    std::stringstream in(line);
    int num;
    Material mat;
    in.ignore(1, ' ');
    if (not(in >> num >> mat))
        return {false, "Error parsing material from file"};
    materials.emplace(num, mat);
    std::cout << "Parsed material " << num << " " << materials.at(num) << std::endl;
    return {true, "Success"};
}

simpleResult Model::parseCell(std::string line)
{
    std::stringstream in(line);
    int num;
    char shapeLetter;
    int materialNum;
    Shape shape;
    in.ignore(1, ' ');
    if (not(in >> num >> shapeLetter >> materialNum))
        return {false, "Error parsing cell from file"};

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
    std::cout << "Parsed cell " << num << " " << cells.at(num) << std::endl;
    return {true, "Success"};
}

Model::Model(const std::string fileName) :
        fileName(fileName)
{};

Result<Model> Model::load()
{
    std::ifstream file(fileName);
    if (!file.is_open())
        return {false, {}, "File Not Found"};

    std::string line;
    int lineNum = 0;
    simpleResult result;

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
                result = parseMaterial(line);
                break;
            case 'v':
                result = parseVertex(line);
                break;
            case 'c':
                result = parseCell(line);
                break;
            default:
                result = {false, "Invalid start character in file"};
                break;
        }
        if (not result.success) {
            result.error += " at line ";
            result.error += std::to_string(lineNum);
            return {false, {}, result.error};
        }
    }
    return {true, *this};
}

uint64_t Model::numVertices()
{
    return vertices.size();
}

uint64_t Model::numCells()
{
    return cells.size();
}

uint64_t Model::numMaterials()
{
    return materials.size();
}

void Model::describeCells()
{
    std::cout << cells.size() << " Cells:" << std::endl;
    for (auto &cellKey : cells)
        std::cout << "Cell " << cellKey.first << ": " << cellKey.second << std::endl;
}

void Model::describeVertices()
{
    std::cout << vertices.size() << " Vertices:" << std::endl;
    for (auto &vertexKey : vertices)
        std::cout << "Vertex " << vertexKey.first << ": " << vertexKey.second << std::endl;
}

void Model::describeMaterials()
{
    std::cout << materials.size() << " Materials:" << std::endl;
    for (auto &matKey : materials)
        std::cout << "Material " << matKey.first << ": " << matKey.second << std::endl;
}

std::vector<int> Model::cellIDs()
{
    std::vector<int> ids;
    for (auto cellKey : cells)
        ids.push_back(cellKey.first);
    return std::move(ids);
}

bool Model::cellExists(int id)
{
    return cells.find(id) != cells.end();
}

Result<Cell> Model::getCell(int id)
{
    if (cellExists(id))
        return {true, cells.at(id)};
    else
        return {false, {}, "Cell " + std::to_string(id) + " accessed which does not exist"};
}

