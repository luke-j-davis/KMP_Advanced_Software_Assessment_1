#include <string>
#include <vector>

std::vector<int> KMP(const std::string& text, const std::string& pattern)
{
    std::vector<int> result;

    if (pattern.empty())
        return result;

    // Build LPS (Longest Prefix Suffix) array
    std::vector<int> lps(pattern.length(), 0);
//current length of the common prefix between start and current point
    int length = 0;

    //start from  as first =0
    for (int current = 1; current < pattern.length();)
    {
        //we are comparing the current value against eachother and if match extend 
        //imagine you have two parts the start and where your at
        if (pattern[current] == pattern[length])
        {
            length++;
            lps[current] = length;
            current++;
        }
        //when mismatch cause of previous if statement 
        else if (length != 0)
        {
            length = lps[length - 1];
        }
        else
        {
            lps[current] = 0;
            current++;
        }
    }

    //if       ABCABCAAB
    //output   000123110


    // KMP search
    int countText = 0; // position in text
    int countPattern = 0; // position in pattern

    while (countText < text.length())
    {
        if (text[countText] == pattern[countPattern ])
        {
            countText++;
            countPattern++;

            // The pattern was found and ended
            if (countPattern == pattern.length())
            {
                result.push_back(countText - countPattern );

                // Continue searching for overlapping matches
                countPattern  = lps[countPattern - 1];

                //word AAA
                //pattern AA

            }
        }
        //mismatch if some charcters were already matched 
        //word:   ABCABCABD
        //pattern ABCABD
        //LPS[4] = 2

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