#include <iostream>

#include "Model.h"

int main(int argc, char *argv[])
{
    Model exampleFile("../ExampleModel1.mod");
    Result result = exampleFile.load();
    if (not result.success)
    {
        std::cout << "Error Parsing File: " << result.error << std::endl;
    }
    exampleFile.describeMaterials();
    exampleFile.describeVertices();
    exampleFile.describeCells();
    return 0;
}