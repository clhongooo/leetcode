#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;


map<char, vector<string>> digits_map = {
    {'1', {""}},
    {'2', {"a","b","c"}},
    {'3', {"d","e","f"}},
    {'4', {"g","h","i"}},
    {'5', {"j","k","l"}},
    {'6', {"m","n","o"}},
    {'7', {"p","q","r","s"}},
    {'8', {"t", "u", "v"}},
    {'9', {"w","x","y","z"}}
};
    
vector<string> letterCombinations(string digits) 
{
    vector<string> str_vec = {""};
    
    for(int i = 0; i < digits.size(); i++)
    {
        map<char, vector<string>>::iterator iter = digits_map.find(digits[i]);
        vector<string> tmp_vec;
        for(auto p : iter->second)
        {
            for(auto q : str_vec)
            {
                tmp_vec.push_back(q + p);
            }
        }
        str_vec = tmp_vec;
    }
    
    return str_vec;
}

int main()
{
    letterCombinations("23");
    return 0;
}