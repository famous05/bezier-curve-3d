/*------------------------------------------------------------------------------
Utils.h 
-  Header file for utility functions

This file is part of BezierLite library
Copyright (c) 2025, Famous Okhuahesogie, famous.osarobo@gmail.com
------------------------------------------------------------------------------*/

#pragma once

#include "Point3D.h"
#include <Eigen/Dense>

namespace BezierLite
{
    class Utils
    {
    public:
        static double GetDistanceBetweenPoints(const Point3D& p1, const Point3D& p2) noexcept;

        static int GetFactorial(int n);

        /// Returns n!/(i! * (n-i)!)  i.e. nCi
        static double GetBinomialCoefficient(int n, int i);

        /// Retuns nCi * t^i * (1-t)^(n-i)
        static double GetBernsteinPolynomial(int i, int n, double t);
    };
}
