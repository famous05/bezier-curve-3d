
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


// Developer Headers
#include "LinearInterpolator.hxx"

namespace BezierLite
{


LinearInterpolator::LinearInterpolator()
{

}

LinearInterpolator::LinearInterpolator(const std::vector<BezierLite::Point>& ctrlPoints,
                                                int nCtrlPoints)
{
    for(auto cp : ctrlPoints) this->m_ControlPoints.push_back(cp);

    this->SetNumberOfCurvePoints(nCtrlPoints);
}

LinearInterpolator::LinearInterpolator(const LinearInterpolator& linterCurve)
{
    this->ClearControlPoints();
	  this->m_ControlPoints = linterCurve.m_ControlPoints;

    this->ClearCurve();
	   for (auto p : linterCurve.GetCurve())
          this->AppendPointToCurve(p);
	   this->m_NumberOfCurvePoints = linterCurve.m_NumberOfCurvePoints;
}


LinearInterpolator& LinearInterpolator::operator =(const LinearInterpolator& linterCurve)
{
	if (&linterCurve != this)
	{
        this->ClearControlPoints();
        this->m_ControlPoints = linterCurve.m_ControlPoints;

        this->ClearCurve();
        for (auto p : linterCurve.GetCurve())
            this->AppendPointToCurve(p);
        this->m_NumberOfCurvePoints = linterCurve.m_NumberOfCurvePoints;
	}
	return *this;
}


LinearInterpolator::~LinearInterpolator()
{
    this->ClearControlPoints();
    this->ClearCurve();
}


void LinearInterpolator::PrintControlPoints()
{
    BezierLite::Curve::PrintCurve(this->m_ControlPoints);
}

void LinearInterpolator::SetNumberOfCurvePoints(int nCurvePoints)
{
    this->m_NumberOfCurvePoints = nCurvePoints;
}


std::vector<BezierLite::Point> LinearInterpolator::GetLinearInterpolatorCurve
(const std::vector<BezierLite::Point>& ctrlPoints, int nPoints)
{
    auto linterCurve = std::make_shared<BezierLite::LinearInterpolator>(ctrlPoints, nPoints);
    linterCurve->ConstructCurve();
    return linterCurve->GetCurve();
}


void LinearInterpolator::ConstructCurve()
{

    // Clear existing curve points if not empty
    if (!(this->GetCurve().empty())) this->ClearCurve();

    // utilility point
    auto point = std::make_shared<BezierLite::Point> (0, 0, 0);

    // Construct vector of cummulative linear length distribution of ctrl points
    std::vector<double> cumLengths;
    double iSumLen = 0;
    int counter = 0;

    for (const auto& p : this->m_ControlPoints)
    {
        if (counter == 0)
        {
            cumLengths.push_back(0);
            *point = p;
        }
        else
        {
            iSumLen = iSumLen + p.GetDistanceToPoint(*point);
            cumLengths.push_back(iSumLen);
            *point = p;
        }
        counter += 1;
    }
    //**************************************************************************


    // Normalise the cummulative distance to 0 -> 1 ****************************
    std::vector<double> cumLengthsNorm;
    auto maxCumLen = std::max_element(cumLengths.begin(), cumLengths.end());

    for (const auto& len : cumLengths)
    {
        cumLengthsNorm.push_back(len / (*maxCumLen));
    }
    //**************************************************************************


    // Compute interpolate points fractions (the parameter t) 0 <= t <= 1 ******
    double t = 0;
    std::vector<double> tDist;
    for (int i = 0; i < this->m_NumberOfCurvePoints; i++)
    {
        t = double(i) / double(this->m_NumberOfCurvePoints - 1);
        tDist.push_back(t);
    }
    //**************************************************************************



    // Interpolate points based on t parameter compared to ctrl points *********
    // normalised cummulative length. Both are from 0 to 1

    double frac;
    double  = tValPrev;

    // Append first control point
    this->AppendPointToCurve(this->m_ControlPoints.front());

    for(int i = 1; i < cumLengthsNorm.size()-1; i++) // ctrl points norm vals
    {
        for (auto t : tDist)
        {
            // First add original control points
            if ((cumLengthsNorm.at(i) > tValPrev) && (cumLengthsNorm.at(i) < t))
            {
                this->AppendPointToCurve(this->m_ControlPoints.at(i));
            }

            if ((t >= cumLengthsNorm.at(i)) && (t < cumLengthsNorm.at(i+1)))
            {
                frac = (t - cumLengthsNorm.at(i)) /
                (cumLengthsNorm.at(i+1) - cumLengthsNorm.at(i));
                *point = LinearInterpolator::GetPointAt
                (this->m_ControlPoints.at(i), this->m_ControlPoints.at(i+1), frac);
                this->AppendPointToCurve(*point);
            }

            tValPrev = t;
        }
    }

    // Append last control point
    this->AppendPointToCurve(this->m_ControlPoints.back());

    //**************************************************************************
}


const std::vector<BezierLite::Point>& LinearInterpolator::GetControlPoints() const
{
    return this->m_ControlPoints;
}


void LinearInterpolator::ClearControlPoints()
{
    this->m_ControlPoints.clear();
}


const BezierLite::Point& LinearInterpolator::GetPointAt(const BezierLite::Point& p1,
                                const BezierLite::Point& p2, double frac)
{
   return p1 + ((p2 - p1) * frac);
}


void LinearInterpolator::AppendControlPoint(const BezierLite::Point& p)
{
    this->m_ControlPoints.push_back(p);
}


} // End of namespace BezierLite
