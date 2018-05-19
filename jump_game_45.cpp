/*************************************************************************
	> File Name: jump_game_45.cpp
	> Author: clhongooo
	> Mail: clhongooo@163.com 
	> Created Time: Fri 18 May 2018 06:23:08 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

/**
 * divide and conquer,but time limit exceeded.
 */

int jump(vector<int>& nums)
{
	if(nums.size() <= 1)
	{
		return 0;
	}

	if(nums[0] >= nums.size() - 1)
	{
		return 1;
	}

	vector<int> step_vec;
	for(int i = 1; i <= nums[0]; i++)
	{
		vector<int> vec(nums.begin() + i, nums.end());
		if(vec[0] >= vec.size() - 1)
		{
			step_vec.push_back(1);
			break;
		}
		else if(vec[0] == 0)
		{
			continue;
		}
		else
		{
			step_vec.push_back(jump(vec));
		}
	}

	if(step_vec.size() >= 1)
	{
		int min_value = step_vec[0];
		for(int i = 0; i < step_vec.size(); i++)
		{
			if(min_value > step_vec[i])
			{
				min_value = step_vec[i];
			}
		}
		return min_value + 1;
	}

	return 9999;
}

int main()
{
	vector<int> test_vec;
	test_vec.push_back(5);
	test_vec.push_back(9);
	test_vec.push_back(3);
	test_vec.push_back(2);
	test_vec.push_back(1);
	test_vec.push_back(0);
	test_vec.push_back(2);
	test_vec.push_back(3);
	test_vec.push_back(3);
	test_vec.push_back(1);
	test_vec.push_back(0);
	test_vec.push_back(0);
	cout << jump(test_vec);
	return 0;
}
