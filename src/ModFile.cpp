#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>

#include "ModFile.h"
#include "Vec3.h"


void ModFile::parseVertex(const std::string line)
{
    std::stringstream in(line);
    int num;
    Vec3 v;
    in.ignore(1, ' ');
    in >> num >> v;
    vertices[num] = v;
}


ModFile::ModFile(const std::string fileName)
{
    std::ifstream file(fileName);
    std::string line;

    while (std::getline(file, line)) {
        std::cout << line[0] << "-> ";
        switch (line[0]) {
            case '\n':
            case '\r':
            case '\0':
                std::cout << "This bitch empty" << std::endl;
                break;
            case '#':
                std::cout << "Comment" << std::endl;
                break;
            case 'm':
                std::cout << "Material" << std::endl;
                break;
            case 'v':
                std::cout << "Vec3" << std::endl;
                parseVertex(line);
                break;
            case 'c':
                std::cout << "Cell" << std::endl;
                break;
            default:
                std::cout << "File Machine Broke" << std::endl;
                break;
        }
    }
}
