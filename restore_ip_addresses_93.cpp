#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> restoreIpAddresses(string s) 
{ 
    vector<string> res_vec;
    int s_size = s.size();
    int n = 3;
    string sub_str1, sub_str2, sub_str3, sub_str4;
    
    for(int x = 1; x <= 3 && x < s_size ; x++)
    {
        if(s_size - x > 3*n)
        {
            continue;
        }

        string sub_str1 = s.substr(0, x);
        int sub = stoi(sub_str1);
        if(sub > 255)
        {
            continue;
        }
        for(int y = x+1; y <= x+3 && y < s_size; y++)
        {
            if(s_size - y > 2*n)
            {
                continue;
            }

            sub_str2 = s.substr(x, y-x);
            sub = stoi(sub_str2);
            if(sub > 255)
            {
                continue;
            }
            for(int z = y+1; z <= y+3 && z < s_size; z++)
            {
                if(s_size - z > n)
                {
                    continue;
                }
                
                sub_str3 = s.substr(y, z-y);
                sub = stoi(sub_str3);
                if(sub > 255)
                {
                    continue;
                }
                
                sub_str4 = s.substr(z);
                sub = stoi(sub_str4);
                if(sub > 255)
                {
                    continue;
                }
                
                string res_str;
                if( x > 1 && s[0] == '0' 
                    || y - x > 1 && s[x] == '0' 
                    || z - y > 1 && s[y] == '0' 
                    || s_size - z > 1 && s[z] =='0')
                {
                    continue;
                }
                
                res_str.append(sub_str1);
                res_str.push_back('.');
                res_str.append(sub_str2);
                res_str.push_back('.');
                res_str.append(sub_str3);
                res_str.push_back('.');
                res_str.append(sub_str4);
                res_vec.push_back(res_str);
            }
        }
    }
    return res_vec;
}

int main()
{
    return 0;
}