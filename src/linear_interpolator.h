
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
    BezierLite::LinearInterpolator

Description
    Linear Interpolator between Points

SourceFiles
    linear_interpolator.cpp

This file is part of BezierLite library
------------------------------------------------------------------------------*/

// C++ Headers
#include <algorithm>


// Developer Headers
#include "point.h"
#include "curve.h"

namespace BezierLite
{


#ifndef LINEARINTERPOLATOR
#define LINEARINTERPOLATOR

class LinearInterpolator : public BezierLite::Curve
{
    public:

        /* Default constructor */
        LinearInterpolator();


        /* Initializes LinearInterpolator curve with points cpts; requesting a
        curve containing 'num_curve_points'  */
        LinearInterpolator(const std::vector<BezierLite::Point>& cpts,
                                                int num_curve_points);

        /* Copy constructor  */
        LinearInterpolator(const LinearInterpolator& linter_curve);


        /* Assignment operator */
        LinearInterpolator& operator = (const LinearInterpolator& linter_curve);

        /* Default destructor */
        virtual ~LinearInterpolator();

        /* Prints the Linear Interpolator curve control points */
        void printControlPoints();

        void constructCurve();

        const std::vector<BezierLite::Point>& getControlPoints() const;

        static std::vector<BezierLite::Point>
        getLinearInterpolatorCurve(const std::vector<BezierLite::Point>& cpts, 
        														int num_points);


        const BezierLite::Point& getPointAt(const BezierLite::Point& p1, 
                                        const BezierLite::Point& p2, double frac);

        void appendControlPoint(const BezierLite::Point& p);

        void clearControlPoints();

        void setNumCurvePoints(int num_curve_points);



    private:
        std::vector<BezierLite::Point> ctrl_points;
        int num_curve_points;
};
#endif


}  // End of namespace BezierLite
