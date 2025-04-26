/*------------------------------------------------------------------------------
BezierLite Library

Copyright (c) 2017 - 2021, Osarobo Famous Okhuahesogie, famous.osarobo@gmail.com

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


// Class Header
#include "CurveWriter.hxx"

namespace BezierLite
{
    void CurveWriter::WriteToTSV(std::vector<BezierLite::Point> curve,
                    std::string fileName, int colWidth)
    {
        std::ofstream writer(fileName);
        for (const auto& p : curve)
        {
            writer << std::left << std::setw(colWidth) << p.GetX();
            writer << std::left << std::setw(colWidth) << p.GetY();
            writer << std::left << std::setw(colWidth) << p.GetZ();
            writer << std::endl;
        }
        writer.close();
    }


    void CurveWriter::WriteToCSV(std::vector<BezierLite::Point> curve,
                    std::string fileName, int colWidth)
    {
        std::ofstream writer(fileName);
        for (const auto& p : curve)
        {
            writer << std::left << std::setw(colWidth) << p.GetX() << ',';
            writer << std::left << std::setw(colWidth) << p.GetY() << ',';
            writer << std::left << std::setw(colWidth) << p.GetZ();
            writer << std::endl;
        }
        writer.close();
    }

}
