/* Copyright © 2025 Osarobo Famous Okhuahesogie (famous.osarobo@gmail.com)
*
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "bezier-curve-3d/Point3D.h"

namespace bezier_curve_3d
{
    Point3D::Point3D(double x, double y, double z) : X(x), Y(y), Z(z) {}

    Point3D& Point3D::operator*=(double scalar)
    {
        X *= scalar;
        Y *= scalar;
        Z *= scalar;
        return *this;
    }

    Point3D& Point3D::operator/=(double scalar)
    {
        if (scalar != 0.0){
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
