#include<iostream>
#include<vector>
#include<unorder_map>

using namespace std;

/**
 * map keep their elements ordered,if give up that, we can use unordered_map.
 */

vector<string> findRepeatedDnaSequences(string s) 
{
    int size = s.size();
    vector<string> result_vec;
    if(size <= 10)
    {
        return result_vec;
    }
    
    unordered_map<string, int> str_map;
    for(int i = 0; i <= size - 10; i++)
    {
        string sub_str = s.substr(i, 10);
        unordered_map<string, int>::iterator iter = str_map.find(sub_str);
        if(iter != str_map.end())
        {
            iter->second += 1;
            if(iter->second == 2)
            {
                result_vec.push_back(sub_str);    
            }
        }
        else
        {
            str_map[sub_str] = 1;
        }
    }
    
    return result_vec;
}

int main()
{
    cout << findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    return 0;
}