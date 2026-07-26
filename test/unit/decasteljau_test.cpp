#include <gtest/gtest.h>

#include "bezier-curve-3d/BezierCurveCreator.h"
#include "bezier-curve-3d/Point3D.h"

using namespace bezier_curve_3d;

static constexpr double EPS = 1e-9;

TEST(DeCasteljauTest, LinearSegment)
{
    std::vector<Point3D> ctrl = { Point3D(0,0,0), Point3D(1,1,1) };
    auto curve = BezierCurveCreator::GetBezierCurve(ctrl, 3);
    ASSERT_EQ(curve->size(), 3u);
    EXPECT_NEAR((*curve)[0].X, 0.0, EPS);
    EXPECT_NEAR((*curve)[1].X, 0.5, EPS);
    EXPECT_NEAR((*curve)[2].X, 1.0, EPS);
    EXPECT_NEAR((*curve)[1].Y, 0.5, EPS);
    EXPECT_NEAR((*curve)[1].Z, 0.5, EPS);
}

TEST(DeCasteljauTest, QuadraticMidpoint)
{
    // Quadratic curve: P0=(0,0,0), P1=(1,2,0), P2=(2,0,0)
    // At t=0.5 the Bernstein weights are [0.25, 0.5, 0.25]
    std::vector<Point3D> ctrl = { Point3D(0,0,0), Point3D(1,2,0), Point3D(2,0,0) };
    auto curve = BezierCurveCreator::GetBezierCurve(ctrl, 3); // t=0,0.5,1
    ASSERT_EQ(curve->size(), 3u);

    double t = 0.5;
    double b0 = (1 - t) * (1 - t);
    double b1 = 2 * t * (1 - t);
    double b2 = t * t;

    Point3D expected(b0 * 0 + b1 * 1 + b2 * 2,
                     b0 * 0 + b1 * 2 + b2 * 0,
                     0.0);

    EXPECT_NEAR((*curve)[1].X, expected.X, EPS);
    EXPECT_NEAR((*curve)[1].Y, expected.Y, EPS);
    EXPECT_NEAR((*curve)[1].Z, expected.Z, EPS);
}
