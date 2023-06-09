//##################################################################################################
//
//   Custom Visualization Core library
//   Copyright (C) 2011-2013 Ceetron AS
//
//   This library may be used under the terms of either the GNU General Public License or
//   the GNU Lesser General Public License as follows:
//
//   GNU General Public License Usage
//   This library is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
//   This library is distributed in the hope that it will be useful, but WITHOUT ANY
//   WARRANTY; without even the implied warranty of MERCHANTABILITY or
//   FITNESS FOR A PARTICULAR PURPOSE.
//
//   See the GNU General Public License at <<http://www.gnu.org/licenses/gpl.html>>
//   for more details.
//
//   GNU Lesser General Public License Usage
//   This library is free software; you can redistribute it and/or modify
//   it under the terms of the GNU Lesser General Public License as published by
//   the Free Software Foundation; either version 2.1 of the License, or
//   (at your option) any later version.
//
//   This library is distributed in the hope that it will be useful, but WITHOUT ANY
//   WARRANTY; without even the implied warranty of MERCHANTABILITY or
//   FITNESS FOR A PARTICULAR PURPOSE.
//
//   See the GNU Lesser General Public License at <<http://www.gnu.org/licenses/lgpl-2.1.html>>
//   for more details.
//
//##################################################################################################


#pragma once

#include "cvfString.h"

namespace external {
namespace cvf {

class Timer;


//=================================================================================================
// 
// Timer class
// 
//=================================================================================================
class DebugTimer
{
public:
    enum OperationMode
    {
        NORMAL,     ///< Normal operation
        DISABLED    ///< Disables all functionality in the class
    };

public:
    explicit DebugTimer(const char* prefix, OperationMode operationMode = NORMAL);
    ~DebugTimer();

    void    restart(const char* msg = NULL);

    void    reportTime(const char* msg = NULL);
    void    reportTimeMS(const char* msg = NULL);
    void    reportLapTime(const char* msg = NULL);
    void    reportLapTimeMS(const char* msg = NULL);

    void    echoMessage(const char* format, ...);

private:
    String	makeMessageStartString(const char* msg);

private:
    Timer*      m_timer;            ///< The actual timer object to use
    String*     m_prefix;           ///< String to prefix all output
    int         m_messageCount;     ///< Counts number of messages returned

    CVF_DISABLE_COPY_AND_ASSIGN(DebugTimer);
};

}
} //namespace external
