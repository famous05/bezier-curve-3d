import BezierLite.Point3D; // Imported module

import <vector>;
import <iostream>;

int main()
{
    using BezierLite::Point3D;

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

    return 0;
}
