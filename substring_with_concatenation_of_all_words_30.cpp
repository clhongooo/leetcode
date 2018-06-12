/*************************************************************************
	> File Name: substring_with_concatenation_of_all_words_30.cpp
	> Author: clhongooo
	> Mail: clhongooo@163.com 
	> Created Time: 二  6/12 22:30:09 2018
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

#if 0
vector<int> findSubstring(string s, vector<string>& words)
{
	vector<int> result_vec;

	if(words.size() == 0)
	{
		return result_vec;
	}

	int words_len = 0;
	for(auto item : words)
	{
		words_len += item.size();
	}
	int word_len = words_len / words.size();

	sort(words.begin(), words.end());

	int str_len = s.size();
	for(int i = 0; i < str_len-words_len; i++)
	{
		vector<string> vec;
		string sub_str = s.substr(i, words_len);
		for(int j = 0; j < words_len; j += word_len)
		{
			vec.push_back(sub_str.substr(j, word_len));
		}
		sort(vec.begin(), vec.end());
		if(words == vec)
		{
			result_vec.push_back(i);
		}
	}
	
	return result_vec;
}

#endif

vector<int> findSubstring(string s, vector<string>& words)
{
	vector<int> result_vec;

	if(words.size() == 0)
	{
		return result_vec;
	}

	int words_len = 0;
	for(auto item : words)
	{
		words_len += item.size();
	}
	int word_len = words_len / words.size();

	unordered_map<string, int> str_map;
	for(auto item : words)
	{
		if(str_map.count(item))
		{
			str_map[item] += 1;
		}
		else
		{
			str_map[item] = 1;
		}
	}

	int str_len = s.size();
	for(int i = 0; i < str_len-words_len; i++)
	{
		vector<string> vec;
		string sub_str = s.substr(i, words_len);
		unordered_map<string, int> str_map1 = str_map;
		for(int j = 0; j < words_len; j += word_len)
		{
			unordered_map<string, int>::iterator iter = str_map1.find(sub_str.substr(j, word_len));
			if(iter != str_map1.end())
			{
				iter->second -= 1;
				if(iter->second == 0)
				{
					str_map1.erase(iter);
				}
			}
			else
			{
				break;
			}
		}
		if(str_map1.size() == 0)
		{
			result_vec.push_back(i);
		}
	}
	
	return result_vec;
}

int main()
{
	vector<string> words;
	words.push_back("word");
	words.push_back("good");
	words.push_back("best");
	words.push_back("good");
	findSubstring("wordgoodgoodgoodbestword", words);
	return 0;
}
