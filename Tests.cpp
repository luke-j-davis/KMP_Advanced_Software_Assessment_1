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

    tests.push_back({
        "Long repeated a",
        std::string(1000, 'a'),
        "aaaaaaaaaa"
    });

    tests.push_back({
        "Long repeated ab",
        "abababababababababababababababababababababababababababababababababababababababababababababababababab",
        "ababababab"
    });

    tests.push_back({
        "Long no match",
        std::string(1000, 'a'),
        "aaaaaaaaab"
    });

    tests.push_back({
        "Long text with match at end",
        std::string(999, 'a') + "b",
        "aaaaab"
    });

    tests.push_back({
        "Long text with match at beginning",
        "abcdef" + std::string(994, 'x'),
        "abcdef"
    });

    tests.push_back({
        "Long pattern",
        std::string(1000, 'a'),
        std::string(500, 'a')
    });

    tests.push_back({
        "Long pattern no match",
        std::string(1000, 'a'),
        std::string(499, 'a') + "b"
    });

    tests.push_back({
        "Repeated pattern with many matches",
        std::string(1000, 'a'),
        "aaa"
    });

    tests.push_back({
        "Large mixed text",
        "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz",
        "mnopqrstuv"
    });

        tests.push_back({
        "Empty text",
        "",
        "abc"
    });

    tests.push_back({
        "Both empty",
        "",
        ""
    });

    tests.push_back({
        "Single character text",
        "a",
        "a"
    });

    tests.push_back({
        "Single character no match",
        "a",
        "b"
    });

    tests.push_back({
        "Pattern longer by one",
        "abc",
        "abcd"
    });

    tests.push_back({
        "Pattern longer by many",
        "abc",
        "abcdefghij"
    });

    tests.push_back({
        "Pattern one character longer",
        "aaaa",
        "aaaaa"
    });

    tests.push_back({
        "Match occurs twice",
        "abcabc",
        "abc"
    });

    tests.push_back({
        "Match occurs three times",
        "abcabcabc",
        "abc"
    });

    tests.push_back({
        "Overlapping by one character",
        "aaaa",
        "aaa"
    });

    tests.push_back({
        "Highly overlapping",
        "aaaaaaaaaa",
        "aaaaa"
    });

    tests.push_back({
        "Pattern overlaps with itself",
        "abababa",
        "ababa"
    });

    tests.push_back({
        "Repeated characters",
        "aaabaaaabaaa",
        "aaa"
    });

    tests.push_back({
        "Mismatch at first character",
        "xxxxxxxxxx",
        "abc"
    });

    tests.push_back({
        "Mismatch at last character",
        "aaaaab",
        "aaaaac"
    });

    tests.push_back({
        "Almost complete match",
        "abcdefghij",
        "abcdefghiX"
    });

    tests.push_back({
        "Match surrounded by same character",
        "xabcx",
        "abc"
    });

    tests.push_back({
        "Match at very beginning",
        "abcxxxxxxxxxx",
        "abc"
    });

    tests.push_back({
        "Match at very end",
        "xxxxxxxxxxabc",
        "abc"
    });

    tests.push_back({
        "Only match",
        "abc",
        "abc"
    });

    tests.push_back({
        "Pattern repeated directly",
        "abcabcabcabc",
        "abcabc"
    });

    tests.push_back({
        "Pattern almost repeated",
        "abcabcabdabc",
        "abcabc"
    });

    tests.push_back({
        "Case sensitive",
        "Hello HELLO hello",
        "hello"
    });

    tests.push_back({
        "Spaces",
        "hello world hello world",
        "world"
    });

    tests.push_back({
        "Pattern contains spaces",
        "hello world hello",
        "hello world"
    });

    tests.push_back({
        "Special characters",
        "!@#$%^&*()!@#$",
        "!@#"
    });

    tests.push_back({
        "Numbers",
        "123451234512345",
        "12345"
    });

    tests.push_back({
        "Pattern is one character from full text",
        "abcdef",
        "e"
    });

    tests.push_back({
        "Pattern equals repeated text",
        "aaaaaaaa",
        "aaaaaaaa"
    });

    tests.push_back({
        "One character difference",
        "aaaaabaaaaa",
        "aaaaaaaaaa"
    });

    tests.push_back({
        "Alternating characters",
        "abababababababab",
        "babab"
    });

    tests.push_back({
        "No match after long partial match",
        "aaaaaaaaaaaaaaaaab",
        "aaaaaaaaaac"
    });
        // 10,000 characters
    tests.push_back({
        "10K - repeated a",
        std::string(10000, 'a'),
        "aaaaaaaaaa"
    });

    tests.push_back({
        "10K - difficult mismatch",
        std::string(9999, 'a') + "b",
        "aaaaaaaaab"
    });


    // 100,000 characters
    tests.push_back({
        "100K - repeated a",
        std::string(100000, 'a'),
        "aaaaaaaaaa"
    });

    tests.push_back({
        "100K - difficult mismatch",
        std::string(99999, 'a') + "b",
        "aaaaaaaaab"
    });


    // 500,000 characters
    tests.push_back({
        "500K - repeated a",
        std::string(500000, 'a'),
        "aaaaaaaaaa"
    });

    tests.push_back({
        "500K - difficult mismatch",
        std::string(499999, 'a') + "b",
        "aaaaaaaaab"
    });


    // 1,000,000 characters
    tests.push_back({
        "1M - repeated a",
        std::string(1000000, 'a'),
        "aaaaaaaaaa"
    });

    tests.push_back({
        "1M - difficult mismatch",
        std::string(999999, 'a') + "b",
        "aaaaaaaaab"
    });


    // 5,000,000 characters
    tests.push_back({
        "5M - repeated a",
        std::string(5000000, 'a'),
        "aaaaaaaaaa"
    });

    tests.push_back({
        "5M - difficult mismatch",
        std::string(4999999, 'a') + "b",
        "aaaaaaaaab"
    });

    return tests;
}