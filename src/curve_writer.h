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


Class
    BezierLite::CurveWriter

Description
    Defines a class for writing curve points in various formats

SourceFiles
    curve_writer.cpp

This file is part of BezierLite library
------------------------------------------------------------------------------*/

// C++ Headers
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

// Developer Headers
#include "point.h"

namespace BezierLite
{

    #ifndef CURVEWRITER
    #define CURVEWRITER

    class CurveWriter
    {
        public:

            static void writeToTSV(std::vector<BezierLite::Point> curve,
                            		std::string file_name, int col_width = 10);
            

            static void writeToCSV(std::vector<BezierLite::Point> curve,
                            		std::string file_name, int col_width = 10);
            
    };
    #endif

} // End of namespace BezierLite


