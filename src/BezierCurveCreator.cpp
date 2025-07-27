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

#include "bezier-curve-3d/BezierCurveCreator.h"
#include "bezier-curve-3d/Utils.h"

namespace bezier_curve_3d
{
    std::shared_ptr<std::vector<Point3D>> BezierCurveCreator::GetBezierCurve(const std::vector<Point3D>& ctrlPoints, int nPoints)
    {
        // Assertions for input validation
        if (ctrlPoints.empty()) {
            throw std::invalid_argument(std::string(__FILE__) + ":" + std::to_string(__LINE__) + " 'ctrlPoints' cannot be empty.");
        }
        if (nPoints <= 1) { // At least 2 points needed to define a line/curve
            throw std::invalid_argument(std::string(__FILE__) + ":" + std::to_string(__LINE__) + " 'nPoints' must be greater than 1.");
        }

        std::vector<WPoint3D> wCtrlPoints;
        wCtrlPoints.reserve(ctrlPoints.size());

        // Convert Point3D to WPoint3D with default weight 1.0
        std::for_each(ctrlPoints.begin(), ctrlPoints.end(), [&wCtrlPoints](const Point3D& p) {
            wCtrlPoints.emplace_back(WPoint3D(p.X, p.Y, p.Z, 1.0));
        });

        return BezierCurveCreator::GetBezierCurve(wCtrlPoints, nPoints);
    }

    std::shared_ptr<std::vector<Point3D>> BezierCurveCreator::GetBezierCurve(const std::vector<WPoint3D>& ctrlPoints, int nPoints)
    {
        if (ctrlPoints.empty()) {
            throw std::invalid_argument(std::string(__FILE__) + ":" + std::to_string(__LINE__) + " 'ctrlPoints' cannot be empty.");
        }
        if (nPoints <= 1) {
            throw std::invalid_argument(std::string(__FILE__) + ":" + std::to_string(__LINE__) + " 'nPoints' must be greater than 1.");
        }

        if (ctrlPoints.size() < 2) {
             throw std::invalid_argument(std::string(__FILE__) + ":" + std::to_string(__LINE__) + " 'ctrlPoints' must have at least 2 points for a Bezier curve.");
        }


        auto curve = std::make_shared<std::vector<Point3D>>();
        curve->reserve(nPoints);

        int n = static_cast<int>(ctrlPoints.size()) - 1;

        for (int j = 0; j < nPoints; ++j) {
            double t = static_cast<double>(j) / static_cast<double>(nPoints - 1);
            Point3D sPoint {0.0, 0.0, 0.0}; // Sum of weighted control points
            double denSum = 0.0;            // Sum of weights * Bernstein polynomial

            for (int i = 0; i <= n; ++i) { // Iterate through control points and their index i
                const WPoint3D& p = ctrlPoints[i]; // Access point by index for Bernstein index

                double weightTPoly = p.W * Utils::GetBernsteinPolynomial(i, n, t);

                // Multiply Point by scalar (p * weightTPoly)
                sPoint.X += p.X * weightTPoly;
                sPoint.Y += p.Y * weightTPoly;
                sPoint.Z += p.Z * weightTPoly;

                denSum += weightTPoly;
            }

            // Normalize the point (homogeneous division)
            if (denSum != 0.0) { // Avoid division by zero, though denSum should ideally not be zero
                sPoint.X /= denSum;
                sPoint.Y /= denSum;
                sPoint.Z /= denSum;
            } else {
                // Handle cases where denSum is zero (e.g., all weights are zero, or t=0/1 cases where some terms are zero)
                // For valid Bezier curves with non-zero weights, denSum should generally not be zero for 0 <= t <= 1
                // This might indicate an issue with input weights or a specific edge case for t.
                // For simplicity in this test setup, we'll assume valid inputs avoid this.
                // A more robust implementation might return an error or handle this differently.
            }
            curve->push_back(sPoint);
        }
        return curve;
    }
}
