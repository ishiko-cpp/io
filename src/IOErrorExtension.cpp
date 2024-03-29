/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/io/blob/main/LICENSE.txt
*/

#include "IOErrorExtension.hpp"
#include "IOErrorCategory.hpp"
#include <errno.h>

using namespace Ishiko;

void IOErrorExtension::Fail(EIOErrorCode code, const char* file, int line, Error& error)
{
    error.fail(IOErrorCategory::Get(), EIO, "", file, line);

    IOErrorExtension* ext;
    if (error.extensions().tryGet(ext))
    {
        ext->m_code = code;
        ext->m_file = file;
        ext->m_line = line;
    }
}

void IOErrorExtension::Fail(const std::ios& status, const char* file, int line, Error& error)
{
    if (!status.good())
    {
        error.fail(IOErrorCategory::Get(), EIO, "", file, line);

        EIOErrorCode code = eError;
        if (status.eof())
        {
            code = eEOF;
        }

        IOErrorExtension* ext;
        if (error.extensions().tryGet(ext))
        {
            ext->m_code = code;
            ext->m_file = file;
            ext->m_line = line;
        }
    }
}

std::ostream& IOErrorExtension::streamOut(std::ostream& os) const
{
    os << ", I/O error: ";
    switch (m_code)
    {
    case eEOF:
        os << "end-of-file";
        break;
    }
    if (m_file.size() > 0)
    {
        os << " [file: " << m_file << ", line: " << m_line << "]";
    }
    return os;
}

IOErrorExtension::EIOErrorCode IOErrorExtension::code() const
{
    return m_code;
}
