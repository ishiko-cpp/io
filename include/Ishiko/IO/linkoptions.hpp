/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/io/blob/main/LICENSE.txt
*/

#ifndef GUARD_ISHIKO_CPP_IO_LINKOPTIONS_HPP
#define GUARD_ISHIKO_CPP_IO_LINKOPTIONS_HPP

#ifdef _DEBUG
#pragma comment(lib, "IshikoIO-d.lib")
#else
#pragma comment(lib, "IshikoIO.lib")
#endif

#endif
