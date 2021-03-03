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


Class
    BezierLite::BezierCurve

Description
    Bezier curve class for constructing Bezier curves

SourceFiles
    BezierCurve.cxx

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


        BezierCurve();

        BezierCurve(const std::vector<BezierLite::BezierControlPoint>& cpts, int nCurvePoints);

        BezierCurve(const std::vector<BezierLite::Point>& cpts, int nCurvePoints);

        BezierCurve(const BezierCurve& bezierCurve);

        BezierCurve& operator = (const BezierCurve& bezierCurve);

        virtual ~BezierCurve();

        void PrintControlPoints();

        std::vector<BezierLite::BezierControlPoint>& GetControlPoints();


        static std::vector<BezierLite::Point> GetBezierCurve(
        	const std::vector<BezierLite::BezierControlPoint>& cpts, int nPoints);

        static std::vector<BezierLite::Point> GetBezierCurve(
        	const std::vector<BezierLite::Point>& cpts, int nPoints);


        void AppendControlPoint(const BezierLite::BezierControlPoint& p);

        void AppendControlPoint(const BezierLite::Point& p);

        void ClearControlPoints();

        void SetNumberOfCurvePoints(int nCurvePoints);

        void ScaleControlPoints(double factor);

        void ConstructCurve();


    private:

        int GetFactorial(int n) const;

        double GetBinomialCoefficient(int n, int i) const;

        double GetBernsteinPolynomial(int i, int n, double t) const;


    private:

        std::vector<BezierLite::BezierControlPoint> m_BezierControlPoints;

        int m_nCurvePoints;
};
#endif


}  // End of namespace BezierLite
