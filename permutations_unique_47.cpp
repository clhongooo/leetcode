/*************************************************************************
	> File Name: permutations_unique_47.cpp
	> Author: clhongooo
	> Mail: clhongooo@163.com 
	> Created Time: Fri 18 May 2018 04:18:24 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> permute_unique(vector<int>& nums)
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

		vector<vector<int>> tmp_result_vec = permute_unique(tmp_vec);
		for(auto vec : tmp_result_vec)
		{
			vec.insert(vec.begin(), nums[i]);
			
			bool is_exist = false;
			for(auto vec_item : result_vec)
			{
				if(vec_item == vec)
				{
					is_exist = true;
					break;
				}
			}
			if(is_exist == false)
			{
				result_vec.push_back(vec);
			}
		}
	}
	return result_vec;
}

int main()
{
	vector<int> nums = {1,2,3};
	permute_unique(nums);
	
	return 0;
}
