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


// Class Header
#include "curve_writer.h"

namespace BezierLite
{
    void CurveWriter::writeToTSV(std::vector<BezierLite::Point> curve,
                    std::string file_name, int col_width)
    {
        std::ofstream writer(file_name);
        for (const auto& p : curve)
        {
            writer << std::left << std::setw(col_width) << p.getX();
            writer << std::left << std::setw(col_width) << p.getY();
            writer << std::left << std::setw(col_width) << p.getZ();
            writer << std::endl;
        }
        writer.close();
    }


    void CurveWriter::writeToCSV(std::vector<BezierLite::Point> curve,
                    std::string file_name, int col_width)
    {
        std::ofstream writer(file_name);
        for (const auto& p : curve)
        {
            writer << std::left << std::setw(col_width) << p.getX() << ',';
            writer << std::left << std::setw(col_width) << p.getY() << ',';
            writer << std::left << std::setw(col_width) << p.getZ();
            writer << std::endl;
        }
        writer.close();
    }

}
