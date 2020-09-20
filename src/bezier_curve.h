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
    BezierLite::BezierCurve

Description
    Bezier curve class for constructing Bezier curves

SourceFiles
    bezier_curve.cpp

This file is part of BezierLite library
------------------------------------------------------------------------------*/




// Developer Headers
#include "point.h"
#include "bezier_control_point.h"
#include "curve.h"
#include "curve_writer.h"

namespace BezierLite
{

#ifndef BEZIERCURVE
#define BEZIERCURVE

class BezierCurve : public BezierLite::Curve
{
    public:


        /* Default constructor */
        BezierCurve();

        /* Initializes Bezier curve with control points cpts; requesting a
           curve containing 'num_curve_points'  */
        BezierCurve(const std::vector<BezierLite::BezierControlPoint>& cpts,
                                                		int num_curve_points);

        /* Initializes Bezier curve with points cpts; requesting a
           curve containing 'num_curve_points'  */
        BezierCurve(const std::vector<BezierLite::Point>& cpts,
                                                int num_curve_points);

        /* Copy constructor  */
        BezierCurve(const BezierCurve& bezier_curve);


        /* Assignment operator */
        BezierCurve& operator = (const BezierCurve& bezier_curve);


        /* Default destructor */
        virtual ~BezierCurve();


        /* Prints the Bezier curve control points */
        void printControlPoints();


        std::vector<BezierLite::BezierControlPoint>& getControlPoints();
        

        static std::vector<BezierLite::Point>
        getBezierCurve(const std::vector<BezierLite::BezierControlPoint>& cpts, 
        														int num_points);

        static std::vector<BezierLite::Point>
        getBezierCurve(const std::vector<BezierLite::Point>& cpts, 
        														int num_points);


        void appendControlPoint(const BezierLite::BezierControlPoint& p);
        void appendControlPoint(const BezierLite::Point& p);
        void clearControlPoints();
        void setNumCurvePoints(int num_points_on_curve);


        void scaleControlPoints(double factor);
        void constructCurve();


    private:
        int getFactorial(int n) const;
        double getBinomialCoefficient(int n, int i) const;
        double getBernsteinPolynomial(int i, int n, double t) const;



    private:
        std::vector<BezierLite::BezierControlPoint> ctrl_points;
        int num_curve_points;
};
#endif


}  // End of namespace BezierLite

