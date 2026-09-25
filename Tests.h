#ifndef TESTS_H
#define TESTS_H

#include <string>
#include <vector>

struct TestCase
{
    std::string name;
    std::string text;
    std::string pattern;
};

std::vector<TestCase> getTestCases();

#endif