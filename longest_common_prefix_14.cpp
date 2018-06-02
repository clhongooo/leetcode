#include<iostream>
#include<vector>
#include<string>

using namespace std;

string longestCommonPrefix(vector<string>& strs) 
{
    if(strs.size() == 0)
    {
        return "";
    }
    
    string str_result = strs[0];
    int result_len = 0;
    for(int i = 0; i < str_result.size(); i++)
    {
        bool is_break = false;
        
        for(auto str : strs)
        {
            if(i < str.size() && str[i] == str_result[i])
            {
                continue;
            }
            else
            {
                is_break = true;
                break;
            }
        }
        if(is_break)
        {
            break;
        }
        
        result_len += 1;
    }
    
    return str_result.substr(0, result_len);
}

int main()
{
    vector<string> str_vec = {"a"};
    cout << longestCommonPrefix(str_vec);
    return 0;
}