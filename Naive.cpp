#include "Naive.h"

std::vector<int> Naive(const std::string& text, const std::string& pattern)
{
    std::vector<int> result;

    if (pattern.empty())
        return result;

    if (pattern.length() > text.length())
        return result;

    for (int count = 0; count <= text.length() - pattern.length(); count++)
    {
        int j = 0;

        while (j < pattern.length() &&
               text[count + j] == pattern[j])
        {
            j++;
        }

        if (j == pattern.length())
        {
            result.push_back(count);
        }
    }

    return result;
}