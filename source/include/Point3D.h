/*------------------------------------------------------------------------------
Point3D.h 
-  This is the header file for a Point class in 3D space with - X, Y, Z components

This file is part of BezierLite library
Copyright (c) 2025, Famous Okhuahesogie, famous.osarobo@gmail.com
------------------------------------------------------------------------------*/

#pragma once

#include <iostream>

namespace BezierLite
{
    class Point3D
    {
    public:
        double X{0.0};
        double Y{0.0};
        double Z{0.0};

        // Constructors
        Point3D() = default;
        Point3D(double x, double y, double z);

        // Copy and Move constructors/assignments
        Point3D(const Point3D&) = default;
        Point3D(Point3D&&) noexcept = default;
        Point3D& operator=(const Point3D&) = default;
        Point3D& operator=(Point3D&&) noexcept = default;

        // Destructor
        ~Point3D() = default;

        // Operators
        Point3D& operator*=(double scalar);
        Point3D& operator/=(double scalar);
        Point3D& operator+=(const Point3D& other);
        Point3D& operator-=(const Point3D& other);

        Point3D operator+(const Point3D& other) const;
        Point3D operator-(const Point3D& other) const;
        Point3D operator*(const Point3D& other) const;
        Point3D operator*(double scalar) const;
    };

    // Non-member operator to print Point3D
    std::ostream& operator<<(std::ostream& os, const Point3D& p);
}
