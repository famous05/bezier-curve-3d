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
    };
}
