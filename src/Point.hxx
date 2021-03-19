
/*------------------------------------------------------------------------------
BezierLite Library

Copyright (c) 2017 - 2021, Osarobo Famous Okhuahesogie, famous.osarobo@gmail.com

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
    BezierLite::Point

Description
    (X, Y, Z) 3D Point

SourceFiles
    Point.cpp

This file is part of BezierLite library
------------------------------------------------------------------------------*/


// C++ Headers
#include <iostream>
#include <cmath>
#include <iomanip>
#include <memory>


namespace BezierLite
{

#ifndef POINT
#define POINT

class Point
{
    public:

        /// Default constructor
        Point();


        /// Parameterized constructor
        Point(double x, double y, double z);


        /// Copy constructor
        Point(const Point & p);


        /// Assignment operator
        Point& operator = (const Point& point);


        virtual ~Point();


        virtual void Print();


        void SetX(double x);
        void SetY(double y);
        void SetZ(double z);
        void SetXYZ(double x, double y, double z);


        double GetX() const;
        double GetY() const;
        double GetZ() const;

        /// Returns the distance between Points p1 and p2
        static double GetDistanceBetweenPoints(const Point& p1, const Point& p2);

        /// Returns the distance between calling point object and Point p
        double GetDistanceToPoint(const Point& p) const;


        /// Adds the (x,y,z) components of Points p and calling point object
        ///   (x,y,z) components and returns a reference to Point object.
        Point& operator+(const Point& p) const;


        /// Subtracts the (x,y,z) components of Points p from the calling point
        ///   object (x,y,z) components and returns a reference to Point object.
        Point& operator-(const Point& p) const;


        /// Multiplies the (x,y,z) components of Point p and the calling point
        ///   object (x,y,z) components and returns a reference to Point object.
        Point& operator*(const Point& p) const;


        /// Multiplies the (x,y,z) components of Point p by value  and returns
        ///   a reference to Point object
        Point& operator*(double val) const;


        /// Adds the (x,y,z) components of Points p1 and p2 and returns a
        /// const reference to Point object
        static const Point& AddPoints(const Point& p1, const Point& p2);


        /// Subtracts the (x,y,z) components of p2 from the (x,y,z) components
        /// of p1 and returns a const reference to Point object
        static const Point& SubtractPoints(const Point& p1, const Point& p2);


        /// Multiplies the (x,y,z) components of p1 and p2 and returns a const
        /// reference to Point object
        static const Point& MultiplyPoints(const Point& p1, const Point& p2);


        /// Multiplies the (x,y,z) components of p1 by val and returns a const
        /// reference to Point object
        static const Point& MultiplyPointByValue(const Point& p1, double val);


        /// Scales the (x,y,z) components of calling point by factor
        void ScalePoint(double factor);


    private:
        double x {0};
        double y {0};
        double z {0};
};
#endif

}  // End of namespace BezierLite
