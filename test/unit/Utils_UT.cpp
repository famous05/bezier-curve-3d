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


#include "gtest/gtest.h"
#include "../../include/bezier-curve-3d/Utils.h"
#include "../../include/bezier-curve-3d/Point3D.h"

// using namespace bezier_curve_3d;
using bezier_curve_3d::Utils;
using bezier_curve_3d::Point3D;

struct UtilsTest : public ::testing::Test {
    Point3D p_origin{0.0, 0.0, 0.0};
    Point3D p_one{1.0, 1.0, 1.0};

    void SetUp() override {
    }

    void TearDown() override {
    }
};


double tolerance = 1e-9;

// =========================================================================
// Test cases for GetDistanceBetweenPoints
// =========================================================================
TEST_F(UtilsTest, GetDistanceBetweenPoints_SamePoint) {
    Point3D p1(1.0, 2.0, 3.0);
    Point3D p2(1.0, 2.0, 3.0);
    ASSERT_NEAR(Utils::GetDistanceBetweenPoints(p1, p2), 0.0, tolerance);
}


TEST_F(UtilsTest, GetDistanceBetweenPoints_AxisAligned) {
    Point3D p1(0.0, 0.0, 0.0);
    Point3D p2(5.0, 0.0, 0.0);
    ASSERT_NEAR(Utils::GetDistanceBetweenPoints(p1, p2), 5.0, tolerance);

    Point3D p3(0.0, 10.0, 0.0);
    Point3D p4(0.0, 0.0, 0.0);
    ASSERT_NEAR(Utils::GetDistanceBetweenPoints(p3, p4), 10.0, tolerance);
}

TEST_F(UtilsTest, GetDistanceBetweenPoints_Diagonal) {
    Point3D p1(0.0, 0.0, 0.0);
    Point3D p2(3.0, 4.0, 0.0);
    ASSERT_NEAR(Utils::GetDistanceBetweenPoints(p1, p2), 5.0, tolerance);

    Point3D p3(1.0, 1.0, 1.0);
    Point3D p4(2.0, 2.0, 2.0);
    ASSERT_NEAR(Utils::GetDistanceBetweenPoints(p3, p4), std::sqrt(3.0), tolerance);
}

// =========================================================================
// Test cases for GetFactorial
// =========================================================================
TEST_F(UtilsTest, GetFactorial_Zero) {
    ASSERT_EQ(Utils::GetFactorial(0), 1);
}

TEST_F(UtilsTest, GetFactorial_One) {
    ASSERT_EQ(Utils::GetFactorial(1), 1);
}

TEST_F(UtilsTest, GetFactorial_PositiveNumbers) {
    ASSERT_EQ(Utils::GetFactorial(2), 2);    // 2 * 1 = 2
    ASSERT_EQ(Utils::GetFactorial(3), 6);    // 3 * 2 * 1 = 6
    ASSERT_EQ(Utils::GetFactorial(5), 120);  // 5 * 4 * 3 * 2 * 1 = 120
    ASSERT_EQ(Utils::GetFactorial(7), 5040); // 7!
}

TEST_F(UtilsTest, GetFactorial_NegativeNumber) {
    ASSERT_THROW(Utils::GetFactorial(-5), std::out_of_range);
}

// =========================================================================
// Test cases for GetBinomialCoefficient
// =========================================================================
TEST_F(UtilsTest, GetBinomialCoefficient_EdgeCases) {
    ASSERT_NEAR(Utils::GetBinomialCoefficient(5, 0), 1.0, tolerance);
    ASSERT_NEAR(Utils::GetBinomialCoefficient(5, 5), 1.0, tolerance);
    ASSERT_NEAR(Utils::GetBinomialCoefficient(0, 0), 1.0, tolerance);
}

TEST_F(UtilsTest, GetBinomialCoefficient_CommonValues) {
    ASSERT_NEAR(Utils::GetBinomialCoefficient(4, 2), 6.0, tolerance);
    ASSERT_NEAR(Utils::GetBinomialCoefficient(5, 2), 10.0, tolerance);
    ASSERT_NEAR(Utils::GetBinomialCoefficient(6, 3), 20.0, tolerance);
}

TEST_F(UtilsTest, GetBinomialCoefficient_InvalidInputs) {
    ASSERT_THROW(Utils::GetBinomialCoefficient(5, -1), std::out_of_range);
    ASSERT_THROW(Utils::GetBinomialCoefficient(5, 6), std::logic_error);
    ASSERT_THROW(Utils::GetBinomialCoefficient(-5, 2), std::out_of_range);
}

// =========================================================================
// Test cases for GetBernsteinPolynomial
// =========================================================================
TEST_F(UtilsTest, GetBernsteinPolynomial_EdgeCases_t0_t1) {
    // B_0,n(0) = 1 (all others 0)
    ASSERT_NEAR(Utils::GetBernsteinPolynomial(0, 3, 0.0), 1.0, tolerance);
    ASSERT_NEAR(Utils::GetBernsteinPolynomial(1, 3, 0.0), 0.0, tolerance);
    ASSERT_NEAR(Utils::GetBernsteinPolynomial(2, 3, 0.0), 0.0, tolerance);
    ASSERT_NEAR(Utils::GetBernsteinPolynomial(3, 3, 0.0), 0.0, tolerance);

    // B_n,n(1) = 1 (all others 0)
    ASSERT_NEAR(Utils::GetBernsteinPolynomial(0, 3, 1.0), 0.0, tolerance);
    ASSERT_NEAR(Utils::GetBernsteinPolynomial(1, 3, 1.0), 0.0, tolerance);
    ASSERT_NEAR(Utils::GetBernsteinPolynomial(2, 3, 1.0), 0.0, tolerance);
    ASSERT_NEAR(Utils::GetBernsteinPolynomial(3, 3, 1.0), 1.0, tolerance);
}

TEST_F(UtilsTest, GetBernsteinPolynomial_SimpleCases) {
    // n=1, i=0: B_0,1(t) = C(1,0) * t^0 * (1-t)^1 = 1 * 1 * (1-t) = 1-t
    ASSERT_NEAR(Utils::GetBernsteinPolynomial(0, 1, 0.5), 0.5, tolerance);
    ASSERT_NEAR(Utils::GetBernsteinPolynomial(0, 1, 0.2), 0.8, tolerance);

    // n=1, i=1: B_1,1(t) = C(1,1) * t^1 * (1-t)^0 = 1 * t * 1 = t
    ASSERT_NEAR(Utils::GetBernsteinPolynomial(1, 1, 0.5), 0.5, tolerance);
    ASSERT_NEAR(Utils::GetBernsteinPolynomial(1, 1, 0.2), 0.2, tolerance);

    // n=2, i=1: B_1,2(t) = C(2,1) * t^1 * (1-t)^1 = 2 * t * (1-t)
    ASSERT_NEAR(Utils::GetBernsteinPolynomial(1, 2, 0.5), 2 * 0.5 * 0.5, tolerance); // 0.5
    ASSERT_NEAR(Utils::GetBernsteinPolynomial(1, 2, 0.2), 2 * 0.2 * 0.8, tolerance); // 0.32
}

TEST_F(UtilsTest, GetBernsteinPolynomial_SummationProperty) {
    // For any n and t, sum of B_i,n(t) for i=0 to n should be 1.0
    int n = 4;
    double t = 0.3;
    double sum = 0.0;
    for (int i = 0; i <= n; ++i) {
        sum += Utils::GetBernsteinPolynomial(i, n, t);
    }
    ASSERT_NEAR(sum, 1.0, tolerance);
}