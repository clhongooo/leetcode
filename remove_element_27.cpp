/*************************************************************************
	> File Name: remove_element_27.cpp
	> Author: clhongooo
	> Mail: clhongooo@163.com 
	> Created Time: Mon 28 May 2018 12:16:18 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int remove_element(vector<int>& nums, int val)
{
	vector<int>::iterator iter = nums.begin();
	for(; iter != nums.end();)
	{
		if(*iter == val)
		{
			iter = nums.erase(iter);
		}
		else
		{
			++iter;
		}
	}
	return nums.size();
}

int main()
{
	vector<int> vec = {3,2,2,3};
	remove_element(vec, 3);
	return 0;
}
