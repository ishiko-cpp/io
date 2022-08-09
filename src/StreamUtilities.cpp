/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/io/blob/main/LICENSE.txt
*/

#include "StreamUtilities.hpp"
#include "IOErrorCategory.hpp"

using namespace Ishiko;

bool Ishiko::FailIfCreateFileError(const std::ios& status, Error& error) noexcept
{
    return FailIfCreateFileError(status, "", nullptr, -1, error);
}

bool Ishiko::FailIfCreateFileError(const std::ios& status, const std::string& path, const char* file, int line,
    Error& error) noexcept
{
    if (!status.good())
    {
        Fail(IOErrorCategory::Value::create_file_error, "failed to create file \'" + path + "\'", file, line, error);
        return true;
    }
    else
    {
        return false;
    }
}

bool Ishiko::FailIfOpenFileError(const std::ios& status, Error& error) noexcept
{
    return FailIfOpenFileError(status, "", nullptr, -1, error);
}

bool Ishiko::FailIfOpenFileError(const std::ios& status, const std::string& path, const char* file, int line,
    Error& error) noexcept
{
    if (!status.good())
    {
        Fail(IOErrorCategory::Value::open_file_error, "failed to open file \'" + path + "\'", file, line, error);
        return true;
    }
    else
    {
        return false;
    }
}
