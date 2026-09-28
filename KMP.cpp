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

    //start from  as first =0
    for (int i = 1; i < pattern.length();)
    {
        //
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
    int countText = 0; // position in text
    int countPattern = 0; // position in pattern

    while (countText < text.length())
    {
        if (text[countText] == pattern[countPattern ])
        {
            countText++;
            countPattern++;

            // Found the pattern
            if (j == pattern.length())
            {
                result.push_back(countText - countPattern );

                // Continue searching for overlapping matches
                countPattern  = lps[countPattern - 1];
            }
        }
        else if (countPattern  != 0)
        {
            countPattern  = lps[countPattern  - 1];
        }
        else
        {
            countText++;
        }
    }

    return result;
}