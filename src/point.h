
/*------------------------------------------------------------------------------
BezierLite Library

Copyright (c) 2018, Osarobo Famous Okhuahesogie, famous.osarobo@gmail.com

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
    point.cpp

This file is part of BezierLite library
------------------------------------------------------------------------------*/


// C++ Headers
#include <iostream>
#include <cmath>
#include <iomanip>


namespace BezierLite
{

#ifndef POINT
#define POINT

class Point
{
    public:

        /* Default constructor */
        Point();


        /* Initialize with x,y,z values of point */
        Point(double x, double y, double z);


        /* Copy constructor */
        Point(const Point& p);


        /* Assignment operator */
        Point& operator = (const Point& point);


        /* Default destructor */
        virtual ~Point();

        /* Prints the x,y,z coordinates of point */
        virtual void print();


        /***********************************************************************
        *** Setter member functions ***
        ***********************************************************************/
        void setX(double x);
        void setY(double y);
        void setZ(double z);
        void setXYZ(double x, double y, double z);

        /***********************************************************************
        *** End of setter member functions ***
        ***********************************************************************/



        /***********************************************************************
        *** Getter member functions ***
        ***********************************************************************/

        double getX() const;
        double getY() const;
        double getZ() const;

        /* Returns the distance between Points p1 and p2 */
        static double getDistBtwPoints(const Point& p1, const Point& p2);

        /* Returns the distance between calling point object and Point p */
        double getDistToPoint(const Point& p) const;

        /***********************************************************************
        *** End of Getter member functions ***
        ***********************************************************************/



        /***********************************************************************
        *** Actor member functions ***
        ***********************************************************************/

        /* Adds the (x,y,z) components of Points p and calling point object
           (x,y,z) components and returns a reference to Point object. */
        Point& operator+(const Point& p) const;


        /* Subtracts the (x,y,z) components of Points p from the calling point
           object (x,y,z) components and returns a reference to Point object. */
        Point& operator-(const Point& p) const;


        /* Multiplies the (x,y,z) components of Point p and the calling point
           object (x,y,z) components and returns a reference to Point object. */
        Point& operator*(const Point& p) const;


        /* Multiplies the (x,y,z) components of Point p by value  and returns
           a reference to Point object */
        Point& operator*(double val) const;



        /* Adds the (x,y,z) components of Points p1 and p2 and returns a
           const reference to Point object */
        static const Point& addPoints(const Point& p1, const Point& p2);


        /* Subtracts the (x,y,z) components of p2 from the (x,y,z) components of
           p1 and returns a const reference to Point object */
        static const Point& subtractPoints(const Point& p1, const Point& p2);


        /* Multiplies the (x,y,z) components of p1 and p2 and returns a const
           reference to Point object */
        static const Point& multiplyPoints(const Point& p1, const Point& p2);

        /* Multiplies the (x,y,z) components of p1 by val and returns a const
           reference to Point object */
        static const Point& multiplyPointByValue(const Point& p1, double val);


        /* Scales the (x,y,z) components of calling point by factor */
        void scalePoint(double factor);

        /***********************************************************************
        *** End of actor member functions ***
        ***********************************************************************/

    private:
        double x;
        double y;
        double z;
};
#endif

}  // End of namespace BezierLite

