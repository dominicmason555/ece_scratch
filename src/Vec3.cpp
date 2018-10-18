#include "Vec3.h"

Vec3 Vec3::operator+(const Vec3 other) const
{
    return Vec3{x + other.x, y + other.y, z + other.z};
}

Vec3 Vec3::operator-(const Vec3 other) const
{
    return Vec3{x - other.x, y - other.y, z - other.z};
}

bool Vec3::operator==(const Vec3 other) const
{
    return x == other.x && y == other.y && z == other.z;
}

bool Vec3::operator!=(const Vec3 other) const
{
    return x != other.x || y != other.y || z != other.z;
}

Vec3 Vec3::dirFrom(const Vec3 other) const
{
    return (*this - other);
}

