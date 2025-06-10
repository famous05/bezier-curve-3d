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

#include "bezier-curve-3d/Utils.h"

namespace bezier_curve_3d
{
    double Utils::GetDistanceBetweenPoints(const Point3D& p1, const Point3D& p2) noexcept
    {
        Eigen::Vector3d v1(p1.X, p1.Y, p1.Z);
        Eigen::Vector3d v2(p2.X, p2.Y, p2.Z);
        return (v1 - v2).norm();
    }

    int Utils::GetFactorial(int n)
    {
        if (n == 0 || n == 1) return 1;

        return n * Utils::GetFactorial(n - 1);
    }

    double Utils::GetBinomialCoefficient(int n, int i)
    {
        return Utils::GetFactorial(n)/((Utils::GetFactorial(i)) *
                                                    (Utils::GetFactorial(n - i)));
    }

    double Utils::GetBernsteinPolynomial(int i, int n, double t)
    {
        return Utils::GetBinomialCoefficient(n, i) * std::pow(t, i) * std::pow(1 - t, n - i);
    }
}
