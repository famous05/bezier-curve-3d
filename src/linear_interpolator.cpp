
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
    BezierLite::LinearInterpolator

Description
    Linear Interpolator between Points

SourceFiles
    linear_interpolator.cpp

This file is part of BezierLite library
------------------------------------------------------------------------------*/


// Developer Headers
#include "linear_interpolator.h"

namespace BezierLite
{


LinearInterpolator::LinearInterpolator()
{

}


LinearInterpolator::LinearInterpolator
(const std::vector<BezierLite::Point>& cpts,
                                                int num_curve_points)
{
    for(auto cp : cpts) this->ctrl_points.push_back(cp);
    this->setNumCurvePoints(num_curve_points);
}


LinearInterpolator::LinearInterpolator(const LinearInterpolator& linter_curve)
{
	this->ctrl_points = linter_curve.ctrl_points;
	this->clearCurve();
	for (auto p : linter_curve.getCurve()) this->appendPointToCurve(p);
	this->num_curve_points = linter_curve.num_curve_points;
}


LinearInterpolator& LinearInterpolator::operator =(const LinearInterpolator& linter_curve)
{
	if (&linter_curve != this)
	{
		this->ctrl_points = linter_curve.ctrl_points;
		this->clearCurve();
		for (auto p : linter_curve.getCurve()) this->appendPointToCurve(p);
		this->num_curve_points = linter_curve.num_curve_points;
	}
	return *this;
}


LinearInterpolator::~LinearInterpolator()
{
    this->clearControlPoints();
    this->clearCurve();
}



void LinearInterpolator::printControlPoints()
{
	BezierLite::Curve::printCurve(this->ctrl_points);
}

void LinearInterpolator::setNumCurvePoints(int num_curve_points)
{
    this->num_curve_points = num_curve_points;
}


std::vector<BezierLite::Point>
LinearInterpolator::getLinearInterpolatorCurve(const std::vector<BezierLite::Point>& cpts,
int num_points)
{
    auto linter_curve =
    std::make_unique<BezierLite::LinearInterpolator>(cpts,num_points);
    linter_curve->constructCurve();
    return linter_curve->getCurve();
}


void LinearInterpolator::constructCurve()
{
   
    // clear existing curve points if not empty
    if (!(this->getCurve().empty())) this->clearCurve();


    // utilility point
    std::unique_ptr<BezierLite::Point> point(new BezierLite::Point(0,0,0));

    // construct vector of cummulative linear length distribution of ctrl points
    std::vector<double> cum_lengths;
    double i_sum_len = 0;
    int counter = 0;
    for (const auto& p : this->getControlPoints())
    {
        if (counter == 0) 
        {
            cum_lengths.push_back(0);
            *point = p;
        }
        else
        {
            i_sum_len = i_sum_len + p.getDistToPoint(*point);
            cum_lengths.push_back(i_sum_len);
            *point = p;
        }
        counter += 1;
    }
    //**************************************************************************


    // normalise the cummulative distance to 0 -> 1 ****************************
    std::vector<double> cum_lengths_norm;
    auto max_cum_len = std::max_element(cum_lengths.begin(), cum_lengths.end());
    for (const auto& len : cum_lengths)
    {
        cum_lengths_norm.push_back(len/(*max_cum_len));   
    }
    //**************************************************************************


    // compute interpolate points fractions (the parameter t) 0 <= t <= 1 ******
    double t = 0;
    std::vector<double> t_dist;
    for (int i = 0; i < this->num_curve_points; i++)
    {
        t = double(i)/double(this->num_curve_points - 1);
        t_dist.push_back(t);
    }
    //**************************************************************************



    // interpolate points based on t parameter compared to ctrl points *********
    // normalised cummulative length. Both are from 0 to 1
    
    double frac;
    double prev_t = 0;

    // first append first control point
    this->appendPointToCurve(this->getControlPoints().front()); 

    for(int i = 1; i < cum_lengths_norm.size()-1; i++) // ctrl points norm vals
    {  
        for (auto t : t_dist)
        {
            // first add original control points
            if ((cum_lengths_norm.at(i) > prev_t) && (cum_lengths_norm.at(i) < t))
            {
                this->appendPointToCurve(this->getControlPoints().at(i));
            }

            if ((t >= cum_lengths_norm.at(i)) && (t < cum_lengths_norm.at(i+1)))
            {
                frac = (t - cum_lengths_norm.at(i))/
                (cum_lengths_norm.at(i+1) - cum_lengths_norm.at(i));
                *point = LinearInterpolator::getPointAt
                (this->getControlPoints().at(i),this->getControlPoints().at(i+1),frac);
                this->appendPointToCurve(*point);
            }
            prev_t = t;
        }
    }

    // append last control point
    this->appendPointToCurve(this->getControlPoints().back());

    //**************************************************************************
}


const std::vector<BezierLite::Point>& LinearInterpolator::getControlPoints() const
{
    return this->ctrl_points;
}


void LinearInterpolator::clearControlPoints()
{
    this->ctrl_points.clear();
}


const BezierLite::Point& LinearInterpolator::getPointAt(const BezierLite::Point& p1, 
                                const BezierLite::Point& p2, double frac)
{
   return p1 + ((p2 - p1) * frac);
}


void LinearInterpolator::appendControlPoint(const BezierLite::Point& p)
{
    this->ctrl_points.push_back(p);
}


} // End of namespace BezierLite
