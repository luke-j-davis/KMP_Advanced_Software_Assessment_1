
#include <map>
#include <numeric>
#include <tuple>

//Ok Im solving for my speed and I lied this is Knuth-Morris-Pratt

String FindingDiff(String str1, String str2)
{
    //So I want to have a integer count of the two strings when going through
    int count = 0;
    int count2 = 0;

    while (str1.length() > 0 && str2.length() > 0)
    {
        if (str1[count] == str2[count2])
        {
            //we just move on
            count ++;
            count2++;
            break;
        }
        //this will be the as diff was found we loop till we find another pattern 
        else if ()
    }

}