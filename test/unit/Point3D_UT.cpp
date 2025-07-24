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
#include <sstream>
#include "bezier-curve-3d/Point3D.h"

using bezier_curve_3d::Point3D;

TEST(Point3DTest, ConstructorInitValues) {
    Point3D p(1.0, 2.0, 3.0);
    EXPECT_DOUBLE_EQ(p.X, 1.0);
    EXPECT_DOUBLE_EQ(p.Y, 2.0);
    EXPECT_DOUBLE_EQ(p.Z, 3.0);
}

TEST(Point3DTest, MultiplyByScalar) {
    Point3D p(1.0, -2.0, 3.5);
    p *= 2.0;
    EXPECT_DOUBLE_EQ(p.X, 2.0);
    EXPECT_DOUBLE_EQ(p.Y, -4.0);
    EXPECT_DOUBLE_EQ(p.Z, 7.0);
}

TEST(Point3DTest, DivideByScalar) {
    Point3D p(4.0, -8.0, 16.0);
    p /= 2.0;
    EXPECT_DOUBLE_EQ(p.X, 2.0);
    EXPECT_DOUBLE_EQ(p.Y, -4.0);
    EXPECT_DOUBLE_EQ(p.Z, 8.0);
}

TEST(Point3DTest, DivideByZeroSafe) {
    Point3D p(4.0, -8.0, 16.0);
    p /= 0.0;  // Should be a no-op
    EXPECT_DOUBLE_EQ(p.X, 4.0);
    EXPECT_DOUBLE_EQ(p.Y, -8.0);
    EXPECT_DOUBLE_EQ(p.Z, 16.0);
}

TEST(Point3DTest, AddAssign) {
    Point3D a(1.0, 2.0, 3.0);
    Point3D b(4.0, -2.0, 1.0);
    a += b;
    EXPECT_DOUBLE_EQ(a.X, 5.0);
    EXPECT_DOUBLE_EQ(a.Y, 0.0);
    EXPECT_DOUBLE_EQ(a.Z, 4.0);
}

TEST(Point3DTest, SubtractAssign) {
    Point3D a(5.0, 4.0, 3.0);
    Point3D b(2.0, 1.0, 0.5);
    a -= b;
    EXPECT_DOUBLE_EQ(a.X, 3.0);
    EXPECT_DOUBLE_EQ(a.Y, 3.0);
    EXPECT_DOUBLE_EQ(a.Z, 2.5);
}

TEST(Point3DTest, AddOperator) {
    Point3D a(1.0, 2.0, 3.0);
    Point3D b(4.0, 5.0, 6.0);
    Point3D result = a + b;
    EXPECT_DOUBLE_EQ(result.X, 5.0);
    EXPECT_DOUBLE_EQ(result.Y, 7.0);
    EXPECT_DOUBLE_EQ(result.Z, 9.0);
}

TEST(Point3DTest, SubtractOperator) {
    Point3D a(10.0, 5.0, 3.0);
    Point3D b(4.0, 1.0, 2.0);
    Point3D result = a - b;
    EXPECT_DOUBLE_EQ(result.X, 6.0);
    EXPECT_DOUBLE_EQ(result.Y, 4.0);
    EXPECT_DOUBLE_EQ(result.Z, 1.0);
}

TEST(Point3DTest, ComponentWiseMultiply) {
    Point3D a(1.0, 2.0, 3.0);
    Point3D b(2.0, -1.0, 0.5);
    Point3D result = a * b;
    EXPECT_DOUBLE_EQ(result.X, 2.0);
    EXPECT_DOUBLE_EQ(result.Y, -2.0);
    EXPECT_DOUBLE_EQ(result.Z, 1.5);
}

TEST(Point3DTest, ScalarMultiplyOperator) {
    Point3D p(1.0, -2.0, 0.5);
    Point3D result = p * 2.0;
    EXPECT_DOUBLE_EQ(result.X, 2.0);
    EXPECT_DOUBLE_EQ(result.Y, -4.0);
    EXPECT_DOUBLE_EQ(result.Z, 1.0);
}

TEST(Point3DTest, OStreamOperator) {
    Point3D p(1.0, 2.5, -3.0);
    std::ostringstream oss;
    oss << p;
    EXPECT_EQ(oss.str(), "(1, 2.5, -3)");
}
