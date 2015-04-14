#ifndef POINT3D_H
#define POINT3D_H

#include <math.h>
#include <qglobal.h>

struct Point3D
{
    float x, y, z;

    Point3D():x(0),y(0),z(0) { }
    Point3D(float tX, float tY, float tZ) : x(tX), y(tY), z(tZ) { }

    Point3D operator+(const Point3D &p) const
    {
        return Point3D(*this) += p;
    }

    Point3D operator-(const Point3D &p) const
    {
        return Point3D(*this) -= p;
    }

    Point3D operator*(float f) const
    {
        return Point3D(*this) *= f;
    }

    Point3D &operator+=(const Point3D &p)
    {
        x += p.x;
        y += p.y;
        z += p.z;

        return *this;
    }

    Point3D &operator-=(const Point3D &p)
    {
        x -= p.x;
        y -= p.y;
        z -= p.z;

        return *this;
    }

    Point3D &operator*=(float f)
    {
        x *= f;
        y *= f;
        z *= f;

        return *this;
    }


    Point3D normalize() const
    {
        float r = 1.0 / sqrt(x*x + y*y + z*z);
        return Point3D(x*r, y*r, z*r);
    }

    float &operator[](unsigned int index)
    {
        Q_ASSERT(index < 3);
        return (&x)[index];
    }

    const float &operator[](unsigned int index) const
    {
        Q_ASSERT(index < 3);
        return (&x)[index];
    }
};

inline float dot(const Point3D &a, const Point3D &b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

inline Point3D cross(const Point3D &a, const Point3D &b)
{
    return Point3D(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}

#endif // POINT3D_H
