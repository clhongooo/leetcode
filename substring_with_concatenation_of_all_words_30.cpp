/*************************************************************************
	> File Name: substring_with_concatenation_of_all_words_30.cpp
	> Author: clhongooo
	> Mail: clhongooo@163.com 
	> Created Time: 二  6/12 22:30:09 2018
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

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
