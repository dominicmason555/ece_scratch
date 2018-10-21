#include <iostream>

#include "ModFile.h"

int main(int argc, char *argv[])
{
    ModFile exampleFile("../ExampleModel1.mod");
    ModFileResult result = exampleFile.load();
    if (!result.success)
    {
        std::cout << "Error Parsing File: " << result.error << std::endl;
    }
    return 0;
}