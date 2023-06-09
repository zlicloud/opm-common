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

namespace external {
namespace cvf {


//==================================================================================================
//
// 
//
//==================================================================================================
class CodeLocation
{
public:
    CodeLocation();
    CodeLocation(const char* fileName, const char* functionName, int lineNumber);
    CodeLocation(const CodeLocation& other);

    const CodeLocation& operator=(CodeLocation rhs);

    const char*         fileName() const;
    const char*         shortFileName() const;
    const char*         functionName() const;
    int                 lineNumber() const;
    void                swap(CodeLocation& other);

private:
    const char*     m_fileName;
    const char*     m_functionName;
    int             m_lineNumber;
};


#if defined(_MSC_VER)
#define CVF_CODELOC_FUNCNAME __FUNCSIG__
#elif defined(__GNUC__)
#define CVF_CODELOC_FUNCNAME __PRETTY_FUNCTION__
#else
#define CVF_CODELOC_FUNCNAME ""
#endif

#define CVF_CODE_LOCATION ::cvf::CodeLocation(__FILE__, CVF_CODELOC_FUNCNAME, __LINE__)


} // cvf


} //namespace external
