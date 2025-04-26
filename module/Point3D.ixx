export module Point3D;

import <Eigen/Dense>;
import <iostream>;
import <format>;
import <ostream>;

namespace BezierLite
{
	export class Point3D
	{
	public:
		// Constructors
		Point3D() noexcept = default;

		Point3D(double x, double y, double z) noexcept
			: coords_{x, y, z}
		{}

		Point3D(const Point3D&) noexcept = default;
		Point3D(Point3D&&) noexcept = default;
		Point3D& operator=(const Point3D&) noexcept = default;
		Point3D& operator=(Point3D&&) noexcept = default;

		virtual ~Point3D() = default;

		Point3D& operator*=(double s) noexcept
		{
			coords_ *= s;
			return *this;
		}

		Point3D& operator/=(double s) noexcept
		{
			coords_ /= s;
			return *this;
		}

		Point3D& operator+=(const Point3D& p) noexcept
		{
			coords_ += p.coords_;
			return *this;
		}

		Point3D& operator-=(const Point3D& p) noexcept
		{
			coords_ -= p.coords_;
			return *this;
		}

		[[nodiscard]] Point3D operator+(const Point3D& p) const noexcept
		{
			return Point3D(coords_.x() + p.coords_.x(), coords_.y() + p.coords_.y(), coords_.z() + p.coords_.z());
		}

		[[nodiscard]] Point3D operator-(const Point3D& p) const noexcept
		{
			return Point3D(coords_.x() - p.coords_.x(), coords_.y() - p.coords_.y(), coords_.z() - p.coords_.z());
		}

		[[nodiscard]] Point3D operator*(const Point3D& p) const noexcept
		{
			return Point3D(coords_.x() * p.coords_.x(), coords_.y() * p.coords_.y(), coords_.z() * p.coords_.z());
		}

		[[nodiscard]] Point3D operator*(double val) const noexcept
		{
			return Point3D(coords_.x() * val, coords_.y() * val, coords_.z() * val);
		}

		[[nodiscard]] double X() const noexcept { return coords_.x(); }
		[[nodiscard]] double Y() const noexcept { return coords_.y(); }
		[[nodiscard]] double Z() const noexcept { return coords_.z(); }

	private:
		Eigen::Vector3d coords_{0.0, 0.0, 0.0};
	};

	// Export function declaration
	export std::ostream& operator<<(std::ostream& os, const Point3D& p);

	// Export function implementation
	inline std::ostream& operator<<(std::ostream& os, const Point3D& p)
	{
		return os << std::format("({}, {}, {})", p.X(), p.Y(), p.Z());
	}
}
