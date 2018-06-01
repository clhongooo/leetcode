/*************************************************************************
	> File Name: permutations_46.cpp
	> Author: clhongooo
	> Mail: clhongooo@163.com 
	> Created Time: Fri 18 May 2018 12:10:53 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

/**
 * divide and conquer.
 * the features of divide-and-conquer:
 * 1: the smaller scale of problem, easier to solve it.
 * 2: we can divite the big problem to smaller ones.
 * 3: the smaller ones's result can make up of the big's result.
 * 4: the smaller ones are self-reliant.
 */

vector<vector<int>> permute(vector<int>& nums)
{
	vector<vector<int>> result_vec;
	if(nums.size() == 1)
	{
		vector<int> vec;
		vec.push_back(nums[0]);
		result_vec.push_back(vec);
		return result_vec;
	}

	for(int i = 0; i < nums.size(); i++)
	{
		vector<int> mem_vec;
		vector<int> tmp_vec(nums.begin(), nums.end());
		mem_vec.push_back(nums[i]);
		tmp_vec.erase(tmp_vec.begin() + i);

		vector<vector<int>> tmp_result_vec = permute(tmp_vec);
		for(auto vec : tmp_result_vec)
		{
			vec.insert(vec.begin(), nums[i]);
			result_vec.push_back(vec);
		}
	}
	return result_vec;
}

int main()
{
	vector<int> nums = {1,2,3};
	permute(nums);
	return 0;
}
