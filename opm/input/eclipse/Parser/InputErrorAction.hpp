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

#ifndef OPM_INPUT_ERROR_ACTION_HPP
#define OPM_INPUT_ERROR_ACTION_HPP

#include <iosfwd>

namespace Opm {

enum class InputErrorAction {
/*
  The THROW_EXCEPTION and EXIT1 error handlers are overlapping, the
  intention os that the EXIT1 handler should be used in situations which
  are clearly user errors where an exception/traceback is of no use to
  the developers. The prototype of an error mode which should be handled
  with EXIT1 is PARSE_MISSING_INCLUDE.
*/
    THROW_EXCEPTION = 0,
    WARN = 1,
    IGNORE = 2,
    EXIT1 = 3,
    DELAYED_EXIT1 = 4
};

std::ostream& operator<<(std::ostream& os, const InputErrorAction action);

}

#endif
