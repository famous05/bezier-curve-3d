
/*------------------------------------------------------------------------------
BezierLite Library

Copyright (c) 2020, Osarobo Famous Okhuahesogie, famous.osarobo@gmail.com

License
    This file is part of BezierLite library. 
    BezierLite is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    BezierLite is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with BezierLite.  If not, see <http://www.gnu.org/licenses/>.


Class
    BezierLite::BezierCurve

Description
    Bezier curve class for constructing Bezier curves

SourceFiles
    bezier_curve.cpp

This file is part of BezierLite library
------------------------------------------------------------------------------*/


// Developer Headers
#include "bezier_curve.h"

namespace BezierLite
{

BezierCurve::BezierCurve()
{

}

BezierCurve::BezierCurve
(const std::vector<BezierLite::BezierControlPoint>& cpts,
                                                int num_curve_points)
{
    for(auto cp : cpts) this->ctrl_points.push_back(cp);
    this->setNumCurvePoints(num_curve_points);
}

BezierCurve::BezierCurve(const std::vector<BezierLite::Point>& cpts,
                                                int num_curve_points)
{
	// Convert control points to BezierControlPoint type, setting weight to 1
	std::unique_ptr<BezierLite::BezierControlPoint> 
	cp(new BezierLite::BezierControlPoint(0,0,0,1));

    for(auto p : cpts)
    {
    	cp->setXYZ(p.getX(), p.getY(), p.getZ());
		this->ctrl_points.push_back(*cp);    	
    } 
    this->setNumCurvePoints(num_curve_points);
}


BezierCurve::BezierCurve(const BezierCurve& bezier_curve)
{
	this->ctrl_points = bezier_curve.ctrl_points;
	this->clearCurve();
	for (auto p : bezier_curve.getCurve()) this->appendPointToCurve(p);
	this->num_curve_points = bezier_curve.num_curve_points;
}


BezierCurve& BezierCurve::operator =(const BezierCurve& bezier_curve)
{
	if (&bezier_curve != this)
	{
		this->ctrl_points = bezier_curve.ctrl_points;
		this->clearCurve();
		for (auto p : bezier_curve.getCurve()) this->appendPointToCurve(p);
		this->num_curve_points = bezier_curve.num_curve_points;
	}
	return *this;
}


BezierCurve::~BezierCurve()
{
    this->clearControlPoints();
    this->clearCurve();
}


void BezierCurve::printControlPoints()
{
	BezierLite::Curve::printCurve(this->ctrl_points);
}

std::vector<BezierLite::BezierControlPoint>& 
BezierCurve::getControlPoints()
{
    return this->ctrl_points;
}


std::vector<BezierLite::Point>
BezierCurve::getBezierCurve(const std::vector<BezierLite::BezierControlPoint>& cpts,
int num_points)
{
    auto b_curve =
    std::make_unique<BezierLite::BezierCurve>(cpts, num_points);
    b_curve->constructCurve();
    return b_curve->getCurve();
}

std::vector<BezierLite::Point>
BezierCurve::getBezierCurve(const std::vector<BezierLite::Point>& cpts,
int num_points)
{
    auto b_curve =
    std::make_unique<BezierLite::BezierCurve>(cpts,num_points);
    b_curve->constructCurve();
    return b_curve->getCurve();
}


void BezierCurve::appendControlPoint(const BezierLite::BezierControlPoint &p)
{
    this->ctrl_points.push_back(p);
}

void BezierCurve::appendControlPoint(const BezierLite::Point &p)
{	
	std::unique_ptr<BezierLite::BezierControlPoint> cp
	(new BezierLite::BezierControlPoint(0,0,0,1));
	cp->setXYZ(p.getX(), p.getY(), p.getZ());
    this->ctrl_points.push_back(*cp);
}


void BezierCurve::clearControlPoints()
{
	if (!(this->ctrl_points.empty())) this->ctrl_points.clear();
}

void BezierCurve::setNumCurvePoints(int num_of_points_on_curve)
{
    if (num_of_points_on_curve < 3)
    {
        std::cout << "Warning: At least 3 points should be requested for";
        std::cout << " the Bezier curve to be constructed !" << std::endl;
        this->num_curve_points = 3;
    }
    this->num_curve_points = num_of_points_on_curve;
}


void BezierCurve::scaleControlPoints(double factor)
{
    BezierLite::Curve::scaleCurve(this->ctrl_points, factor);
}

void BezierCurve::constructCurve()
{
    double t = 0;
    int n = this->ctrl_points.size() - 1;  // curve degree
    int i = 0;
    double sum_den = 0;
    double weight_t_poly = 0;

    // Clear existing curve points if not empty
    //if (!(this->getNumCurvePoints() == 0)) this->curve_points.clear();
    this->clearCurve();

    // Check if all control points weights equal 1
    bool is_weighted = false;
    for (const auto& ctrl_point : this->ctrl_points)
    {
    	if (ctrl_point.getWeight() != 1)
    	{
    		is_weighted = true;
    	}
    }

    BezierLite::Point* sum_point =  
    new BezierLite::Point(0,0,0);

    BezierLite::Point* point =  
    new BezierLite::Point(0,0,0);

    for (int j = 0; j < this->num_curve_points; j++)
    {
        // Calculate t parameter: (0 <= t <= 1)
        t = (double)j/double(this->num_curve_points - 1);
        i = 0;
        if (is_weighted == false)
        {
        	for (const auto& ctrl_point : this->ctrl_points)
	        {
	            *point = ctrl_point * this->getBernsteinPolynomial(i,n,t);
	            *sum_point = *sum_point + *point;
	            i += 1;
	        }

	        //this->curve_points.push_back(*sum_point);
	        this->appendPointToCurve(*sum_point);
	        sum_point->setXYZ(0,0,0);
        }
        else
        {
        	for (const auto& ctrl_point : this->ctrl_points)
	        {
	        	// denominator for each ctrl pt (weight * bernstein polynomial)
	        	weight_t_poly = 
	        	ctrl_point.getWeight() * this->getBernsteinPolynomial(i,n,t);

	        	*point = ctrl_point * weight_t_poly;

	            *sum_point = *sum_point + *point;

	            // summation of denominator: den = den + weight * bernstein poly
	            sum_den = sum_den + weight_t_poly;
	            i += 1;
	        }
	        *sum_point = *sum_point * (1/sum_den);
	        //this->curve_points.push_back(*sum_point);
	    	this->appendPointToCurve(*sum_point);
	        sum_point->setXYZ(0,0,0);
	        sum_den = 0;
        }

    }

    delete sum_point;
    delete point;
    sum_point = nullptr;
    point = nullptr;

}


int BezierCurve::getFactorial(int n) const
{
    int factorial = 0;
    if (n == 0)
    {
        factorial = 1;
    }
    else if (n == 1)
    {
        factorial = 1;
    }
    else
    {
        factorial = n * this->getFactorial(n-1);
    }
    return factorial;
}

double BezierCurve::getBinomialCoefficient(int n, int i) const
{
    /*
        returns n!/(i! * (n-i)!)  i.e. nCi
    */
    return this->getFactorial(n)/((this->getFactorial(i)) *
                                                (this->getFactorial(n-i)));
}

double BezierCurve::getBernsteinPolynomial(int i, int n, double t) const
{
    /*
        retuns nCi * t^i * (1-t)^(n-i)
    */
    return this->getBinomialCoefficient(n,i) * std::pow(t,i) * std::pow(1-t,n-i);
}


} // End of namespace BezierLite

