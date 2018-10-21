#include "Cell.h"

std::ostream &operator<<(std::ostream &os, const Cell &cell)
{
    os << cell.shape << " cell made of " << cell.material << " with " << cell.vertices.size() << " vertices";
    return os;
}

std::ostream &operator<<(std::ostream &os, const Shape &shape)
{
    switch (shape) {
        case Shape::HEXAHEDRAL:
            os << "Hexahedral";
            break;
        case Shape::PYRAMIDAL:
            os << "Pyramidal";
            break;
        case Shape::TETRAHEDRAL:
            os << "Tetrahedral";
            break;
        default:
            os << "Broken Shape";
    }
    return os;
}

std::istream &operator>>(std::istream &in, Material &out)
{
    in >> out.density;
    in >> out.name;
    return in;
}

std::ostream &operator<<(std::ostream &out, const Material &mat)
{
    out << mat.name << " with a density of " << mat.density;
    return out;
}
