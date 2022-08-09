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
    enum class Value
    {
        generic_error = -1,
        create_file_error = -2,
        open_file_error = -3
    };

    static const IOErrorCategory& Get() noexcept;

    const char* name() const noexcept override;
    std::ostream& streamOut(int value, std::ostream& os) const override;

private:
    IOErrorCategory() noexcept = default;
};

void Fail(IOErrorCategory::Value value, Error& error) noexcept;
void Fail(IOErrorCategory::Value value, const std::string& message, const char* file, int line,
    Error& error) noexcept;

}

#endif
