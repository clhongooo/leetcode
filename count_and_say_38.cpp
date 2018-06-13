#include<iostream>
#include<vector>
#include<string>

using namespace std;

string countAndSay(int n) 
{
    if(n == 0)
    {
        return "";
    }
    vector<string> str_vec;
    str_vec.push_back("1");
    
    for(int i = 1; i < n; i++)
    {
        string str = str_vec[i-1];
        string str_item;
        
        char c = str[0];
        int count = 1;
        for(int j = 0; j < str.size(); j++)
        {
            if(j < str.size() - 1)
            {
                if(str[j] == str[j+1])
                {
                    count += 1;
                }
                else
                {
                    char c_in = '0' + count;
                    str_item.push_back(c_in);
                    str_item.push_back(c);
                    
                    c = str[j+1];
                    count = 1;
                }
            }
            else
            {
                char c_in = '0' + count;
                str_item.push_back(c_in);
                str_item.push_back(c);                   
            }
        }
        str_vec.push_back(str_item);
    }
    return str_vec[n-1];
}

int main()
{
    cout << countAndSay(5);
    return 0;
}