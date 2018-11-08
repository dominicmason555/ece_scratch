#include <iostream>

#include "Model.h"

int main(int argc, char *argv[])
{
    if (auto model = Model("../ExampleModel2.mod").load()) {

        model->describeMaterials();
        model->describeVertices();
        model->describeCells();

        if (auto cell = model->getCell(1))
            std::cout << cell << std::endl;
        else
            std::cout << cell.error << std::endl;

    } else
        std::cout << model.error << std::endl;

    return 0;
}
