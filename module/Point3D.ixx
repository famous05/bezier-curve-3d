export module Point3D;

import <iostream>;
import <cmath>;
import <format>;

export class Point3D
{
    public:

    double X, Y, Z;
	
    // Constructors
	constexpr Point3D() noexcept = default;
	constexpr Point3D(double x, double y, double z) noexcept: X{X}, Y{y}, Z{z} {}

    constexpr Point3D(const Point3D&) noexcept = default;
    constexpr Point3D(Point3D&&) noexcept = default;
    constexpr Point3D& operator=(const Point3D&) noexcept = default;
    constexpr Point3D& operator=(Point3D&&) noexcept = default;

    virtual ~Point3D() = default;

	Point3D& operator *=(double s)
	{
		X *= s;
		Y *= s;
		Z *= s;
		return (*this);
	}

	Point3D& operator /=(double s)
	{
		s = 1.0F / s;
		X *= s;
		Y *= s;
		Z *= s;
		return (*this);
	}

	Point3D& operator +=(const Point3D& p)
	{
		X += p.X;
		Y += p.Y;
		Z += p.Z;
		return (*this);
	}

	Point3D& operator -=(const Point3D& p)
	{
		X -= p.X;
		Y -= p.Y;
		Z -= p.Z;
		return (*this);
	}
};
