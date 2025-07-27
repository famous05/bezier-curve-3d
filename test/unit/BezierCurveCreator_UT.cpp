#include "gtest/gtest.h"
#include "bezier-curve-3d/BezierCurveCreator.h"
#include "bezier-curve-3d/Point3D.h" 
#include "bezier-curve-3d/WPoint3D.h"
#include "bezier-curve-3d/Utils.h"     

#include <vector>
#include <memory>
#include <cmath>

using namespace bezier_curve_3d;

// Helper function to compare two Point3D objects with a tolerance
void ExpectPointsNear(const Point3D& expected, const Point3D& actual, double tolerance) {
    ASSERT_NEAR(expected.X, actual.X, tolerance) << "X coordinate mismatch";
    ASSERT_NEAR(expected.Y, actual.Y, tolerance) << "Y coordinate mismatch";
    ASSERT_NEAR(expected.Z, actual.Z, tolerance) << "Z coordinate mismatch";
}

// Test Fixture (optional, but good practice if tests share setup)
struct BezierCurveCreatorTest : public ::testing::Test {
    const double EPSILON = 1e-9; // Tolerance for floating point comparisons
};

// =========================================================================
// Tests for GetBezierCurve(const std::vector<Point3D>& ctrlPoints, int nPoints)
// =========================================================================

TEST_F(BezierCurveCreatorTest, GetBezierCurve_Point3D_LineSegment) {
    std::vector<Point3D> ctrlPoints = {
        Point3D(0, 0, 0),
        Point3D(10, 0, 0)
    };
    int nPoints = 3; // t = 0, 0.5, 1

    auto curve = BezierCurveCreator::GetBezierCurve(ctrlPoints, nPoints);

    ASSERT_NE(curve, nullptr);
    ASSERT_EQ(curve->size(), nPoints);

    // Expected points for a line segment
    // t=0: P0 = (0,0,0)
    ExpectPointsNear(Point3D(0, 0, 0), (*curve)[0], EPSILON);
    // t=0.5: 0.5*P0 + 0.5*P1 = 0.5*(0,0,0) + 0.5*(10,0,0) = (5,0,0)
    ExpectPointsNear(Point3D(5, 0, 0), (*curve)[1], EPSILON);
    // t=1: P1 = (10,0,0)
    ExpectPointsNear(Point3D(10, 0, 0), (*curve)[2], EPSILON);
}

TEST_F(BezierCurveCreatorTest, GetBezierCurve_Point3D_SimpleQuadratic) {
    std::vector<Point3D> ctrlPoints = {
        Point3D(0, 0, 0),   // P0
        Point3D(0, 10, 0),  // P1
        Point3D(10, 10, 0)  // P2
    };
    int nPoints = 5; // t = 0, 0.25, 0.5, 0.75, 1

    auto curve = BezierCurveCreator::GetBezierCurve(ctrlPoints, nPoints);

    ASSERT_NE(curve, nullptr);
    ASSERT_EQ(curve->size(), nPoints);

    // Expected points for a quadratic Bezier curve
    // t=0: P0 = (0,0,0)
    ExpectPointsNear(Point3D(0, 0, 0), (*curve)[0], EPSILON);

    // t=0.25: B_0,2(0.25)*P0 + B_1,2(0.25)*P1 + B_2,2(0.25)*P2
    //        = (0.75^2)*P0 + (2*0.25*0.75)*P1 + (0.25^2)*P2
    //        = 0.5625*(0,0,0) + 0.375*(0,10,0) + 0.0625*(10,10,0)
    //        = (0, 3.75, 0) + (0.625, 0.625, 0) = (0.625, 4.375, 0)
    ExpectPointsNear(Point3D(0.625, 4.375, 0), (*curve)[1], EPSILON);

    // t=0.5: (0.5^2)*P0 + (2*0.5*0.5)*P1 + (0.5^2)*P2
    //        = 0.25*P0 + 0.5*P1 + 0.25*P2
    //        = 0.25*(0,0,0) + 0.5*(0,10,0) + 0.25*(10,10,0)
    //        = (0,5,0) + (2.5,2.5,0) = (2.5, 7.5, 0)
    ExpectPointsNear(Point3D(2.5, 7.5, 0), (*curve)[2], EPSILON);

    // t=0.75: B_0,2(0.75)*P0 + B_1,2(0.75)*P1 + B_2,2(0.75)*P2
    //        = (0.25^2)*P0 + (2*0.75*0.25)*P1 + (0.75^2)*P2
    //        = 0.0625*(0,0,0) + 0.375*(0,10,0) + 0.5625*(10,10,0)
    //        = (0, 3.75, 0) + (5.625, 5.625, 0) = (5.625, 9.375, 0)
    ExpectPointsNear(Point3D(5.625, 9.375, 0), (*curve)[3], EPSILON);

    // t=1: P2 = (10,10,0)
    ExpectPointsNear(Point3D(10, 10, 0), (*curve)[4], EPSILON);
}

TEST_F(BezierCurveCreatorTest, GetBezierCurve_Point3D_EmptyControlPointsThrows) {
    std::vector<Point3D> ctrlPoints;
    int nPoints = 5;
    ASSERT_THROW(BezierCurveCreator::GetBezierCurve(ctrlPoints, nPoints), std::invalid_argument);
}

