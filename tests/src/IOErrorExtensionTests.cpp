/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/io/blob/main/LICENSE.txt
*/

#include "IOErrorExtensionTests.hpp"
#include "Ishiko/IO/IOErrorExtension.hpp"
#include <Ishiko/Errors.hpp>
#include <sstream>
#include <fstream>
#include <errno.h>

using namespace Ishiko;

IOErrorExtensionTests::IOErrorExtensionTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "IOErrorExtension tests", context)
{
    append<HeapAllocationErrorsTest>("Construction test 1", ConstructionTest1);
    append<HeapAllocationErrorsTest>("Fail test 1", FailTest1);
    append<HeapAllocationErrorsTest>("Fail test 2", FailTest2);
    append<HeapAllocationErrorsTest>("Fail test 3", FailTest3);
    append<HeapAllocationErrorsTest>("Fail test 4", FailTest4);
    append<HeapAllocationErrorsTest>("Fail test 5", FailTest5);
    append<HeapAllocationErrorsTest>("Fail test 6", FailTest6);
    append<HeapAllocationErrorsTest>("operator<< test 1", StreamInsertionTest1);
}

void IOErrorExtensionTests::ConstructionTest1(Test& test)
{
    IOErrorExtension ioExtension;

    ISHIKO_TEST_PASS();
}

void IOErrorExtensionTests::FailTest1(Test& test)
{
    Error error;
    IOErrorExtension::Fail(error, IOErrorExtension::eEOF, "file1", 3);

    ISHIKO_TEST_FAIL_IF_NEQ(error.condition().value(), EIO);

    const IOErrorExtension* extension;
    bool found = error.extensions().tryGet(extension);

    ISHIKO_TEST_FAIL_IF(found);
    ISHIKO_TEST_PASS();
}

void IOErrorExtensionTests::FailTest2(Test& test)
{
    Error error;
    error.extensions().install<IOErrorExtension>();
    IOErrorExtension::Fail(error, IOErrorExtension::eEOF, "file1", 3);

    ISHIKO_TEST_FAIL_IF_NEQ(error.condition().value(), EIO);

    const IOErrorExtension* extension;
    bool found = error.extensions().tryGet(extension);

    ISHIKO_TEST_ABORT_IF_NOT(found);
    ISHIKO_TEST_FAIL_IF_NEQ(extension->code(), IOErrorExtension::eEOF);
    ISHIKO_TEST_PASS();
}

void IOErrorExtensionTests::FailTest3(Test& test)
{
    boost::filesystem::path inputPath = test.context().getDataPath("file1.txt");
    std::fstream file(inputPath.c_str());

    Error error;
    IOErrorExtension::Fail(error, file, "file1", 3);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(error.condition().value(), 0);

    const IOErrorExtension* extension;
    bool found = error.extensions().tryGet(extension);

    ISHIKO_TEST_FAIL_IF(found);
    ISHIKO_TEST_PASS();
}

void IOErrorExtensionTests::FailTest4(Test& test)
{
    std::fstream file("doesnotexist");

    Error error;
    IOErrorExtension::Fail(error, file, "file1", 3);

    ISHIKO_TEST_FAIL_IF_NOT(error);
    ISHIKO_TEST_FAIL_IF_NEQ(error.condition().value(), EIO);

    const IOErrorExtension* extension;
    bool found = error.extensions().tryGet(extension);

    ISHIKO_TEST_FAIL_IF(found);
    ISHIKO_TEST_PASS();
}

void IOErrorExtensionTests::FailTest5(Test& test)
{
    std::fstream file("doesnotexist");

    Error error;
    error.extensions().install<IOErrorExtension>();
    IOErrorExtension::Fail(error, file, "file1", 3);

    ISHIKO_TEST_FAIL_IF_NOT(error);
    ISHIKO_TEST_FAIL_IF_NEQ(error.condition().value(), EIO);
    
    const IOErrorExtension* extension;
    bool found = error.extensions().tryGet(extension);

    ISHIKO_TEST_ABORT_IF_NOT(found);
    ISHIKO_TEST_FAIL_IF_NEQ(extension->code(), IOErrorExtension::eError);
    ISHIKO_TEST_PASS();
}

void IOErrorExtensionTests::FailTest6(Test& test)
{
    boost::filesystem::path inputPath = test.context().getDataPath("file1.txt");
    std::fstream file(inputPath.c_str());
    char buffer[20];
    file.read(buffer, 20);

    Error error;
    error.extensions().install<IOErrorExtension>();
    IOErrorExtension::Fail(error, file, "file1", 3);

    ISHIKO_TEST_FAIL_IF_NOT(error);
    ISHIKO_TEST_FAIL_IF_NEQ(error.condition().value(), EIO);

    const IOErrorExtension* extension;
    bool found = error.extensions().tryGet(extension);

    ISHIKO_TEST_ABORT_IF_NOT(found);
    ISHIKO_TEST_FAIL_IF_NEQ(extension->code(), IOErrorExtension::eEOF);
    ISHIKO_TEST_PASS();
}

void IOErrorExtensionTests::StreamInsertionTest1(Test& test)
{
    Error error;
    error.extensions().install<IOErrorExtension>();
    IOErrorExtension::Fail(error, IOErrorExtension::eEOF, "file1", 3);

    std::stringstream errorMessage;
    errorMessage << error;

    ISHIKO_TEST_FAIL_IF_NOT(error);
    ISHIKO_TEST_FAIL_IF_NEQ(errorMessage.str(), "Ishiko::IOErrorCategory, 5, I/O error: end-of-file [file: file1, line: 3]");
    ISHIKO_TEST_PASS();
}
