/*------------------------------------------------------------------------------
BezierLite Library

Copyright (c) 2017 - 2020, Osarobo Famous Okhuahesogie, famous.osarobo@gmail.com

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
#include "../src/Point.hxx"


using Point = BezierLite::Point;

int main()
{

	
	Point p1(0,-10,0);
	p1.Print();

	auto p2 = std::make_unique<Point>(0.5, 1, 2);
	p2->Print();


	auto p3 = p1 + *p2;
	p3.Print();


	p1 = p1 * 2;
        p1.Print();

}
