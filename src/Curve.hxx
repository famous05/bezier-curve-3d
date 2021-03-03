
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
    BezierLite::Curve

Description
    A curve consists of at least two points

SourceFiles
    Curve.cpp

This file is part of BezierLite library
------------------------------------------------------------------------------*/


// C++ Headers
#include <algorithm>
#include <vector>


// Developer Headers
#include "Point.hxx"
#include "CurveWriter.hxx"


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


        void PrintCurve();


        const std::vector<BezierLite::Point>& GetCurve() const;


        int GetNumberOfCurvePoints();


        // static member functions do not require an object for use
        template <typename T> static void PrintCurve(const std::vector<T>& vp)
        {
            for(auto p : vp) p.Print();
        }


        template <typename T> static void ScaleCurve (std::vector<T>& vp, double scaleFactor)
        {
            for (auto &p : vp) p.ScalePoint(scaleFactor);
        }


        void AppendPointToCurve(const BezierLite::Point& p);

        void ClearCurve();

        void ScaleCurve(double factor);

        void WriteCurveToCSV(std::string fileName, int colWidth = 10);
        void WriteCurveToTSV(std::string fileName, int colWidth = 10);


    private:
        std::vector<BezierLite::Point> m_CurvePoints;
};
#endif

}  // End of namespace BezierLite
