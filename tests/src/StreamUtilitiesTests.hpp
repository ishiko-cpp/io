/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/io/blob/main/LICENSE.txt
*/

#ifndef GUARD_ISHIKO_CPP_IO_TESTS_STREAMUTILITIESTESTS_HPP
#define GUARD_ISHIKO_CPP_IO_TESTS_STREAMUTILITIESTESTS_HPP

#include <Ishiko/TestFramework/Core.hpp>

class StreamUtilitiesTests : public Ishiko::TestSequence
{
public:
    StreamUtilitiesTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void FailIfCreateFileErrorTest1(Ishiko::Test& test);
    static void FailIfCreateFileErrorTest2(Ishiko::Test& test);
    static void FailIfOpenFileErrorTest1(Ishiko::Test& test);
    static void FailIfOpenFileErrorTest2(Ishiko::Test& test);
};

#endif
