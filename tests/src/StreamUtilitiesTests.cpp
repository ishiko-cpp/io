/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/io/blob/main/LICENSE.txt
*/

#include "StreamUtilitiesTests.hpp"
#include "Ishiko/IO/IOErrorCategory.hpp"
#include "Ishiko/IO/StreamUtilities.hpp"
#include <fstream>

using namespace Ishiko;

StreamUtilitiesTests::StreamUtilitiesTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "StreamUtilities tests", context)
{
    append<HeapAllocationErrorsTest>("FailIfCreateFileError test 1", FailIfCreateFileErrorTest1);
    append<HeapAllocationErrorsTest>("FailIfCreateFileError test 2", FailIfCreateFileErrorTest2);
    append<HeapAllocationErrorsTest>("FailIfOpenFileError test 1", FailIfOpenFileErrorTest1);
    append<HeapAllocationErrorsTest>("FailIfOpenFileError test 2", FailIfOpenFileErrorTest2);
}

void StreamUtilitiesTests::FailIfCreateFileErrorTest1(Test& test)
{
    // We try to open the file instead of creating it because this is easier to implement and puts the stream in the
    // same state
    Error error;
    std::fstream file("doesnotexist");

    bool failed = FailIfCreateFileError(error, file);
  
    ISHIKO_TEST_FAIL_IF_NOT(failed);
    ISHIKO_TEST_FAIL_IF_NOT(error);
    ISHIKO_TEST_FAIL_IF_NEQ(error.condition().value(), -2);
    ISHIKO_TEST_FAIL_IF_NEQ(&error.condition().category(), &IOErrorCategory::Get());

    std::string message;
    bool messsageFound = error.tryGetMessage(message);

    ISHIKO_TEST_FAIL_IF(messsageFound);

    const char* originFile = nullptr;
    int originLine = -1;
    bool originFound = error.tryGetOrigin(originFile, originLine);

    ISHIKO_TEST_FAIL_IF(originFound);
    ISHIKO_TEST_PASS();
}

void StreamUtilitiesTests::FailIfCreateFileErrorTest2(Test& test)
{
    const char* path = "doesnotexist";

    // We try to open the file instead of creating it because this is easier to implement and puts the stream in the
    // same state
    Error error;
    error.extensions().install<MessageErrorExtension>();
    std::fstream file(path);

    bool failed = FailIfCreateFileError(error, file, path, "file1", 3);

    ISHIKO_TEST_FAIL_IF_NOT(failed);
    ISHIKO_TEST_FAIL_IF_NOT(error);
    ISHIKO_TEST_FAIL_IF_NEQ(error.condition().value(), -2);
    ISHIKO_TEST_FAIL_IF_NEQ(&error.condition().category(), &IOErrorCategory::Get());

    std::string message;
    bool messsageFound = error.tryGetMessage(message);

    ISHIKO_TEST_FAIL_IF_NOT(messsageFound);
    ISHIKO_TEST_FAIL_IF_NEQ(message, "failed to create file 'doesnotexist'");

    const char* originFile = nullptr;
    int originLine = -1;
    bool origin = error.tryGetOrigin(originFile, originLine);

    ISHIKO_TEST_FAIL_IF_NOT(origin);
    ISHIKO_TEST_FAIL_IF_STR_NEQ(originFile, "file1");
    ISHIKO_TEST_FAIL_IF_NEQ(originLine, 3);
    ISHIKO_TEST_PASS();
}

void StreamUtilitiesTests::FailIfOpenFileErrorTest1(Test& test)
{
    Error error;
    std::fstream file("doesnotexist");

    bool failed = FailIfOpenFileError(error, file);

    ISHIKO_TEST_FAIL_IF_NOT(failed);
    ISHIKO_TEST_FAIL_IF_NOT(error);
    ISHIKO_TEST_FAIL_IF_NEQ(error.condition().value(), -3);
    ISHIKO_TEST_FAIL_IF_NEQ(&error.condition().category(), &IOErrorCategory::Get());

    std::string message;
    bool messsageFound = error.tryGetMessage(message);

    ISHIKO_TEST_FAIL_IF(messsageFound);

    const char* originFile = nullptr;
    int originLine = -1;
    bool originFound = error.tryGetOrigin(originFile, originLine);

    ISHIKO_TEST_FAIL_IF(originFound);
    ISHIKO_TEST_PASS();
}

void StreamUtilitiesTests::FailIfOpenFileErrorTest2(Test& test)
{
    const char* path = "doesnotexist";

    Error error;
    error.extensions().install<MessageErrorExtension>();
    std::fstream file(path);

    bool failed = FailIfOpenFileError(error, file, path, "file1", 3);

    ISHIKO_TEST_FAIL_IF_NOT(failed);
    ISHIKO_TEST_FAIL_IF_NOT(error);
    ISHIKO_TEST_FAIL_IF_NEQ(error.condition().value(), -3);
    ISHIKO_TEST_FAIL_IF_NEQ(&error.condition().category(), &IOErrorCategory::Get());

    std::string message;
    bool messsageFound = error.tryGetMessage(message);

    ISHIKO_TEST_FAIL_IF_NOT(messsageFound);
    ISHIKO_TEST_FAIL_IF_NEQ(message, "failed to open file 'doesnotexist'");

    const char* originFile = nullptr;
    int originLine = -1;
    bool origin = error.tryGetOrigin(originFile, originLine);

    ISHIKO_TEST_FAIL_IF_NOT(origin);
    ISHIKO_TEST_FAIL_IF_STR_NEQ(originFile, "file1");
    ISHIKO_TEST_FAIL_IF_NEQ(originLine, 3);
    ISHIKO_TEST_PASS();
}
