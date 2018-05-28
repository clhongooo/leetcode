/*************************************************************************
	> File Name: strstr_28.cpp
	> Author: clhongooo
	> Mail: clhongooo@163.com 
	> Created Time: Mon 28 May 2018 02:46:23 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int strstr(string haystack, string needle)
{
	if(needle.size() == 0)
	{
		return 0;
	}

	int j = 0, idx = -1, match_idx = 0;
	for(int i = 0; i < haystack.size() && j < needle.size();)
	{
		if(haystack[i] == needle[j])
		{
			if(match_idx == idx)
			{
				match_idx = i;
			}
			if(j == 0)
			{
				idx = i;
				match_idx = i;
			}
			j++;
			i++;
		}
		else
		{
			if(j)
			{
				j = 0;
				if(match_idx != idx)
				{
					i = match_idx;
				}
				else
				{
					i = idx + 1;
				}
				idx = -1;
			}
			else
			{
				i++;
			}
		}
	}

	return j == needle.size() ? idx : -1;
}

int main()
{
	cout << strstr("mississippi", "issip");
	return 0;
}
