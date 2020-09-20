
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
    BezierLite::Curve

Description
    A curve consists of at least two points

SourceFiles
    curve.cpp

This file is part of BezierLite library
------------------------------------------------------------------------------*/


// C++ Headers
#include <algorithm>
#include <vector>


// Developer Headers
#include "point.h"
#include "curve_writer.h"


namespace BezierLite
{

#ifndef CURVE
#define CURVE

class Curve
{
    public:

        /* Default constructor */
        Curve();

       
        /* Copy constructor  */
        Curve(const Curve& curve);


        /* Assignment operator */
        Curve& operator = (const Curve& curve);


        /* Default destructor */
        virtual ~Curve();


        void printCurve();


        const std::vector<BezierLite::Point>& getCurve() const;


        int getNumCurvePoints();


        // static member functions do not require an object for use
        template <typename T> static void printCurve(const std::vector<T>& vp)
        {
            for(auto p : vp) p.print();
        }


        template <typename T> static void scaleCurve
        (std::vector<T>& vp, const double scale_f)
        {
            for (auto &p : vp) p.scalePoint(scale_f);
        }

    
        void appendPointToCurve(const BezierLite::Point& p);

        void clearCurve();

        void scaleCurve(double factor);

        void writeCurveToCSV(std::string file_name, int col_width = 10);
        void writeCurveToTSV(std::string file_name, int col_width = 10);


    private:
        std::vector<BezierLite::Point> curve_points;
};
#endif

}  // End of namespace BezierLite

