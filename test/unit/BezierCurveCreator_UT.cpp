/* Copyright © 2025 Osarobo Famous Okhuahesogie (famous.osarobo@gmail.com)
*
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <gtest/gtest.h>
#include <vector>
#include <cmath>
#include <iomanip>

#include "bezier-curve-3d/Point3D.h"
#include "bezier-curve-3d/WPoint3D.h"
#include "bezier-curve-3d/Utils.h"
#include "bezier-curve-3d/BezierCurveCreator.h"

constexpr double EPSILON = 1e-9;

using namespace bezier_curve_3d;

bool VectorsEqual(const std::vector<Point3D>& v1,
                                  const std::vector<Point3D>& v2,
                                  double epsilon = EPSILON) {
    if (v1.size() != v2.size()) {
        return false;
    }
    for (size_t i = 0; i < v1.size(); ++i) {
        if (std::abs(v1[i].X - v2[i].X) > epsilon ||
            std::abs(v1[i].Y - v2[i].Y) > epsilon ||
            std::abs(v1[i].Z - v2[i].Z) > epsilon) {
            return false;
        }
    }
    return true;
}

// Test fixture
class BezierCurveCreatorTest : public ::testing::Test {
protected:
    void SetUp() override {
        
    }
};

// --- Tests for BezierCurveCreator with Point3D (Standard Bezier) ---

// Test case for a simple linear Bezier curve (2 control points)
TEST_F(BezierCurveCreatorTest, LinearCurvePoint3D) {
    std::vector<Point3D> controlPoints = {
        Point3D(0, 0, 0),
        Point3D(10, 0, 0)
    };
    int numPoints = 3; // t = 0, 0.5, 1

    BezierCurveCreator<Point3D> creator(controlPoints, numPoints);
    std::vector<Point3D> curve = creator.GetBezierCurvePoints();

    std::vector<Point3D> expectedCurve = {
        Point3D(0, 0, 0),    // t=0
        Point3D(5, 0, 0),     // t=0.5
        Point3D(10, 0, 0)    // t=1
    };

    ASSERT_TRUE(VectorsEqual(curve, expectedCurve));
}

/*

// Test case for a quadratic Bezier curve (3 control points)
TEST_F(BezierCurveCreatorTest, QuadraticCurvePoint3D) {
    std::vector<Point3D> controlPoints = {
        Point3D(0, 0, 0),
        Point3D(5, 10, 0),
        Point3D(10, 0, 0)
    };
    int numPoints = 5; // t = 0, 0.25, 0.5, 0.75, 1

    bezier_curve_3d::BezierCurveCreator<Point3D> creator(controlPoints, numPoints);
    std::vector<Point3D> curve = creator.GetBezierCurvePoints();

    // Expected points calculated manually or with a known Bezier function
    std::vector<Point3D> expectedCurve = {
        Point3D(0, 0, 0),
        Point3D(2.8125, 3.75, 0), // t=0.25: (0.75^2)*P0 + 2*0.75*0.25*P1 + (0.25^2)*P2
        Point3D(5, 5, 0),     // t=0.5: 0.25*P0 + 0.5*P1 + 0.25*P2
        Point3D(7.1875, 3.75, 0), // t=0.75
        Point3D(10, 0, 0)
    };

    ASSERT_TRUE(VectorsEqual(curve, expectedCurve));
}

// Test case for a cubic Bezier curve (4 control points)
TEST_F(BezierCurveCreatorTest, CubicCurvePoint3D) {
    std::vector<Point3D> controlPoints = {
        Point3D(0, 0, 0),
        Point3D(0, 10, 0),
        Point3D(10, 10, 0),
        Point3D(10, 0, 0)
    };
    int numPoints = 5; // t = 0, 0.25, 0.5, 0.75, 1

    bezier_curve_3d::BezierCurveCreator<Point3D> creator(controlPoints, numPoints);
    std::vector<Point3D> curve = creator.GetBezierCurvePoints();

    // Expected points (calculated for a simple S-curve-like shape)
    std::vector<Point3D> expectedCurve = {
        Point3D(0, 0, 0),
        Point3D(0.9375, 6.5625, 0), // t=0.25
        Point3D(5, 7.5, 0),     // t=0.5
        Point3D(9.0625, 3.4375, 0), // t=0.75
        Point3D(10, 0, 0)
    };

    ASSERT_TRUE(VectorsEqual(curve, expectedCurve));
}

// Test case with all control points at the same location
TEST_F(BezierCurveCreatorTest, AllPointsSamePoint3D) {
    std::vector<Point3D> controlPoints = {
        Point3D(5, 5, 5),
        Point3D(5, 5, 5),
        Point3D(5, 5, 5)
    };
    int numPoints = 5;

    bezier_curve_3d::BezierCurveCreator<Point3D> creator(controlPoints, numPoints);
    std::vector<Point3D> curve = creator.GetBezierCurvePoints();

    std::vector<Point3D> expectedCurve(numPoints, Point3D(5, 5, 5));
    ASSERT_TRUE(VectorsEqual(curve, expectedCurve));
}

// Test case with only one control point (should just return that point)
TEST_F(BezierCurveCreatorTest, SingleControlPointPoint3D) {
    std::vector<Point3D> controlPoints = {
        Point3D(1, 2, 3)
    };
    int numPoints = 1; // Only t=0

    bezier_curve_3d::BezierCurveCreator<Point3D> creator(controlPoints, numPoints);
    std::vector<Point3D> curve = creator.GetBezierCurvePoints();

    std::vector<Point3D> expectedCurve = {
        Point3D(1, 2, 3)
    };
    ASSERT_TRUE(VectorsEqual(curve, expectedCurve));

    // Test with more numPoints, should still be the same single point
    numPoints = 5;
    bezier_curve_3d::BezierCurveCreator<Point3D> creator2(controlPoints, numPoints);
    std::vector<Point3D> curve2 = creator2.GetBezierCurvePoints();
    std::vector<Point3D> expectedCurve2(numPoints, Point3D(1, 2, 3));
    ASSERT_TRUE(VectorsEqual(curve2, expectedCurve2));
}

// Test case with zero numPoints (should return empty vector)
TEST_F(BezierCurveCreatorTest, ZeroNumPointsPoint3D) {
    std::vector<Point3D> controlPoints = {
        Point3D(0, 0, 0),
        Point3D(10, 0, 0)
    };
    int numPoints = 0;

    bezier_curve_3d::BezierCurveCreator<Point3D> creator(controlPoints, numPoints);
    std::vector<Point3D> curve = creator.GetBezierCurvePoints();

    ASSERT_TRUE(curve.empty());
}

// --- Tests for BezierCurveCreator with WPoint3D (Rational Bezier) ---

// Test case for a simple linear rational Bezier curve
TEST_F(BezierCurveCreatorTest, LinearRationalCurveWPoint3D) {
    std::vector<bezier_curve_3d::WPoint3D> controlPoints = {
        bezier_curve_3d::WPoint3D(0, 0, 0, 1.0),
        bezier_curve_3d::WPoint3D(10, 0, 0, 1.0)
    };
    int numPoints = 3; // t = 0, 0.5, 1

    bezier_curve_3d::BezierCurveCreator<bezier_curve_3d::WPoint3D> creator(controlPoints, numPoints);
    std::vector<Point3D> curve = creator.GetBezierCurvePoints();

    std::vector<Point3D> expectedCurve = {
        Point3D(0, 0, 0),    // t=0
        Point3D(5, 0, 0),     // t=0.5
        Point3D(10, 0, 0)    // t=1
    };
    ASSERT_TRUE(VectorsEqual(curve, expectedCurve));
}

// Test case for a quadratic rational Bezier curve with varying weights
TEST_F(BezierCurveCreatorTest, QuadraticRationalCurveWPoint3D) {
    std::vector<bezier_curve_3d::WPoint3D> controlPoints = {
        bezier_curve_3d::WPoint3D(0, 0, 0, 1.0),
        bezier_curve_3d::WPoint3D(5, 10, 0, 2.0), // Increased weight on middle point
        bezier_curve_3d::WPoint3D(10, 0, 0, 1.0)
    };
    int numPoints = 5; // t = 0, 0.25, 0.5, 0.75, 1

    bezier_curve_3d::BezierCurveCreator<bezier_curve_3d::WPoint3D> creator(controlPoints, numPoints);
    std::vector<Point3D> curve = creator.GetBezierCurvePoints();

    // Expected points for rational Bezier (calculated manually for t=0.5)
    // B_0,2(0.5) = 0.25, B_1,2(0.5) = 0.5, B_2,2(0.5) = 0.25
    // Denominator for t=0.5: (1*0.25) + (2*0.5) + (1*0.25) = 0.25 + 1.0 + 0.25 = 1.5
    // Numerator for t=0.5: (P0*1*0.25) + (P1*2*0.5) + (P2*1*0.25)
    // = (0,0,0)*0.25 + (5,10,0)*1.0 + (10,0,0)*0.25
    // = (0,0,0) + (5,10,0) + (2.5,0,0) = (7.5,10,0)
    // Point at t=0.5: (7.5,10,0) / 1.5 = (5, 6.666666..., 0)

    std::vector<Point3D> expectedCurve = {
        Point3D(0, 0, 0),
        // Precise calculation for t=0.25 for rational Bezier:
        // B02(0.25)=0.5625, B12(0.25)=0.375, B22(0.25)=0.0625
        // Den: (1*0.5625) + (2*0.375) + (1*0.0625) = 0.5625 + 0.75 + 0.0625 = 1.375
        // Num: P0*0.5625 + P1*0.75 + P2*0.0625
        // = (0,0,0) + (5,10,0)*0.75 + (10,0,0)*0.0625
        // = (3.75, 7.5, 0) + (0.625, 0, 0) = (4.375, 7.5, 0)
        // Point: (4.375/1.375, 7.5/1.375, 0) = (3.1818..., 5.4545..., 0)
        Point3D(3.181818181818182, 5.454545454545454, 0),
        Point3D(5, 6.666666666666667, 0), // t=0.5
        // Precise calculation for t=0.75 for rational Bezier:
        // B02(0.75)=0.0625, B12(0.75)=0.375, B22(0.75)=0.5625
        // Den: (1*0.0625) + (2*0.375) + (1*0.5625) = 0.0625 + 0.75 + 0.5625 = 1.375
        // Num: P0*0.0625 + P1*0.75 + P2*0.5625
        // = (0,0,0) + (5,10,0)*0.75 + (10,0,0)*0.5625
        // = (3.75, 7.5, 0) + (5.625, 0, 0) = (9.375, 7.5, 0)
        // Point: (9.375/1.375, 7.5/1.375, 0) = (6.8181..., 5.4545..., 0)
        Point3D(6.818181818181818, 5.454545454545454, 0),
        Point3D(10, 0, 0)
    };

    ASSERT_TRUE(VectorsEqual(curve, expectedCurve));
}

// Test case with negative weights (can cause unexpected behavior, but should not crash)
TEST_F(BezierCurveCreatorTest, NegativeWeightsWPoint3D) {
    std::vector<bezier_curve_3d::WPoint3D> controlPoints = {
        bezier_curve_3d::WPoint3D(0, 0, 0, 1.0),
        bezier_curve_3d::WPoint3D(5, 10, 0, -1.0), // Negative weight
        bezier_curve_3d::WPoint3D(10, 0, 0, 1.0)
    };
    int numPoints = 3;

    bezier_curve_3d::BezierCurveCreator<bezier_curve_3d::WPoint3D> creator(controlPoints, numPoints);
    std::vector<Point3D> curve = creator.GetBezierCurvePoints();

    // The curve might go "behind" the control points due to negative weights.
    // At t=0.5:
    // Den: (1*0.25) + (-1*0.5) + (1*0.25) = 0.25 - 0.5 + 0.25 = 0
    // This specific case results in division by zero, which the current code handles by
    // pushing the unscaled sPoint. We should test for this.
    // The current implementation will push sPoint = (0,0,0) if denSum is 0.

    // For t=0.5, denSum will be 0.
    // For t=0 and t=1, denSum will be 1.0.
    std::vector<Point3D> expectedCurve = {
        Point3D(0, 0, 0),    // t=0
        Point3D(0, 0, 0),     // t=0.5 (due to denSum being 0, sPoint remains (0,0,0))
        Point3D(10, 0, 0)    // t=1
    };
    ASSERT_TRUE(VectorsEqual(curve, expectedCurve));
}

// Test case for all points being the same (WPoint3D)
TEST_F(BezierCurveCreatorTest, AllPointsSameWPoint3D) {
    std::vector<bezier_curve_3d::WPoint3D> controlPoints = {
        bezier_curve_3d::WPoint3D(5, 5, 5, 1.0),
        bezier_curve_3d::WPoint3D(5, 5, 5, 2.0),
        bezier_curve_3d::WPoint3D(5, 5, 5, 0.5)
    };
    int numPoints = 5;

    bezier_curve_3d::BezierCurveCreator<bezier_curve_3d::WPoint3D> creator(controlPoints, numPoints);
    std::vector<Point3D> curve = creator.GetBezierCurvePoints();

    std::vector<Point3D> expectedCurve(numPoints, Point3D(5, 5, 5));
    ASSERT_TRUE(VectorsEqual(curve, expectedCurve));
}

// Test case with a single WPoint3D control point
TEST_F(BezierCurveCreatorTest, SingleControlPointWPoint3D) {
    std::vector<bezier_curve_3d::WPoint3D> controlPoints = {
        bezier_curve_3d::WPoint3D(1, 2, 3, 5.0)
    };
    int numPoints = 1;

    bezier_curve_3d::BezierCurveCreator<bezier_curve_3d::WPoint3D> creator(controlPoints, numPoints);
    std::vector<Point3D> curve = creator.GetBezierCurvePoints();

    std::vector<Point3D> expectedCurve = {
        Point3D(1, 2, 3)
    };
    ASSERT_TRUE(VectorsEqual(curve, expectedCurve));
}

// Test case with zero numPoints (should return empty vector) for WPoint3D
TEST_F(BezierCurveCreatorTest, ZeroNumPointsWPoint3D) {
    std::vector<bezier_curve_3d::WPoint3D> controlPoints = {
        bezier_curve_3d::WPoint3D(0, 0, 0, 1.0),
        bezier_curve_3d::WPoint3D(10, 0, 0, 1.0)
    };
    int numPoints = 0;

    bezier_curve_3d::BezierCurveCreator<bezier_curve_3d::WPoint3D> creator(controlPoints, numPoints);
    std::vector<Point3D> curve = creator.GetBezierCurvePoints();

    ASSERT_TRUE(curve.empty());
}

*/