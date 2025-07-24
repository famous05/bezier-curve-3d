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
#include "bezier-curve-3d/WPoint3D.h"

using bezier_curve_3d::WPoint3D;

struct WPoint3DTest : public ::testing::Test {
    // You can set up common objects here
    WPoint3D default_wp;
    WPoint3D custom_wp{1.0, 2.0, 3.0, 0.5};
    WPoint3D another_wp{4.0, 5.0, 6.0, 1.5};

    void SetUp() override {

    }

    void TearDown() override {

    }
};

// Test Default Constructor
TEST_F(WPoint3DTest, DefaultConstructorInitializesCorrectly) {
    ASSERT_DOUBLE_EQ(default_wp.X, 0.0);
    ASSERT_DOUBLE_EQ(default_wp.Y, 0.0);
    ASSERT_DOUBLE_EQ(default_wp.Z, 0.0);
    ASSERT_DOUBLE_EQ(default_wp.W, 1.0);
}

// Test Parameterized Constructor
TEST_F(WPoint3DTest, ParameterizedConstructorInitializesCorrectly) {
    ASSERT_DOUBLE_EQ(custom_wp.X, 1.0);
    ASSERT_DOUBLE_EQ(custom_wp.Y, 2.0);
    ASSERT_DOUBLE_EQ(custom_wp.Z, 3.0);
    ASSERT_DOUBLE_EQ(custom_wp.W, 0.5);
}

// Test Copy Constructor
TEST_F(WPoint3DTest, CopyConstructorCreatesIndependentCopy) {
    WPoint3D copied_wp = custom_wp; // Calls copy constructor

    ASSERT_DOUBLE_EQ(copied_wp.X, custom_wp.X);
    ASSERT_DOUBLE_EQ(copied_wp.Y, custom_wp.Y);
    ASSERT_DOUBLE_EQ(copied_wp.Z, custom_wp.Z);
    ASSERT_DOUBLE_EQ(copied_wp.W, custom_wp.W);

    // Verify independence by modifying the original
    custom_wp.X = 10.0;
    ASSERT_NE(copied_wp.X, custom_wp.X);
}

// Test Copy Assignment Operator
TEST_F(WPoint3DTest, CopyAssignmentOperatorCopiesValues) {
    WPoint3D assigned_wp;
    assigned_wp = custom_wp;

    ASSERT_DOUBLE_EQ(assigned_wp.X, custom_wp.X);
    ASSERT_DOUBLE_EQ(assigned_wp.Y, custom_wp.Y);
    ASSERT_DOUBLE_EQ(assigned_wp.Z, custom_wp.Z);
    ASSERT_DOUBLE_EQ(assigned_wp.W, custom_wp.W);
}

// Test Self-Assignment
TEST_F(WPoint3DTest, CopyAssignmentOperatorHandlesSelfAssignment) {
    WPoint3D original_wp = custom_wp;

    custom_wp = custom_wp;

    // Values should remain unchanged
    ASSERT_DOUBLE_EQ(custom_wp.X, original_wp.X);
    ASSERT_DOUBLE_EQ(custom_wp.Y, original_wp.Y);
    ASSERT_DOUBLE_EQ(custom_wp.Z, original_wp.Z);
    ASSERT_DOUBLE_EQ(custom_wp.W, original_wp.W);
}

// Test chained assignment (optional but good)
TEST_F(WPoint3DTest, CopyAssignmentOperatorAllowsChainedAssignment) {
    WPoint3D wp1;
    WPoint3D wp2;

    wp1 = wp2 = custom_wp; // Chained assignment

    ASSERT_DOUBLE_EQ(wp1.X, custom_wp.X);
    ASSERT_DOUBLE_EQ(wp1.Y, custom_wp.Y);
    ASSERT_DOUBLE_EQ(wp1.Z, custom_wp.Z);
    ASSERT_DOUBLE_EQ(wp1.W, custom_wp.W);

    ASSERT_DOUBLE_EQ(wp2.X, custom_wp.X);
    ASSERT_DOUBLE_EQ(wp2.Y, custom_wp.Y);
    ASSERT_DOUBLE_EQ(wp2.Z, custom_wp.Z);
    ASSERT_DOUBLE_EQ(wp2.W, custom_wp.W);
}
