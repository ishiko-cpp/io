/*
    Copyright (c) 2020-2024 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/io/blob/main/LICENSE.txt
*/

#include "IOErrorCategory.hpp"

using namespace Ishiko;

IOErrorCategory::IOErrorCategory() noexcept
    : ErrorCategory(ID(0x20605b5f80ad43b5ULL, 0xb3fd641673d9f56fULL)) // 20605b5f-80ad-43b5-b3fd-641673d9f56f
{
}

const IOErrorCategory& IOErrorCategory::Get() noexcept
{
    static IOErrorCategory theCategory;
    return theCategory;
}

const char* IOErrorCategory::name() const noexcept
{
    return "Ishiko::IOErrorCategory";
}

const char* IOErrorCategory::message(int ev, char* buffer, size_t len) const noexcept
{
    switch (static_cast<Value>(ev))
    {
    case Value::generic_error:
        return "generic error";

    case Value::create_file_error:
        return "create file error";

    case Value::open_file_error:
        return "open file error";

    default:
        return "unknown value";
    }
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
