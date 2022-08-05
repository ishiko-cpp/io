/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/io/blob/main/LICENSE.txt
*/

#ifndef GUARD_ISHIKO_CPP_IO_IOERROREXTENSION_HPP
#define GUARD_ISHIKO_CPP_IO_IOERROREXTENSION_HPP

#include <Ishiko/Errors.hpp>
#include <ios>

namespace Ishiko
{

class IOErrorExtension : public Error::Extension
{
public:
    enum EIOErrorCode
    {
        eError,
        eEOF
    };

    std::ostream& operator<<(std::ostream& os) const override;

    static void Fail(Error& error, EIOErrorCode code, const char* file, int line);
    static void Fail(Error& error, const std::ios& status, const char* file, int line);

    EIOErrorCode code() const;
    
private:
    EIOErrorCode m_code;
    std::string m_file;
    int m_line;
};

}

#endif
