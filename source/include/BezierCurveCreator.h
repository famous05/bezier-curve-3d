/*------------------------------------------------------------------------------
BezierCurveCreator.h 
-  Class for creating Bezier curves

This file is part of BezierLite library
Copyright (c) 2025, Famous Okhuahesogie, famous.osarobo@gmail.com
------------------------------------------------------------------------------*/

#pragma once

#include <iostream>
#include <typeinfo>
#include <vector>

#include "Point3D.h"
#include "WPoint3D.h"

namespace BezierLite
{
    enum class ControlPointsType{
        Point_3D = 0,
        WPoint_3D
    };


    template<typename T>
    class BezierCurveCreator
    {
        public:
            BezierCurveCreator(std::vector<T> Points, int NPoints) : m_CtrlPoints(Points), m_NumPoints(NPoints)
            {
                if(typeid(m_CtrlPoints.front()) == typeid(Point3D)){
                    std::cout << "Point3DType" << std::endl;
                    m_CtrlPointsType = ControlPointsType::Point_3D;
                }else if (typeid(m_CtrlPoints.front()) == typeid(WPoint3D)){
                    std::cout << "WPoint3DType" << std::endl;
                    m_CtrlPointsType = ControlPointsType::WPoint_3D;
                }else{
                    std::cerr << "Error: Unsupported point type passed to Constructor." << std::endl;
                }
            }
        
        private:
        std::vector<Point3D> CalculateBezierCurve(ControlPointsType Type){

            std::vector<Point3D> curvePoints;

            double t = 0;
            int n = this->m_CtrlPoints.size() - 1;  // curve degree
            int i = 0;
            double denSum = 0;
            double weightTPoly = 0;
            Point3D point {0, 0, 0};
            Point3D sPoint {0, 0, 0};

            for (int j = 0; j < this->m_NumPoints; j++){
                // Calculate t parameter: (0 <= t <= 1)
                t = (double)j/double(this->m_NumPoints - 1);
                i = 0;
        
                if(Type == ControlPointsType::Point_3D) {
                    for (const auto& p : this->m_CtrlPoints){
                        point = p * Utils::GetBernsteinPolynomial(i,n,t);
                        sPoint = sPoint + point;
                        i += 1;
                    }
                    curvePoints.push_back(sPoint);
                    sPoint.X = 0;
                    sPoint.Y = 0;
                    sPoint.Z = 0;
                }else{
                    for (const auto& p : this->m_CtrlPoints){
                        weightTPoly = p.W * Utils::GetBernsteinPolynomial(i,n,t);
                        point = p * weightTPoly;
                        sPoint = sPoint + point;
                        denSum = denSum + weightTPoly;
                        i += 1;
                    }
        
                    sPoint = sPoint * (1 / denSum);
                    curvePoints.push_back(sPoint);
                    sPoint.X = 0;
                    sPoint.Y = 0;
                    sPoint.Z = 0;
                    denSum = 0;
                }
                
            }
            return curvePoints;
        }

    
        public:
            std::vector<Point3D> GetBezierCurvePoints(){
                return CalculateBezierCurve(m_CtrlPointsType);
            }

        private:
        std::vector<T> m_CtrlPoints;
        int m_NumPoints;
        std::vector<Point3D> m_BezierCurvePoints;
        ControlPointsType m_CtrlPointsType;
    };
} 
