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
        std::vector<WPoint3D> wCtrlPoints;
        wCtrlPoints.reserve(ctrlPoints.size());

        std::for_each(ctrlPoints.begin(), ctrlPoints.end(), [&wCtrlPoints](const Point3D& p) {wCtrlPoints.emplace_back(WPoint3D(p.X, p.Y, p.Z, 1.0)); });

        return BezierCurveCreator::GetBezierCurve(wCtrlPoints, nPoints);
    }
    std::shared_ptr<std::vector<Point3D>> BezierCurveCreator::GetBezierCurve(const std::vector<WPoint3D>& ctrlPoints, int nPoints)
    {
        double t = 0;
        int n = ctrlPoints.size() - 1;  // curve degree
        int i = 0;
        double denSum = 0;
        double weightTPoly = 0;
        Point3D point {0, 0, 0};
        Point3D sPoint {0, 0, 0};

        auto curve = std::make_shared<std::vector<Point3D>>();

        for (int j = 0; j < nPoints; j++){
            // Calculate t parameter: (0 <= t <= 1)
            t = static_cast<double>(j)/static_cast<double>(nPoints - 1);
            i = 0;
            for (auto& p : ctrlPoints){
                weightTPoly = p.W * Utils::GetBernsteinPolynomial(i,n,t);
                point = p * weightTPoly;
                sPoint = sPoint + point;
                denSum = denSum + weightTPoly;
                i += 1;
            }
            sPoint = sPoint * (1.0 / denSum);
            curve->push_back(sPoint);
            denSum = 0;
            sPoint = Point3D {0, 0, 0};
        }
        return curve;
    }
}
