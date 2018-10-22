#include <iostream>

#include "Model.h"

int main(int argc, char *argv[])
{
    if (auto file = Model("../ExampleModel1.mod").load()) {
        file.value.describeMaterials();
        file.value.describeVertices();
        file.value.describeCells();
        if (auto res = file.value.getCell(2))
            std::cout << res.value << std::endl;
        else
            std::cout << res.error << std::endl;
    } else
        std::cout << file.error << std::endl;
    return 0;
}