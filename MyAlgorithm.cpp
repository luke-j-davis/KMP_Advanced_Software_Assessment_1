#include <string>
#include <vector>

//need to grab the info
#include "MyAlgorithm.h"

//Ok Im solving for my speed and I lied this is Knuth-Morris-Pratt

std::vector<int> MyAlgorithm(const std::string& str1, const std::string& str2)
{
    //output
    std::vector<int> output;
    
    if(str2.length() <= 1)
    {
        //we first do the 0 but its hidden in here so not a extra if
        if(str2.length() == 0)
        {
            return output;
        }
        else{
            for(int count =0; count < str1.length(); count++)
            {
                if(str1[count] == str2[0])
                {
                    //just pushback  this code breaks on pattern length 1 
                    output.push_back(count);
                }
            }
            return output;
        }
    }





   //So I want as we are finding the pattern

   //remembering a few weeks ago I want to start from every value if need be 
   //but Im trying to do in one loop
   //so two values
   //int countPattern = 0;
    //Ima use a stack //changed to vector
    //we dont need a tuple as we can just - from the current position
    std::vector<int> matches;

    //we will imagine test data as aaaaaaaaaaaa aaaaaa for the idea of there is multiple
   for(int count =0; count < str1.length(); count++)
    {
        //Now if pattern and this equal we say yippy
        if (!matches.empty())
        {
            for (int i = 0; i < matches.size(); i++)
            {   
                if (str1[count] == str2[matches[i]])
                {   
                    matches[i]++;
                    if(matches[i] == str2.length())
                    {
                        output.push_back(count - str2.length() + 1);
                        matches.erase(matches.begin() + i);
                        //as we deleted it we dont want to move it forward technically on the next run
                        i--;
                    }
                    
                    
                }
                else
                {
                    matches.erase(matches.begin() + i);
                    i--;
                }
            }
        }

        //we do this last first we try go through all Do want it to be a tuple so I can record the placement its in
        if(str1[count] == str2[0])
        {
            //just pushback  this code breaks on pattern length 1 
            matches.push_back(1);
        }
        
    }
    return output;
}