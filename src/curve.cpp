
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
#include "curve.h"

namespace BezierLite
{

Curve::Curve()
{

}

Curve::Curve(const Curve& c)
{
    this->clearCurve();
    for(auto p : c.curve_points) this->curve_points.push_back(p);
}

Curve& Curve::operator =(const Curve& c)
{
	if (&c != this)
	{
		this->clearCurve();
        for(auto p : c.curve_points) this->curve_points.push_back(p);
	}
	return *this;
}


Curve::~Curve()
{
    this->clearCurve();
}


void Curve::printCurve()
{
	BezierLite::Curve::printCurve(this->curve_points);
}


const std::vector<BezierLite::Point>& Curve::getCurve() const
{
    return this->curve_points;
}


int Curve::getNumCurvePoints()
{
    return this->curve_points.size();
}


void Curve::appendPointToCurve(const BezierLite::Point &p)
{
    this->curve_points.push_back(p);
}


void Curve::clearCurve()
{
    if (!(this->curve_points.empty())) this->curve_points.clear();
}


void Curve::scaleCurve(double factor)
{
    BezierLite::Curve::scaleCurve(this->curve_points, factor);
}


void Curve::writeCurveToCSV(std::string file_name, int col_width)
{
	BezierLite::CurveWriter::writeToCSV
	(this->getCurve(), file_name, col_width);
}

void Curve::writeCurveToTSV(std::string file_name, int col_width)
{
	BezierLite::CurveWriter::writeToTSV
	(this->getCurve(), file_name, col_width);
}

} // End of namespace BezierLite



