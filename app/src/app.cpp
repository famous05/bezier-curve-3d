#include "Point3D.h"
#include "Utils.h"
#include "BezierCurveCreator.h"

#include <vector>
#include <iostream>

int main()
{
    using namespace BezierLite;

    // Create a vector of Point3D
    std::vector<Point3D> points;
    points.emplace_back(1.0, 2.0, 3.0);
    points.emplace_back(4.0, 5.0, 6.0);
    points.emplace_back(7.0, 8.0, 9.0);
    points.emplace_back(-1.0, -2.0, -3.0);

    // Print points
    std::cout << "List of 3D Points:\n";
    for (const auto& point : points)
    {
        std::cout << point << '\n';
    }

    Point3D start { 0,0,0};
    Point3D end {3, 4, 0}; 

    std::cout << "Distance Btw Points : " << Utils::GetDistanceBetweenPoints(start, end) << std::endl;

    BezierCurveCreator<Point3D> Creator(points, 20);

    std::vector<WPoint3D> wpoints;
    wpoints.emplace_back(1.0, 2.0, 3.0, 0.5);
    wpoints.emplace_back(4.0, 5.0, 6.0, 1.25);
    wpoints.emplace_back(7.0, 8.0, 9.0, 1);

    BezierCurveCreator<WPoint3D> WCreator(wpoints, 20);
    auto curve = WCreator.GetBezierCurvePoints();
    for (const auto& p : curve){
        std::cout << p << '\n';
    }

    return 0;
}
