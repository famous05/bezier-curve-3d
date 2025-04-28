/*------------------------------------------------------------------------------
Point3D.cpp

This file is part of BezierLite library
Copyright (c) 2025, Famous Okhuahesogie, famous.osarobo@gmail.com
------------------------------------------------------------------------------*/

#include "Point3D.h"

namespace BezierLite
{
    // Constructor
    Point3D::Point3D(double x, double y, double z)
        : X(x), Y(y), Z(z)
    {
    }

    // Member operators
    Point3D& Point3D::operator*=(double scalar)
    {
        X *= scalar;
        Y *= scalar;
        Z *= scalar;
        return *this;
    }

    Point3D& Point3D::operator/=(double scalar)
    {
        if (scalar != 0.0)
        {
            X /= scalar;
            Y /= scalar;
            Z /= scalar;
        }
        return *this;
    }

    Point3D& Point3D::operator+=(const Point3D& other)
    {
        X += other.X;
        Y += other.Y;
        Z += other.Z;
        return *this;
    }

    Point3D& Point3D::operator-=(const Point3D& other)
    {
        X -= other.X;
        Y -= other.Y;
        Z -= other.Z;
        return *this;
    }

    Point3D Point3D::operator+(const Point3D& other) const
    {
        return Point3D(X + other.X, Y + other.Y, Z + other.Z);
    }

    Point3D Point3D::operator-(const Point3D& other) const
    {
        return Point3D(X - other.X, Y - other.Y, Z - other.Z);
    }

    Point3D Point3D::operator*(const Point3D& other) const
    {
        return Point3D(X * other.X, Y * other.Y, Z * other.Z);
    }

    Point3D Point3D::operator*(double scalar) const
    {
        return Point3D(X * scalar, Y * scalar, Z * scalar);
    }

    // ostream operator
    std::ostream& operator<<(std::ostream& os, const Point3D& p)
    {
        os << "(" << p.X << ", " << p.Y << ", " << p.Z << ")";
        return os;
    }
}
