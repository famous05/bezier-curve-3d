
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


// Developer Headers
#include "Curve.hxx"

namespace BezierLite
{

Curve::Curve()
{

}

Curve::Curve(const Curve& c)
{
    this->ClearCurve();

    for(auto &p : c.m_CurvePoints) this->m_CurvePoints.push_back(p);
}

Curve& Curve::operator =(const Curve& c)
{
	if (&c != this)
	{
		this->ClearCurve();

        for(auto &p : c.m_CurvePoints) this->m_CurvePoints.push_back(p);
	}

	return *this;
}


Curve::~Curve()
{
    this->ClearCurve();
}


void Curve::PrintCurve()
{
	BezierLite::Curve::PrintCurve(this->m_CurvePoints);
}


const std::vector<BezierLite::Point>& Curve::GetCurve() const
{
    return this->m_CurvePoints;
}


int Curve::GetNumberOfCurvePoints()
{
    return this->m_CurvePoints.size();
}


void Curve::AppendPointToCurve(const BezierLite::Point &p)
{
    this->m_CurvePoints.push_back(p);
}


void Curve::ClearCurve()
{
    if (!(this->m_CurvePoints.empty())) this->m_CurvePoints.clear();
}


void Curve::ScaleCurve(double factor)
{
    BezierLite::Curve::ScaleCurve(this->m_CurvePoints, factor);
}


void Curve::WriteCurveToCSV(std::string fileName, int colWidth)
{
	BezierLite::CurveWriter::WriteToCSV
	(this->m_CurvePoints, fileName, colWidth);
}

void Curve::WriteCurveToTSV(std::string fileName, int colWidth)
{
	BezierLite::CurveWriter::WriteToTSV
	(this->m_CurvePoints, fileName, colWidth);
}

} // End of namespace BezierLite



