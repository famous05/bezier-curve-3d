/*------------------------------------------------------------------------------
BezierLite Library

Copyright (c) 2020, Osarobo Famous Okhuahesogie, famous.osarobo@gmail.com

License
    This file is part of BezierLite library. 
    BezierLite is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    BezierLite is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with BezierLite.  If not, see <http://www.gnu.org/licenses/>.


Class
    BezierLite::BezierControlPoint

Description
    (X, Y, Z, Weight) 3D Control Point for Bezier Curves and Bezier Surfaces 

SourceFiles
    bezier_control_point.cpp

This file is part of BezierLite library
------------------------------------------------------------------------------*/


// Developer Headers
#include "point.h"


namespace BezierLite
{

#ifndef BEZIERCONTROLPOINT
#define BEZIERCONTROLPOINT

class BezierControlPoint : public BezierLite::Point
{
    public:

    	/* Default constructor */
    	BezierControlPoint();

        /* Initialize control point using x,y,z coordinates and weight */
        BezierControlPoint(const double x, const double y, const double z,
                                                        const double weight = 1);

        /* Copy constructor */
        BezierControlPoint(const BezierControlPoint& cpoint);


        /* Assignment operator */
        BezierControlPoint& operator = (const BezierControlPoint& point);


        /* Default destructor */
        virtual ~BezierControlPoint();
        

        /* Prints the x,y,z coordiates and weight of control point */
        void print();

        
        double getWeight() const;


        void setWeight(const double w);
        void setXYZW(const double x, const double y, const double z,
                                                                const double w);

    private:
        double weight;
};
#endif

}  // End of namespace BezierLite
