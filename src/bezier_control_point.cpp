
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
    BezierLite::BezierControlPoint

Description
    (X, Y, Z, Weight) 3D Control Point for Bezier Curves and Bezier Surfaces 

SourceFiles
    bezier_control_point.cpp

This file is part of BezierLite library
------------------------------------------------------------------------------*/

// Developer Headers
#include "bezier_control_point.h"


namespace BezierLite
{


BezierControlPoint::BezierControlPoint()
{
	this->setX(0);
	this->setY(0);
	this->setZ(0);
	this->setWeight(0);
}

BezierControlPoint::BezierControlPoint (const double x, const double y, 
										const double z, const double w) :
                                        BezierLite::Point(x,y,z)
{
    this->weight = w;
}

BezierControlPoint::BezierControlPoint(const BezierControlPoint& cpoint) : 
			BezierLite::Point(cpoint.getX(), cpoint.getY(), cpoint.getZ())
{
	this->weight = cpoint.getWeight();
}


BezierControlPoint& BezierControlPoint::operator = (const BezierControlPoint& cpoint)
{
	if (&cpoint != this)
	{
		this->setX(cpoint.getX());
		this->setY(cpoint.getY());
		this->setZ(cpoint.getZ());
		this->weight = cpoint.getWeight();
	}

	return *this;
}

BezierControlPoint::~BezierControlPoint()
{

}

void BezierControlPoint::print()
{
    std::cout << std::left << std::setw(10) << this->getX();
    std::cout << std::left << std::setw(10) << this->getY();
    std::cout << std::left << std::setw(10) << this->getZ();
    std::cout << std::left << std::setw(10) << this->getWeight();
    std::cout << std::endl;
}

void BezierControlPoint::setWeight(const double w)
{
    this->weight = w;
}

void BezierControlPoint::setXYZW(const double x, const double y, 
												const double z, const double w)
{
    this->setXYZ(x,y,z);
    this->setWeight(w);
}


double BezierControlPoint::getWeight() const
{
    return this->weight;
}

} // End of namespace BezierLite