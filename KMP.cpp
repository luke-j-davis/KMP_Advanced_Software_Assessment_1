#include <string>
#include <vector>

std::vector<int> KMP(const std::string& text, const std::string& pattern)
{
    std::vector<int> result;

    if (pattern.empty())
        return result;

    // Build LPS (Longest Prefix Suffix) array
    std::vector<int> lps(pattern.length(), 0);

    int length = 0;

    for (int i = 1; i < pattern.length();)
    {
        if (pattern[i] == pattern[length])
        {
            length++;
            lps[i] = length;
            i++;
        }
        else if (length != 0)
        {
            length = lps[length - 1];
        }
        else
        {
            lps[i] = 0;
            i++;
        }
    }

    // KMP search
    int i = 0; // position in text
    int j = 0; // position in pattern

    while (i < text.length())
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;

            // Found the pattern
            if (j == pattern.length())
            {
                result.push_back(i - j);

                // Continue searching for overlapping matches
                j = lps[j - 1];
            }
        }
        else if (j != 0)
        {
            j = lps[j - 1];
        }
        else
        {
            i++;
        }
    }

    return result;
}