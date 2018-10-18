#pragma once

#include <iostream>

class Vec3
{
public:
    double x = 0, y = 0, z = 0;

    friend std::istream &operator>>(std::istream &in, Vec3 &out)
    {
        in >> out.x;
        in >> out.y;
        in >> out.z;
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, const Vec3 &vec)
    {
        out << "(" << vec.x << "," << vec.y << "," << vec.z << ")";
        return out;
    }

    Vec3 operator+(Vec3 other) const;

    Vec3 operator-(Vec3 other) const;

    bool operator==(Vec3 other) const;

    bool operator!=(Vec3 other) const;

    Vec3 dirFrom(Vec3 other) const;
};
