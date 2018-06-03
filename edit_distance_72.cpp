#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

/**
 * state: array[i][j] the minimum number of operations required to convert the i chars in front of word1 to the j chars in front of word2.
 * state transfer function:if(word1[i] == word2[j])
 *                              array[i][j] = array[i-1][j-1]
 *                          else 
 *                              array[i][j] = min(array[i-1][j] + 1, array[i][j-1] + 1, array[i-1][j-1] + 1)
 *                                  array[i-1][j] + 1: delete word1[i]
 *                                  array[i][j-1] + 1: insert word2[j] 
 *                                  array[i-1][j-1] + 1:replace word1[i] by word2[j]
 */

int minDistance(string word1, string word2) 
{
    int len1 = word1.size();
    int len2 = word2.size();
    if(len1 == 0)
    {
        return len2;
    }
    if(len2 == 0)
    {
        return len1;
    }
    int array[len1+1][len2+1];
    for(int i = 0; i <= len1; i++)
    {
        array[i][0] = i;
    }
    for(int j = 0; j <= len2; j++)
    {
        array[0][j] = j;
    }
    for(int i = 1; i <= len1; i++)
    {
        for(int j = 1; j <= len2; j++)
        {
            if(word1[i-1] == word2[j-1])
            {
                array[i][j] = array[i-1][j-1];
            }
            else
            {
                int val = min(array[i-1][j] + 1, array[i][j-1] + 1);
                array[i][j] = min(array[i-1][j-1] + 1, val);
            }
        }
    }
    return array[len1][len2];
}

int main()
{
    cout << minDistance("11","12");
    return 0;
}