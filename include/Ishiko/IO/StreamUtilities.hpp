/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/io/blob/main/LICENSE.txt
*/

#ifndef GUARD_ISHIKO_CPP_IO_STREAMUTILITIES_HPP
#define GUARD_ISHIKO_CPP_IO_STREAMUTILITIES_HPP

#include <Ishiko/Errors.hpp>
#include <ios>

namespace Ishiko
{

bool FailIfCreateFileError(const std::ios& status, Error& error) noexcept;
bool FailIfCreateFileError(const std::ios& status, const std::string& path, const char* file, int line,
    Error& error) noexcept;
bool FailIfOpenFileError(const std::ios& status, Error& error) noexcept;
bool FailIfOpenFileError(const std::ios& status, const std::string& path, const char* file, int line,
    Error& error) noexcept;

}

#endif
