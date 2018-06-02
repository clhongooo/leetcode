#include"stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target)
{
	sort(nums.begin(), nums.end());

	int nums_size = nums.size();
	int most_suit = nums[0] + nums[1] + nums[nums_size - 1];
	for (int i = 0; i < nums_size; i++)
	{
		int fore = i + 1;
		int rear = nums_size - 1;
		while (fore < rear)
		{
			int sum = nums[i] + nums[fore] + nums[rear];
			if (abs(sum - target) <= abs(most_suit - target))
			{
				most_suit = sum;
				if (sum < target)
				{
					fore++;
				}
				else if (sum == target)
				{
					return sum;
				}
				else
				{
					rear--;
				}
			}
			else
			{
				if (sum < most_suit)
				{
					fore++;
				}
				else
				{
					rear--;
				}
			}
		}
	}
	return most_suit;
}

int main()
{
	vector<int> vec = { 0,2,1,-3 };
	cout << threeSumClosest(vec, 1);
	return 0;
}