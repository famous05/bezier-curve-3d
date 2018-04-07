
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
    BezierLite::Point

Description
    (X, Y, Z) 3D Point

SourceFiles
    point.cpp

This file is part of BezierLite library
------------------------------------------------------------------------------*/


// Class header
#include "point.h"


namespace BezierLite
{



Point::Point()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Point::Point(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Point::Point(const Point& p)
{
    this->x = p.getX();
    this->y = p.getY();
    this->z = p.getZ();
}

Point& Point::operator =(const Point& point)
{
	if (&point != this)
	{
		this->x = point.x;
		this->y = point.y;
		this->z = point.z;
	}

	return *this;
}

Point::~Point()
{

}

void Point::print()
{
    std::cout << std::left << std::setw(10) << this->x;
    std::cout << std::left << std::setw(10) << this->y;
    std::cout << std::left << std::setw(10) << this->z;
    std::cout << std::endl;
}

// Setters ***
void Point::setX(double x)
{
    this->x = x;
}

void Point::setY(double y)
{
    this->y = y;
}

void Point::setZ(double z)
{
    this->z = z;
}

void Point::setXYZ(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
// End of setters ***


// Getters ***
double Point::getX() const
{
    return this->x;
}

double Point::getY() const
{
    return this->y;
}

double Point::getZ() const
{
    return this->z;
}

double Point::getDistBtwPoints(const Point &p1, const Point &p2)
{
    return std::sqrt(std::pow(p2.getX() - p1.getX(), 2) +
    std::pow(p2.getY() - p1.getY(), 2) +
    std::pow(p2.getZ() - p1.getZ(), 2));
}

double Point::getDistToPoint(const Point &p) const
{
    return BezierLite::Point::getDistBtwPoints(*this, p);
}
// End of getters ***


Point& Point::operator+(const Point& p) const
{
    BezierLite::Point* point = new BezierLite::Point(0,0,0);
    point->setX(this->getX() + p.getX());
    point->setY(this->getY() + p.getY());
    point->setZ(this->getZ() + p.getZ());
    return *point;

    // Clear memory
    delete point;
    point = nullptr;
}

Point& Point::operator-(const Point& p) const
{
    BezierLite::Point* point = new BezierLite::Point(0,0,0);
    point->setX(this->getX() - p.getX());
    point->setY(this->getY() - p.getY());
    point->setZ(this->getZ() - p.getZ());
    return *point;

    // Clear memory
    delete point;
    point = nullptr;
}


Point& Point::operator*(const Point& p) const
{
    BezierLite::Point* point = new BezierLite::Point(0,0,0);
    point->setX(this->getX() * p.getX());
    point->setY(this->getY() * p.getY());
    point->setZ(this->getZ() * p.getZ());
    return *point;

    // Clear memory
    delete point;
    point = nullptr;
}

Point& Point::operator*(double val) const
{
    BezierLite::Point* point = new BezierLite::Point(0,0,0);
    point->setX(this->getX() * val);
    point->setY(this->getY() * val);
    point->setZ(this->getZ() * val);
    return *point;

    // Clear memory
    delete point;
    point = nullptr;
}

const Point& Point::addPoints(const Point& p1, const Point& p2)
{
    BezierLite::Point* p = new BezierLite::Point(0,0,0);
    p->setX(p1.getX() + p2.getX());
    p->setY(p1.getY() + p2.getY());
    p->setZ(p1.getZ() + p2.getZ());
    return *p;

    // Clear memory
    delete p;
    p = nullptr;
}

const Point& Point::subtractPoints(const Point& p1, const Point& p2)
{
    BezierLite::Point* p = new BezierLite::Point(0,0,0);
    p->setX(p1.getX() - p2.getX());
    p->setY(p1.getY() - p2.getY());
    p->setZ(p1.getZ() - p2.getZ());
    return *p;

    // Clear memory
    delete p;
    p = nullptr;
}

const Point& Point::multiplyPoints(const Point& p1, const Point& p2)
{
    BezierLite::Point* p = new BezierLite::Point(0,0,0);
    p->setX(p1.getX() * p2.getX());
    p->setY(p1.getY() * p2.getY());
    p->setZ(p1.getZ() * p2.getZ());
    return *p;

    // Clear memory
    delete p;
    p = nullptr;
}

const Point& Point::multiplyPointByValue(const Point& p1, double val)
{
    BezierLite::Point* p = new BezierLite::Point(0,0,0);
    p->setX(p1.getX() * val);
    p->setY(p1.getY() * val);
    p->setZ(p1.getZ() * val);
    return *p;

    // Clear memory
    delete p;
    p = nullptr;
}

void Point::scalePoint(double factor)
{
    this->setX(this->getX() * factor);
    this->setY(this->getY() * factor);
    this->setZ(this->getZ() * factor);
}

} // End of namespace BezierLite
