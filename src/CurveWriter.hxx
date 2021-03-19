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

// C++ Headers
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

// Developer Headers
#include "Point.hxx"

namespace BezierLite
{

    #ifndef CURVEWRITER
    #define CURVEWRITER

    class CurveWriter final
    {
        public:

            /// Writes a curve to tab seperated file format
            /// @param <Input> Curve object (vector of Points)
            /// @param <Input> Outpuf file name
            /// @param <Input/Optional> Column width. Default = 10
            static void WriteToTSV
            (
                std::vector<BezierLite::Point> curve,
                const std::string fileName,
                int colWidth = 10
            );

            /// Writes a curve to comma seperated file format
            /// @param <Input> Curve object (vector of Points)
            /// @param <Input> Outpuf file name
            /// @param <Input/Optional> Column width. Default = 10
            static void WriteToCSV
            (
                std::vector<BezierLite::Point> curve,
                std::string fileName,
                int colWidth = 10
            );

    };
    #endif

} // End of namespace BezierLite
