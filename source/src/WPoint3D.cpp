
/*------------------------------------------------------------------------------
WPoint3D.cpp

This file is part of BezierLite library
Copyright (c) 2025, Famous Okhuahesogie, famous.osarobo@gmail.com
------------------------------------------------------------------------------*/

#include "WPoint3D.h"

namespace BezierLite
{

WPoint3D::WPoint3D() : Point3D(0, 0, 0)
{
    this->W = 1;
}

WPoint3D::WPoint3D (double X, double Y, double Z, double W) : Point3D(X, Y, Z)
{
    this->W = W;
}

WPoint3D::WPoint3D(const WPoint3D& P) :
			Point3D(P.X, P.Y, P.Z)
{
	this->W = P.W;
}


WPoint3D& WPoint3D::operator = (const WPoint3D& P)
{
	if (&P != this)
	{
		this->X = P.X;
		this->Y = P.Y;
		this->Z = P.Z;
		this->W = P.W;
	}

	return *this;
}

WPoint3D::~WPoint3D(){}

} 