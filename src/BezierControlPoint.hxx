/*------------------------------------------------------------------------------
BezierLite Library

Copyright (c) 2021, Osarobo Famous Okhuahesogie, famous.osarobo@gmail.com

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


This file is part of BezierLite library
------------------------------------------------------------------------------*/

// Developer Headers
#include "Point.hxx"

namespace BezierLite
{

#ifndef BEZIERCONTROLPOINT
#define BEZIERCONTROLPOINT

class BezierControlPoint : public BezierLite::Point
{
    public:

        /// Default constructor        
    	BezierControlPoint();


        /// Parameterized Constructor
        /// @param x, y ,z coordinate valuea and w weight
        BezierControlPoint(double x, double y, double z, double weight = 1);


        /// Copy constructor
        BezierControlPoint(const BezierControlPoint& cpoint);


        /// Assignment Constructor
        BezierControlPoint& operator = (const BezierControlPoint& point);

        virtual ~BezierControlPoint();


        /// Prints the BezierControlPoint object to screen
        void Print();


        /// Returns the weight of the BezierControlPoint
        double GetWeight() const;


        /// Set weight of BezierControlPoint
        /// @param w weight value between 
        void SetWeight(double w);


        /// Sets the coordinates and weight value
        /// @param x X coordinate value
        /// @param y Y coordinate value
        /// @param x Z coordinate value
        /// @param w Weight of control point
        void SetXYZW(double x, double y, double z, double w);

    private:
        double weight;
};
#endif

}  // End of namespace BezierLite
