/*------------------------------------------------------------------------------
BezierLite Library

Copyright (c) 2018, Osarobo Famous Okhuahesogie, famous.osarobo@gmail.com

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


This file is part of BezierLite library
------------------------------------------------------------------------------*/

// C++
#include <iostream>
#include <memory>
#include <vector>

// Developer
#include "../src/point.h"
#include "../src/bezier_control_point.h"
#include "../src/curve.h"
#include "../src/bezier_curve.h"
#include "../src/linear_interpolator.h"
#include "../src/curve_writer.h"


using Point = BezierLite::Point;
using BezierControlPoint = BezierLite::BezierControlPoint;
using BezierCurve = BezierLite::BezierCurve;
using LinearInterpolator = BezierLite::LinearInterpolator;
using CurveWriter = BezierLite::CurveWriter;

int main()
{

	// Create a point in stack and print it
	Point p(0,0,0);
	p.print();


	// *************************************************************************
	// Create a vector containing four control points 
	std::vector<Point> ctrl_points;
	ctrl_points.push_back(p);
	p.setXYZ(2,5,-4);
	ctrl_points.push_back(p);
	p.setXYZ(4,-2,0);
	ctrl_points.push_back(p);
	p.setXYZ(5,4,3);
	ctrl_points.push_back(p);
	// *************************************************************************


	// *************************************************************************
	// Construct a Bezier curve using the four control points.
	// The Bezier curve should contain 10 points
	auto bezier_curve =
    std::make_unique<BezierCurve>(ctrl_points, 10);
	bezier_curve->constructCurve();
	std:: cout << "Printing Bezier Curve " << std::endl;
	bezier_curve->printCurve();
	//**************************************************************************


	// *************************************************************************
	// Construct a linear interpolator curve using the four control points
	// The Linear Interpolator curve should contain 10 points + original 
	// internal points (excluding first and last)
	auto linter_curve =
    std::make_unique<LinearInterpolator>(ctrl_points,10);
	linter_curve->constructCurve();
	std:: cout << "Printing Linear Interpolator Curve " << std::endl;
	linter_curve->printCurve();
	// *************************************************************************



	// *************************************************************************
	// Construct a new Bezier curve using the linear interpolator curve points
	// as control points. The new Bezier curve should contain 10 points
	std::unique_ptr<BezierCurve> 
	bezier_curve_2(new BezierCurve(linter_curve->getCurve(), 10));
	bezier_curve_2->constructCurve();
	std:: cout << "Printing New Bezier Curve " << std::endl;
	bezier_curve_2->printCurve();
	bezier_curve_2->writeCurveToTSV("bezier.dat", 20); // writer to file
	// *************************************************************************




	// *************************************************************************
	// Construct a new Bezier curve using the linear interpolator curve points
	// as control points. Assign weights to the control points by copying
	// into a new vector of control points. The new Bezier curve should 
	// contain 10 points	
	std::vector<BezierControlPoint> w_ctrl_pts;
	int counter = 1;
	BezierControlPoint* bcp = new BezierControlPoint(0,0,0,1);
	for (const auto& p : linter_curve->getCurve())
	{
		bcp->setXYZW(p.getX(), p.getY(), p.getZ(), counter);
		w_ctrl_pts.push_back(*bcp);
		counter++;
	}
	delete bcp;
	bcp = nullptr;

	// use the static member function to get new Bezier curve without creating
	// a Bezier curve object.
	auto w_bezier_curve = BezierCurve::getBezierCurve(w_ctrl_pts,10);

	// write to csv file using directly the static member function the file 
	// writer class.
	CurveWriter::writeToCSV(w_bezier_curve, "w_bezier.dat", 20); 
	// *************************************************************************

	// Create a base class pointer to derived class
	std::unique_ptr<Point> p1(new BezierControlPoint(1,2,0,1));
	p1->print();

	// Add to existing control points vector, then print control points. Notice
	// the weight is not printed to screen.
	ctrl_points.push_back(*p1);

	std::cout << "Printing control points again " << std::endl;
	for (auto& p : ctrl_points) p.print();


}
