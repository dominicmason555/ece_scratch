#include <iostream>

#include "Model.h"

int main(int argc, char *argv[])
{
    if (auto file = Model("../ExampleModel1.mod").load()) {

        file->describeMaterials();
        file->describeVertices();
        file->describeCells();

        if (auto cell = file->getCell(2))
            std::cout << cell << std::endl;
        else
            std::cout << cell.error << std::endl;

    } else
        std::cout << file.error << std::endl;

    return 0;
}
