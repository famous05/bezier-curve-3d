/*------------------------------------------------------------------------------
BezierLite Library
Copyright (c) 2018 - 2021, Osarobo Famous Okhuahesogie, famous.osarobo@gmail.com
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

// C++ Headers
#include <algorithm>


// Developer Headers
#include "Point.hxx"
#include "Curve.hxx"

namespace BezierLite
{


#ifndef LINEARINTERPOLATOR
#define LINEARINTERPOLATOR

class LinearInterpolator : public BezierLite::Curve
{
    public:
        /// Default constructor
        LinearInterpolator();


        /// Initialization Constructor
        /// @param <Input> ctrlPoints. Vector of Point points
        /// @param <Input> nCurvePoints. Number of points on curve to be created  
        LinearInterpolator(const std::vector<BezierLite::Point>& ctrlPoints,
                                                int nCurvePoints);
        

        /// Copy constructor
        LinearInterpolator(const LinearInterpolator& linterCurve);


        /// Assignment operator
        /// @param <Input> linterCurve Linear interpolation curve to be assigned
        LinearInterpolator& operator = (const LinearInterpolator& linterCurve);


        /// Desctuctor
        virtual ~LinearInterpolator();


        /// Print the LinearInterpolator curve control points
        void PrintControlPoints();


        /// Call this function to construct curve after creating a curve object
        void ConstructCurve();


        /// @return Control points of curve
        const std::vector<BezierLite::Point>& GetControlPoints() const;


        /// Static function to create LinearInterpolator curve without creating an instance of 
        /// LinearInterpolator class
        /// @param cptsVector Vector of Point points
        /// @param nPoints Number of points for the curve to be created
        /// @return LinearInterpolator curve as vector of Point points
        static std::vector<BezierLite::Point>
        GetLinearInterpolatorCurve(const std::vector<BezierLite::Point>& ctrlPoints, int nPoints);


        /// @param <Input> p1 first point
        /// @param <Input> p2 second point
        /// @param <Input> frac fraction value between 0 and 1
        /// @return Point at frac of distance between p1 and p2 
        const BezierLite::Point& GetPointAt(const BezierLite::Point& p1,
                                        const BezierLite::Point& p2, double frac);


        /// Append a control point to the LinearInterpolator control points
        /// @param <Input> p Point to add
        void AppendControlPoint(const BezierLite::Point& p);


        /// Clears the control points
        void ClearControlPoints();


        /// Set number of points in LinearInterpolator curve
        /// @param numCurvePoints Number of cuve points
        void SetNumberOfCurvePoints(int numCurvePoints);

    private:
        std::vector<BezierLite::Point> m_ControlPoints;
        int m_NumberOfCurvePoints;
};
#endif


}  // End of namespace BezierLite
