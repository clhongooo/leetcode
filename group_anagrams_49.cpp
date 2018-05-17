/*************************************************************************
	> File Name: group_anagrams_49.cpp
	> Author: clhongooo
	> Mail: clhongooo@163.com 
	> Created Time: Thu 17 May 2018 07:20:39 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

/**
 * by sorting the member of strs, we can group anagrams together.
 */
vector<vector<string>> group_anagrams(vector<string>& strs)
{
	map<string, vector<string>> result_map;
	int strs_size = strs.size();
	
	for(int i = 0; i < strs_size; i++)
	{
		string str = strs[i];
		sort(str.begin(), str.end());
		map<string, vector<string>>::iterator iter = result_map.find(str);
		if(iter != result_map.end())
		{
			vector<string>& str_vec = iter->second;
			str_vec.push_back(strs[i]);
		}
		else
		{
			vector<string> str_vec;
			str_vec.push_back(strs[i]);
			result_map[str] = str_vec;
		}
	}

	vector<vector<string>> result_vec;
	for(auto iter : result_map)
	{
		result_vec.push_back(iter.second);
	}
	
	return result_vec;
}

int main()
{
	vector<string> input_vec;
	vector<vector<string>> output_vec;

	input_vec.push_back("eat");
	input_vec.push_back("tea");
	input_vec.push_back("tan");
	input_vec.push_back("ate");
	input_vec.push_back("nat");
	input_vec.push_back("bat");
	
	output_vec = group_anagrams(input_vec);
	for(auto iter : output_vec)
	{
		for(auto in_iter : iter)
		{
			cout << in_iter << " ";
		}
		cout << endl;
	}
	return 0;
}
