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
#include "BezierControlPoint.hxx"
#include "Curve.hxx"
#include "CurveWriter.hxx"

namespace BezierLite
{

#ifndef BEZIERCURVE
#define BEZIERCURVE

class BezierCurve : public BezierLite::Curve
{
    public:

        /// Default constructor
        BezierCurve();


        /// Parameterized constructor
        /// @param cpts Vector of BezierControlPoint points
        /// @param nCurvePoints Number of points for curve to be created
        BezierCurve(const std::vector<BezierLite::BezierControlPoint>& cpts, int nCurvePoints);


        /// Parameterized constructor
        /// @param cpts Vector of Point points
        /// @param nCurvePoints Number of points for curve to be created
        BezierCurve(const std::vector<BezierLite::Point>& cpts, int nCurvePoints);


        /// Copy constructor
        /// @param bezierCurve BezierCurve object to be copied
        BezierCurve(const BezierCurve& bezierCurve);


        /// Assignment operator
        /// @param bezierCurve BezierCurve object to be assigned
        BezierCurve& operator = (const BezierCurve& bezierCurve);


        /// Default destructor
        virtual ~BezierCurve();


        /// Print BezierCurve control points to the screen
        void PrintControlPoints();


        /// @return The BezierCurve control points
        std::vector<BezierLite::BezierControlPoint>& GetControlPoints();


        /// Static function to create BezierCurve without creating an instance of 
        /// BezierCurve class
        /// @param cptsVector Vector of BezierControlPoint points
        /// @param nPoints Number of points for the curve to be created
        /// @return BezierCurve as vector of Point points
        static std::vector<BezierLite::Point> GetBezierCurve(
        	const std::vector<BezierLite::BezierControlPoint>& cpts, int nPoints);


        /// Static function to create BezierCurve without creating an instance of 
        /// BezierCurve class
        /// @param cptsVector Vector BezierControlPoint points
        /// @param nPoints Number of points for the curve to be created
        /// @return BezierCurve as vector of Point points
        static std::vector<BezierLite::Point> GetBezierCurve(
        	const std::vector<BezierLite::Point>& cpts, int nPoints);


        /// Append a BezierControlPoint to BezierCurve control points
        /// @param p BezierControlPoint to append
        void AppendControlPoint(const BezierLite::BezierControlPoint& p);


        /// Append a BezierControlPoint to BezierCurve control points
        /// @param p Point to append
        void AppendControlPoint(const BezierLite::Point& p);


        /// Clears all control points
        void ClearControlPoints();


        /// Sets number of points in BezierCurve to be created
        /// @param nCurvePoints Number of points required
        void SetNumberOfCurvePoints(int nCurvePoints);


        /// Scale the BezierCurve control points by factor
        /// @param factor Scale factor
        void ScaleControlPoints(double factor);


        /// Function to construct the curve
        void ConstructCurve();


    private:

        int GetFactorial(int n) const;

        double GetBinomialCoefficient(int n, int i) const;

        double GetBernsteinPolynomial(int i, int n, double t) const;

        std::vector<BezierLite::BezierControlPoint> m_BezierControlPoints;

        int m_nCurvePoints;
};
#endif


}  // End of namespace BezierLite
