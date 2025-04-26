export module Utils;

import Point3D;

import <Eigen/Dense>;

namespace BezierLite
{
	export class Utils
	{
		[[nodiscard]] static double GetDistanceBetweenPoints(const Point3D& p1, const Point3D& p2) noexcept
		{
			Eigen::Vector3d v1(p1.X(), p1.Y(), p1.Z());
			Eigen::Vector3d v2(p2.X(), p2.Y(), p2.Z());
			return (v1 - v2).norm();
		}
	};
}
