/*************************************************************************
	> File Name: scramble_string_87.cpp
	> Author: clhongooo
	> Mail: clhongooo@163.com 
	> Created Time: 日  6/10 18:23:36 2018
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

bool IsScramble(string s1, string s2)
{
	if(s1.empty() || s2.empty())
	{
		return false;
	}
	if(s1.size() != s2.size())
	{
		return false;
	}
	
	int str_len = s1.size();
	bool result[str_len][str_len][str_len+1];
	for(int sub_len = 1; sub_len <= str_len; sub_len++)
	{
		for(int i = 0; i <= str_len-sub_len; i++)
		{
			for(int j = 0; j <= str_len-sub_len; j++)
			{
				if(sub_len == 1)
				{
					result[i][j][sub_len] = s1[i] == s2[j];
					continue;
				}
				result[i][j][sub_len] = false;
				for(int k = 1; k < sub_len; k++)
				{
					if(result[i][j][k] && result[i+k][j+k][sub_len-k]
					  || result[i][j+sub_len-k][k] && result[i+k][j][sub_len-k])
					{
						result[i][j][sub_len] = true;
						break;
					}
				}
			}
		}
	}
	return result[0][0][str_len];
}

int main()
{
	cout << IsScramble("great", "rgeat");
	return 0;
}
