
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
#include "Point.hxx"


namespace BezierLite
{



Point::Point()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Point::Point(const double& x, const double& y, const double& z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Point::Point(const Point& p)
{
    this->x = p.GetX();
    this->y = p.GetY();
    this->z = p.GetZ();
}

Point& Point::operator =(const Point& point)
{
	if (&point != this)
	{
		this->x = point.GetX();
		this->y = point.GetY();
		this->z = point.GetZ();
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
void Point::SetX(const double& x)
{
    this->x = x;
}

void Point::SetY(const double& y)
{
    this->y = y;
}

void Point::SetZ(const double& z)
{
    this->z = z;
}

void Point::SetXYZ(const double& x, const double& y, const double& z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
// End of setters ***


// Getters ***
double Point::GetX() const
{
    return this->x;
}

double Point::GetY() const
{
    return this->y;
}

double Point::GetZ() const
{
    return this->z;
}

double Point::GetDistBtwPoints(const Point &p1, const Point &p2)
{
    return std::sqrt(std::pow(p2.GetX() - p1.GetX(), 2) +
    std::pow(p2.GetY() - p1.GetY(), 2) +
    std::pow(p2.GetZ() - p1.GetZ(), 2));
}

double Point::GetDistToPoint(const Point &p) const
{
    return BezierLite::Point::GetDistBtwPoints(*this, p);
}
// End of getters ***


Point& Point::operator+(const Point& p) const
{
    BezierLite::Point* point = new BezierLite::Point(0,0,0);
    point->SetX(this->x + p.GetX());
    point->SetY(this->y + p.GetY());
    point->SetZ(this->z + p.GetZ());
    return *point;

    // Clear memory
    delete point;
    point = nullptr;
}

Point& Point::operator-(const Point& p) const
{
    BezierLite::Point* point = new BezierLite::Point(0,0,0);
    point->SetX(this->x - p.GetX());
    point->SetY(this->y - p.GetY());
    point->SetZ(this->z - p.GetZ());
    return *point;

    // Clear memory
    delete point;
    point = nullptr;
}


Point& Point::operator*(const Point& p) const
{
    BezierLite::Point* point = new BezierLite::Point(0,0,0);
    point->SetX(this->x * p.GetX());
    point->SetY(this->y * p.GetY());
    point->SetZ(this->z * p.GetZ());
    return *point;

    // Clear memory
    delete point;
    point = nullptr;
}

Point& Point::operator*(const double& val) const
{
    BezierLite::Point* point = new BezierLite::Point(0,0,0);
    point->SetX(this->x * val);
    point->SetY(this->y * val);
    point->SetZ(this->z * val);
    return *point;

    // Clear memory
    delete point;
    point = nullptr;
}

const Point& Point::AddPoints(const Point& p1, const Point& p2)
{
    BezierLite::Point* p = new BezierLite::Point(0,0,0);
    p->SetX(p1.GetX() + p2.GetX());
    p->SetY(p1.GetY() + p2.GetY());
    p->SetZ(p1.GetZ() + p2.GetZ());
    return *p;

    // Clear memory
    delete p;
    p = nullptr;
}

const Point& Point::SubtractPoints(const Point& p1, const Point& p2)
{
    BezierLite::Point* p = new BezierLite::Point(0,0,0);
    p->SetX(p1.GetX() - p2.GetX());
    p->SetY(p1.GetY() - p2.GetY());
    p->SetZ(p1.GetZ() - p2.GetZ());
    return *p;

    // Clear memory
    delete p;
    p = nullptr;
}

const Point& Point::MultiplyPoints(const Point& p1, const Point& p2)
{
    BezierLite::Point* p = new BezierLite::Point(0,0,0);
    p->SetX(p1.GetX() * p2.GetX());
    p->SetY(p1.GetY() * p2.GetY());
    p->SetZ(p1.GetZ() * p2.GetZ());
    return *p;

    // Clear memory
    delete p;
    p = nullptr;
}

const Point& Point::MultiplyPointByValue(const Point& p1, const double& val)
{
    BezierLite::Point* p = new BezierLite::Point(0,0,0);
    p->SetX(p1.GetX() * val);
    p->SetY(p1.GetY() * val);
    p->SetZ(p1.GetZ() * val);
    return *p;

    // Clear memory
    delete p;
    p = nullptr;
}

void Point::ScalePoint(const double& factor)
{
    this->SetX(this->GetX() * factor);
    this->SetY(this->GetY() * factor);
    this->SetZ(this->GetZ() * factor);
}

} // End of namespace BezierLite
