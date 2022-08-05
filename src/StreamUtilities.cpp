/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/io/blob/main/LICENSE.txt
*/

#include "StreamUtilities.hpp"
#include "IOErrorCategory.hpp"

using namespace Ishiko;

bool Ishiko::FailIfCreateFileError(Error& error, const std::ios& status) noexcept
{
    return FailIfCreateFileError(error, status, "", nullptr, -1);
}

bool Ishiko::FailIfCreateFileError(Error& error, const std::ios& status, const std::string& path, const char* file,
    int line) noexcept
{
    if (!status.good())
    {
        Fail(error, IOErrorCategory::eCreateFileError, "failed to create file \'" + path + "\'", file, line);
        return true;
    }
    else
    {
        return false;
    }
}

bool Ishiko::FailIfOpenFileError(Error& error, const std::ios& status) noexcept
{
    return FailIfOpenFileError(error, status, "", nullptr, -1);
}

bool Ishiko::FailIfOpenFileError(Error& error, const std::ios& status, const std::string& path, const char* file,
    int line) noexcept
{
    if (!status.good())
    {
        Fail(error, IOErrorCategory::eOpenFileError, "failed to open file \'" + path + "\'", file, line);
        return true;
    }
    else
    {
        return false;
    }
}
