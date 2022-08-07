/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/io/blob/main/LICENSE.txt
*/

#ifndef GUARD_ISHIKO_CPP_IO_IOERRORCATEGORY_HPP
#define GUARD_ISHIKO_CPP_IO_IOERRORCATEGORY_HPP

#include <Ishiko/Errors.hpp>

namespace Ishiko
{

class IOErrorCategory : public ErrorCategory
{
public:
    enum EErrorValues
    {
        eGenericError = -1,
        eCreateFileError = -2,
        eOpenFileError = -3
    };

    static const IOErrorCategory& Get() noexcept;

    const char* name() const noexcept override;

private:
    IOErrorCategory() noexcept = default;
};

void Fail(IOErrorCategory::EErrorValues value, Error& error) noexcept;
void Fail(IOErrorCategory::EErrorValues value, const std::string& message, const char* file, int line,
    Error& error) noexcept;

}

#endif
