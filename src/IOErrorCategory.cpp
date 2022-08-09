/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/io/blob/main/LICENSE.txt
*/

#include "IOErrorCategory.hpp"

using namespace Ishiko;

const IOErrorCategory& IOErrorCategory::Get() noexcept
{
    static IOErrorCategory theCategory;
    return theCategory;
}

const char* IOErrorCategory::name() const noexcept
{
    return "Ishiko::IOErrorCategory";
}

std::ostream& IOErrorCategory::streamOut(int value, std::ostream& os) const
{
    switch (static_cast<Value>(value))
    {
    case Value::generic_error:
        os << "generic error";
        break;

    case Value::create_file_error:
        os << "create file error";
        break;

    case Value::open_file_error:
        os << "open file error";
        break;

    default:
        os << "unknown value";
        break;
    }
    return os;
}

void Ishiko::Fail(IOErrorCategory::Value value, Error& error) noexcept
{
    error.fail(IOErrorCategory::Get(), static_cast<int>(value));
}

void Ishiko::Fail(IOErrorCategory::Value value, const std::string& message, const char* file, int line,
    Error& error) noexcept
{
    error.fail(IOErrorCategory::Get(), static_cast<int>(value), message, file, line);
}
