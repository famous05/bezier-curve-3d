#include <gtest/gtest.h>
#include <sstream>
#include "Point3D.h"

using namespace BezierLite;

// Define the test fixture class
class Point3DTest : public ::testing::Test {
    protected:
        // Optional setup code
        void SetUp() override {
            // Code to run before each test
        }
    
        // Optional teardown code
        void TearDown() override {
            // Code to run after each test
        }
    
        // You can also define member variables here for use in tests
        Point3D p1{1.0, 2.0, 3.0};
        Point3D p2{4.0, 5.0, 6.0};
    };

TEST_F(Point3DTest, DefaultConstructor) {
    Point3D p;
    EXPECT_DOUBLE_EQ(p.X, 0.0);
    EXPECT_DOUBLE_EQ(p.Y, 0.0);
    EXPECT_DOUBLE_EQ(p.Z, 0.0);
}

TEST_F(Point3DTest, ParameterizedConstructor) {
    Point3D p(1.0, 2.0, 3.0);
    EXPECT_DOUBLE_EQ(p.X, 1.0);
    EXPECT_DOUBLE_EQ(p.Y, 2.0);
    EXPECT_DOUBLE_EQ(p.Z, 3.0);
}

// TEST(Point3DTest, ScalarMultiplicationAssignment) {
//     Point3D p(1.0, 2.0, 3.0);
//     p *= 2.0;
//     EXPECT_DOUBLE_EQ(p.X, 2.0);
//     EXPECT_DOUBLE_EQ(p.Y, 4.0);
//     EXPECT_DOUBLE_EQ(p.Z, 6.0);
// }

// TEST(Point3DTest, ScalarDivisionAssignment) {
//     Point3D p(2.0, 4.0, 6.0);
//     p /= 2.0;
//     EXPECT_DOUBLE_EQ(p.X, 1.0);
//     EXPECT_DOUBLE_EQ(p.Y, 2.0);
//     EXPECT_DOUBLE_EQ(p.Z, 3.0);
// }

// TEST(Point3DTest, VectorAdditionAssignment) {
//     Point3D p1(1.0, 2.0, 3.0);
//     Point3D p2(4.0, 5.0, 6.0);
//     p1 += p2;
//     EXPECT_DOUBLE_EQ(p1.X, 5.0);
//     EXPECT_DOUBLE_EQ(p1.Y, 7.0);
//     EXPECT_DOUBLE_EQ(p1.Z, 9.0);
// }

// TEST(Point3DTest, VectorSubtractionAssignment) {
//     Point3D p1(5.0, 7.0, 9.0);
//     Point3D p2(1.0, 2.0, 3.0);
//     p1 -= p2;
//     EXPECT_DOUBLE_EQ(p1.X, 4.0);
//     EXPECT_DOUBLE_EQ(p1.Y, 5.0);
//     EXPECT_DOUBLE_EQ(p1.Z, 6.0);
// }

// TEST(Point3DTest, VectorAddition) {
//     Point3D p1(1.0, 2.0, 3.0);
//     Point3D p2(4.0, 5.0, 6.0);
//     Point3D result = p1 + p2;
//     EXPECT_DOUBLE_EQ(result.X, 5.0);
//     EXPECT_DOUBLE_EQ(result.Y, 7.0);
//     EXPECT_DOUBLE_EQ(result.Z, 9.0);
// }

// TEST(Point3DTest, VectorSubtraction) {
//     Point3D p1(5.0, 7.0, 9.0);
//     Point3D p2(1.0, 2.0, 3.0);
//     Point3D result = p1 - p2;
//     EXPECT_DOUBLE_EQ(result.X, 4.0);
//     EXPECT_DOUBLE_EQ(result.Y, 5.0);
//     EXPECT_DOUBLE_EQ(result.Z, 6.0);
// }

// TEST(Point3DTest, ComponentWiseMultiplication) {
//     Point3D p1(2.0, 3.0, 4.0);
//     Point3D p2(5.0, 6.0, 7.0);
//     Point3D result = p1 * p2;
//     EXPECT_DOUBLE_EQ(result.X, 10.0);
//     EXPECT_DOUBLE_EQ(result.Y, 18.0);
//     EXPECT_DOUBLE_EQ(result.Z, 28.0);
// }

// TEST(Point3DTest, ScalarMultiplication) {
//     Point3D p(1.0, 2.0, 3.0);
//     Point3D result = p * 3.0;
//     EXPECT_DOUBLE_EQ(result.X, 3.0);
//     EXPECT_DOUBLE_EQ(result.Y, 6.0);
//     EXPECT_DOUBLE_EQ(result.Z, 9.0);
// }

// TEST(Point3DTest, StreamOutput) {
//     Point3D p(1.0, 2.0, 3.0);
//     std::ostringstream oss;
//     oss << p;
//     EXPECT_EQ(oss.str(), "(1, 2, 3)");
// }
