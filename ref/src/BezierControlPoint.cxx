
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
#include "BezierControlPoint.hxx"


namespace BezierLite
{


BezierControlPoint::BezierControlPoint()
{
	this->SetX(0);
	this->SetY(0);
	this->SetZ(0);
	this->SetWeight(0);
}

BezierControlPoint::BezierControlPoint (double x, double y,
										double z, double w) : BezierLite::Point(x, y, z)
{
    this->weight = w;
}

BezierControlPoint::BezierControlPoint(const BezierControlPoint& bCtrlPoint) :
			BezierLite::Point(bCtrlPoint.GetX(), bCtrlPoint.GetY(), bCtrlPoint.GetZ())
{
	this->weight = bCtrlPoint.GetWeight();
}


BezierControlPoint& BezierControlPoint::operator = (const BezierControlPoint& bCtrlPoint)
{
	if (&bCtrlPoint != this)
	{
		this->SetX(bCtrlPoint.GetX());
		this->SetY(bCtrlPoint.GetY());
		this->SetZ(bCtrlPoint.GetZ());
		this->weight = bCtrlPoint.GetWeight();
	}

	return *this;
}

BezierControlPoint::~BezierControlPoint()
{

}

void BezierControlPoint::Print()
{
    std::cout << std::left << std::setw(10) << this->GetX();
    std::cout << std::left << std::setw(10) << this->GetY();
    std::cout << std::left << std::setw(10) << this->GetZ();
    std::cout << std::left << std::setw(10) << this->GetWeight();
    std::cout << std::endl;
}

void BezierControlPoint::SetWeight(double w)
{
    this->weight = w;
}

void BezierControlPoint::SetXYZW(double x, double y,
												double z, double w)
{
    this->SetXYZ(x, y, z);
    this->SetWeight(w);
}


double BezierControlPoint::GetWeight() const
{
    return this->weight;
}

} // End of namespace BezierLite
