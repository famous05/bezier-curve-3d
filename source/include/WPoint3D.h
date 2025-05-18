/*------------------------------------------------------------------------------
WPoint3D.h 
-  This is the header file for a Weighted Point class in 3D space with - X, Y, Z, W components

This file is part of BezierLite library
Copyright (c) 2025, Famous Okhuahesogie, famous.osarobo@gmail.com
------------------------------------------------------------------------------*/

#pragma once

#include "Point3D.h"

namespace BezierLite
{
    class WPoint3D : public Point3D
    {
        public:

            double W {1.0};

            /// Default constructor        
            WPoint3D();

            WPoint3D(double x, double y, double z, double w = 1);

            WPoint3D(const WPoint3D& P);

            /// Assignment Constructor
            WPoint3D& operator = (const WPoint3D& point);

            virtual ~WPoint3D();
    };
} 
