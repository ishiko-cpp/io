/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/io/blob/main/LICENSE.txt
*/

#ifndef GUARD_ISHIKO_CPP_IO_TESTS_IOERROREXTENSIONTESTS_HPP
#define GUARD_ISHIKO_CPP_IO_TESTS_IOERROREXTENSIONTESTS_HPP

#include <Ishiko/TestFramework/Core.hpp>

class IOErrorExtensionTests : public Ishiko::TestSequence
{
public:
    IOErrorExtensionTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructionTest1(Ishiko::Test& test);
    static void FailTest1(Ishiko::Test& test);
    static void FailTest2(Ishiko::Test& test);
    static void FailTest3(Ishiko::Test& test);
    static void FailTest4(Ishiko::Test& test);
    static void FailTest5(Ishiko::Test& test);
    static void FailTest6(Ishiko::Test& test);
    static void StreamInsertionTest1(Ishiko::Test& test);
};

#endif
