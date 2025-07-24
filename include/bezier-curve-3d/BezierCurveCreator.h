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

#pragma once

#include <typeinfo>
#include <vector>

#include "Point3D.h"
#include "WPoint3D.h"

namespace bezier_curve_3d
{
    template<typename T, typename = std::enable_if_t<std::is_same_v<T, Point3D> || std::is_same_v<T, WPoint3D>>>
    class BezierCurveCreator
    {
        public:
            BezierCurveCreator(std::vector<T> Points, int NPoints) : m_CtrlPoints(Points), m_NumPoints(NPoints) {}

        public:
            std::vector<Point3D> GetBezierCurvePoints(){ return CalculateBezierCurve();}

        private:
        std::vector<Point3D> CalculateBezierCurve(){
            std::vector<Point3D> curvePoints;

            double t = 0;
            int n = m_CtrlPoints.size() - 1;  // curve degree
            int i = 0;
            double denSum = 0;
            double weightTPoly = 0;
            Point3D point {0, 0, 0};
            Point3D sPoint {0, 0, 0};

            for (int j = 0; j < m_NumPoints; j++){
                // Calculate t parameter: (0 <= t <= 1)
                t = (double)j/double(m_NumPoints - 1);
                i = 0;

                //if(typeid(m_CtrlPoints.front()) == typeid(Point3D)){
                if (std::is_same_v<decltype(m_CtrlPoints.front()), Point3D>){
                    for (const auto& p : m_CtrlPoints){
                        point = p * Utils::GetBernsteinPolynomial(i,n,t);
                        sPoint = sPoint + point;
                        i += 1;
                    }
                    curvePoints.push_back(sPoint);
                }else if (std::is_same_v<decltype(m_CtrlPoints.front()), WPoint3D>){
                    for (const auto& p : m_CtrlPoints){
                        //auto p_ = static_cast<WPoint3D>(p);
                        weightTPoly = p.W * Utils::GetBernsteinPolynomial(i,n,t);
                        point = p * weightTPoly;
                        sPoint = sPoint + point;
                        denSum = denSum + weightTPoly;
                        i += 1;
                    }
                    sPoint = sPoint * (1.0 / denSum);
                    curvePoints.push_back(sPoint);
                    denSum = 0;
                }
                sPoint = Point3D {0, 0, 0};

            }
            return curvePoints;
        }

        private:
            std::vector<T> m_CtrlPoints;
            int m_NumPoints;
    };
}
