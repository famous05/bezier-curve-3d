/* Copyright © 2017 - 2025 Osarobo Famous Okhuahesogie (famous.osarobo@gmail.com)
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
        auto curve = std::make_shared<std::vector<Point3D>>();
        if (ctrlPoints.empty() || nPoints <= 0) return curve;

        int n = static_cast<int>(ctrlPoints.size()) - 1;  // curve degree
        curve->reserve(nPoints);

        double denom = (nPoints > 1) ? static_cast<double>(nPoints - 1) : 1.0;

        for (int j = 0; j < nPoints; ++j) {
            double t = static_cast<double>(j) / denom; // 0 <= t <= 1

            // Work on a local copy of control points in homogeneous coordinates
            std::vector<WPoint3D> pts = ctrlPoints;

            // de Casteljau iterative evaluation in homogeneous space
            for (int r = 1; r <= n; ++r) {
                for (int i = 0; i <= n - r; ++i) {
                    double invt = 1.0 - t;
                    pts[i].X = invt * pts[i].X + t * pts[i + 1].X;
                    pts[i].Y = invt * pts[i].Y + t * pts[i + 1].Y;
                    pts[i].Z = invt * pts[i].Z + t * pts[i + 1].Z;
                    pts[i].W = invt * pts[i].W + t * pts[i + 1].W;
                }
            }

            // Convert from homogeneous coordinates to Cartesian (handle W == 0)
            Point3D out{0.0, 0.0, 0.0};
            if (pts[0].W != 0.0) {
                out.X = pts[0].X / pts[0].W;
                out.Y = pts[0].Y / pts[0].W;
                out.Z = pts[0].Z / pts[0].W;
            } else {
                out.X = pts[0].X;
                out.Y = pts[0].Y;
                out.Z = pts[0].Z;
            }

            curve->push_back(out);
        }

        return curve;
    }
}
