/*------------------------------------------------------------------------------
Utils.cpp

This file is part of BezierLite library
Copyright (c) 2025, Famous Okhuahesogie, famous.osarobo@gmail.com
------------------------------------------------------------------------------*/

#include "Utils.h"

namespace BezierLite
{
    double Utils::GetDistanceBetweenPoints(const Point3D& p1, const Point3D& p2) noexcept
    {
        Eigen::Vector3d v1(p1.X, p1.Y, p1.Z);
        Eigen::Vector3d v2(p2.X, p2.Y, p2.Z);
        return (v1 - v2).norm();
    }

    int Utils::GetFactorial(int n)
    {
        if (n == 0 || n == 1) return 1;

        return n * Utils::GetFactorial(n - 1);
    }

    double Utils::GetBinomialCoefficient(int n, int i)
    {
        return Utils::GetFactorial(n)/((Utils::GetFactorial(i)) *
                                                    (Utils::GetFactorial(n - i)));
    }

    double Utils::GetBernsteinPolynomial(int i, int n, double t)
    {
        return Utils::GetBinomialCoefficient(n, i) * std::pow(t, i) * std::pow(1 - t, n - i);
    }
}
