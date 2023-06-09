/*
  Copyright 2015 Statoil ASA.

  This file is part of the Open Porous Media project (OPM).

  OPM is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  OPM is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OPM.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef OPM_PINCHMODE_HPP
#define OPM_PINCHMODE_HPP

#include <iosfwd>
#include <string>

namespace Opm {
    
enum class PinchMode {
    ALL = 1,
    TOPBOT = 2,
    TOP = 3,
    GAP = 4,
    NOGAP = 5,
};

std::string PinchMode2String(const PinchMode enumValue);
PinchMode PinchModeFromString(const std::string& stringValue);

std::ostream& operator<<(std::ostream&, const PinchMode);

}


#endif // _PINCHMODE_