TEST_F(BezierCurveCreatorTest, GetBezierCurve_Point3D_SingleControlPointThrows) {
    // A Bezier curve needs at least 2 control points
    std::vector<Point3D> ctrlPoints = {Point3D(0,0,0)};
    int nPoints = 5;
    ASSERT_THROW(BezierCurveCreator::GetBezierCurve(ctrlPoints, nPoints), std::invalid_argument);
}


TEST_F(BezierCurveCreatorTest, GetBezierCurve_Point3D_NPointsLessThanOrEqualToOneThrows) {
    std::vector<Point3D> ctrlPoints = {Point3D(0,0,0), Point3D(1,1,1)};
    ASSERT_THROW(BezierCurveCreator::GetBezierCurve(ctrlPoints, 0), std::invalid_argument);
    ASSERT_THROW(BezierCurveCreator::GetBezierCurve(ctrlPoints, 1), std::invalid_argument);
}


// =========================================================================
// Tests for GetBezierCurve(const std::vector<WPoint3D>& ctrlPoints, int nPoints)
// =========================================================================

TEST_F(BezierCurveCreatorTest, GetBezierCurve_WPoint3D_LineSegmentWithWeights) {
    std::vector<WPoint3D> ctrlPoints = {
        WPoint3D(0, 0, 0, 1.0),
        WPoint3D(10, 0, 0, 1.0)
    };
    int nPoints = 3; // t = 0, 0.5, 1

    auto curve = BezierCurveCreator::GetBezierCurve(ctrlPoints, nPoints);

    ASSERT_NE(curve, nullptr);
    ASSERT_EQ(curve->size(), nPoints);

    // For constant weights, result should be same as non-weighted
    ExpectPointsNear(Point3D(0, 0, 0), (*curve)[0], EPSILON);
    ExpectPointsNear(Point3D(5, 0, 0), (*curve)[1], EPSILON);
    ExpectPointsNear(Point3D(10, 0, 0), (*curve)[2], EPSILON);
}

TEST_F(BezierCurveCreatorTest, GetBezierCurve_WPoint3D_WeightedQuadratic) {
    // Example: A rational Bezier curve that's a perfect circle arc
    // For a quarter circle arc in XY plane with center (0,0,0), radius 1
    // P0=(1,0,0), P1=(1,1,0), P2=(0,1,0)
    // Weights: W0=1, W1=sqrt(2)/2, W2=1
    double sqrt2_half = std::sqrt(2.0) / 2.0;

    std::vector<WPoint3D> ctrlPoints = {
        WPoint3D(1, 0, 0, 1.0),            // P0
        WPoint3D(1, 1, 0, sqrt2_half),     // P1 (mid-point, pulls curve)
        WPoint3D(0, 1, 0, 1.0)             // P2
    };
    int nPoints = 5; // To get intermediate points including 45-degree mark

    auto curve = BezierCurveCreator::GetBezierCurve(ctrlPoints, nPoints);

    ASSERT_NE(curve, nullptr);
    ASSERT_EQ(curve->size(), nPoints);

    // Expected points for a quarter circle arc (unit circle in XY plane)
    // t=0: (1,0,0)
    ExpectPointsNear(Point3D(1, 0, 0), (*curve)[0], EPSILON);

    // t=0.25 (should be on the circle)
    // For rational quadratic Bezier: B(t) = (B_0,2(t)*W0*P0 + B_1,2(t)*W1*P1 + B_2,2(t)*W2*P2) / (B_0,2(t)*W0 + B_1,2(t)*W1 + B_2,2(t)*W2)
    // At t=0.5, a circular arc typically passes through (sqrt(2)/2, sqrt(2)/2, 0)
    ExpectPointsNear(Point3D(sqrt2_half, sqrt2_half, 0), (*curve)[(nPoints - 1) / 2], EPSILON); // Check midpoint (t=0.5)

    // t=1: (0,1,0)
    ExpectPointsNear(Point3D(0, 1, 0), (*curve)[nPoints - 1], EPSILON);

    // Verify all points are on the unit circle (radius 1) in XY plane
    // Distance from origin should be 1
    Point3D origin(0,0,0);
    for (const auto& p : *curve) {
        ASSERT_NEAR(Utils::GetDistanceBetweenPoints(origin, p), 1.0, EPSILON);
    }
}

TEST_F(BezierCurveCreatorTest, GetBezierCurve_WPoint3D_EmptyControlPointsThrows) {
    std::vector<WPoint3D> ctrlPoints;
    int nPoints = 5;
    ASSERT_THROW(BezierCurveCreator::GetBezierCurve(ctrlPoints, nPoints), std::invalid_argument);
}

TEST_F(BezierCurveCreatorTest, GetBezierCurve_WPoint3D_SingleControlPointThrows) {
    // A Bezier curve needs at least 2 control points
    std::vector<WPoint3D> ctrlPoints = {WPoint3D(0,0,0,1.0)};
    int nPoints = 5;
    ASSERT_THROW(BezierCurveCreator::GetBezierCurve(ctrlPoints, nPoints), std::invalid_argument);
}

TEST_F(BezierCurveCreatorTest, GetBezierCurve_WPoint3D_NPointsLessThanOrEqualToOneThrows) {
    std::vector<WPoint3D> ctrlPoints = {WPoint3D(0,0,0,1.0), WPoint3D(1,1,1,1.0)};
    ASSERT_THROW(BezierCurveCreator::GetBezierCurve(ctrlPoints, 0), std::invalid_argument);
    ASSERT_THROW(BezierCurveCreator::GetBezierCurve(ctrlPoints, 1), std::invalid_argument);
}
