
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
#include "BezierCurve.hxx"

namespace BezierLite
{

BezierCurve::BezierCurve()
{

}

BezierCurve::BezierCurve
(
	const std::vector<BezierLite::BezierControlPoint>& cpts,
    int nCurvePoints
)
{
    for(auto cp : cpts) this->m_BezierControlPoints.push_back(cp);
    this->SetNumberOfCurvePoints(nCurvePoints);
}

BezierCurve::BezierCurve
(
	const std::vector<BezierLite::Point>& cpts,
    int nCurvePoints
)
{
	// Convert control points to BezierControlPoint type, setting weight to 1
	std::unique_ptr<BezierLite::BezierControlPoint> cp(new BezierLite::BezierControlPoint(0, 0, 0, 1));

    for(auto p : cpts)
    {
    	cp->SetXYZ(p.GetX(), p.GetY(), p.GetZ());
		this->m_BezierControlPoints.push_back(*cp);
    }

    this->SetNumberOfCurvePoints(nCurvePoints);
}


BezierCurve::BezierCurve(const BezierCurve& bezierCurve)
{
	this->m_BezierControlPoints = bezierCurve.m_BezierControlPoints;

	this->ClearCurve();

	for (auto p : bezierCurve.GetCurve()) this->AppendPointToCurve(p);

	this->m_nCurvePoints = bezierCurve.m_nCurvePoints;
}


BezierCurve& BezierCurve::operator =(const BezierCurve& bezierCurve)
{
	if (&bezierCurve != this)
	{
		this->m_BezierControlPoints = bezierCurve.m_BezierControlPoints;

		this->ClearCurve();

		for (auto p : bezierCurve.GetCurve()) this->AppendPointToCurve(p);

		this->m_nCurvePoints = bezierCurve.m_nCurvePoints;
	}

	return *this;
}


BezierCurve::~BezierCurve()
{
    this->ClearControlPoints();
    this->ClearCurve();
}


void BezierCurve::PrintControlPoints()
{
	BezierLite::Curve::PrintCurve(this->m_BezierControlPoints);
}

std::vector<BezierLite::BezierControlPoint>& BezierCurve::GetControlPoints()
{
    return this->m_BezierControlPoints;
}


std::vector<BezierLite::Point> BezierCurve::GetBezierCurve
(
	const std::vector<BezierLite::BezierControlPoint>& cpts,
	int nPoints
)
{
    auto bCurve = std::make_unique<BezierLite::BezierCurve>(cpts, nPoints);
    bCurve->ConstructCurve();
    return bCurve->GetCurve();
}

std::vector<BezierLite::Point> BezierCurve::GetBezierCurve
(
	const std::vector<BezierLite::Point>& cpts,
	int nPoints
)
{
    auto bCurve = std::make_unique<BezierLite::BezierCurve>(cpts, nPoints);
    bCurve->ConstructCurve();
    return bCurve->GetCurve();
}


void BezierCurve::AppendControlPoint(const BezierLite::BezierControlPoint &p)
{
    this->m_BezierControlPoints.push_back(p);
}

void BezierCurve::AppendControlPoint(const BezierLite::Point &p)
{
	std::unique_ptr<BezierLite::BezierControlPoint> cp(new BezierLite::BezierControlPoint(0, 0, 0 ,1));
	cp->SetXYZ(p.GetX(), p.GetY(), p.GetZ());
    this->m_BezierControlPoints.push_back(*cp);
}


void BezierCurve::ClearControlPoints()
{
	if (!(this->m_BezierControlPoints.empty())) this->m_BezierControlPoints.clear();
}

void BezierCurve::SetNumberOfCurvePoints(int nCurvePoints)
{
    if (nCurvePoints < 3)
    {
        std::cout << "Warning: At least 3 points should be requested for";
        std::cout << " the Bezier curve to be constructed !" << std::endl;
        this->m_nCurvePoints = 3;
    }

    this->m_nCurvePoints = nCurvePoints;
}


void BezierCurve::ScaleControlPoints(double factor)
{
    BezierLite::Curve::ScaleCurve(this->m_BezierControlPoints, factor);
}

void BezierCurve::ConstructCurve()
{
    double t = 0;
    int n = this->m_BezierControlPoints.size() - 1;  // curve degree
    int i = 0;
    double denSum = 0;
    double weightTPoly = 0;

    // Clear existing curve points if not empty
    this->ClearCurve();

    // Check if all control points weights equal 1
    bool isWeighted = false;

    for (const auto& ctrlPoint : this->m_BezierControlPoints)
    {
    	if (ctrlPoint.GetWeight() != 1)
    	{
    		isWeighted = true;
    	}
    }

    BezierLite::Point* sPoint =  new BezierLite::Point(0,0,0);

    BezierLite::Point* point =  new BezierLite::Point(0,0,0);

    for (int j = 0; j < this->m_nCurvePoints; j++)
    {
        // Calculate t parameter: (0 <= t <= 1)
        t = (double)j/double(this->m_nCurvePoints - 1);
        i = 0;

        if (isWeighted == false)
        {
        	for (const auto& ctrlPoint : this->m_BezierControlPoints)
	        {
	            *point = ctrlPoint * this->GetBernsteinPolynomial(i,n,t);
	            *sPoint = *sPoint + *point;
	            i += 1;
	        }

	        //this->curve_points.push_back(*sPoint);
	        this->AppendPointToCurve(*sPoint);
	        sPoint->SetXYZ(0,0,0);
        }
        else
        {
        	for (const auto& ctrlPoint : this->m_BezierControlPoints)
	        {
	        	// denominator for each ctrl pt (weight * bernstein polynomial)
	        	weightTPoly = ctrlPoint.GetWeight() * this->GetBernsteinPolynomial(i,n,t);

	        	*point = ctrlPoint * weightTPoly;

	            *sPoint = *sPoint + *point;

	            // summation of denominator: den = den + weight * bernstein poly
	            denSum = denSum + weightTPoly;
	            i += 1;
	        }

	        *sPoint = *sPoint * (1 / denSum);
	        //this->curve_points.push_back(*sPoint);
	    	this->AppendPointToCurve(*sPoint);
	        sPoint->SetXYZ(0,0,0);
	        denSum = 0;
        }

    }

    delete sPoint;
    delete point;
    sPoint = nullptr;
    point = nullptr;

}


int BezierCurve::GetFactorial(int n) const
{
    if (n == 0 || n == 1) return 1;

    return n * this->GetFactorial(n - 1);
}

double BezierCurve::GetBinomialCoefficient(int n, int i) const
{
    /// Returns n!/(i! * (n-i)!)  i.e. nCi

    return this->GetFactorial(n)/((this->GetFactorial(i)) *
                                                (this->GetFactorial(n - i)));
}

double BezierCurve::GetBernsteinPolynomial(int i, int n, double t) const
{
    /// Retuns nCi * t^i * (1-t)^(n-i)

    return this->GetBinomialCoefficient(n, i) * std::pow(t, i) * std::pow(1 - t, n - i);
}


} // End of namespace BezierLite
