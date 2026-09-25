#include "Tests.h"

std::vector<TestCase> getTestCases()
{
    std::vector<TestCase> tests;

    tests.push_back({
        "Basic match",
        "hello world",
        "world"
    });

    tests.push_back({
        "No match",
        "hello world",
        "xyz"
    });

    tests.push_back({
        "Match at beginning",
        "abcdef",
        "abc"
    });

    tests.push_back({
        "Match at end",
        "abcdef",
        "def"
    });

    tests.push_back({
        "Pattern equals text",
        "hello",
        "hello"
    });

    tests.push_back({
        "Overlapping matches",
        "aaaaa",
        "aaa"
    });

    tests.push_back({
        "Repeated pattern",
        "abababab",
        "abab"
    });

    tests.push_back({
        "Single character",
        "abracadabra",
        "a"
    });

    tests.push_back({
        "Pattern longer than text",
        "abc",
        "abcdef"
    });

    tests.push_back({
        "Empty pattern",
        "hello",
        ""
    });

    return tests;
}