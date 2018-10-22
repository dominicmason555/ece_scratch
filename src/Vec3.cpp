


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

double Vec3::dotProduct(const Vec3 other) const
{
    return (x * other.x) + (y * other.y) + (z * other.z);
}

double Vec3::length() const
{
    return sqrt((x * x) + (y * y) + (z * z));
}

Vec3 Vec3::crossProduct(Vec3 other) const
{
    return Vec3{y * other.z - z * other.y,
                z * other.x - x * other.z,
                x * other.y - y * other.x};
}
