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

bool FailIfCreateFileError(Error& error, const std::ios& status) noexcept;
bool FailIfCreateFileError(Error& error, const std::ios& status, const std::string& path, const char* file,
    int line) noexcept;
bool FailIfOpenFileError(Error& error, const std::ios& status) noexcept;
bool FailIfOpenFileError(Error& error, const std::ios& status, const std::string& path, const char* file,
    int line) noexcept;

}

#endif
