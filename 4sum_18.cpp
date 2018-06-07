#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    vector<vector<int>> result_vec;
    int nums_size = nums.size();
    if(nums_size < 4)
    {
        return result_vec;
    }

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums_size - 3; i++)
    {
        if(i > 0 && nums[i] == nums[i-1])
        {
            continue;
        }
        if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target)
        {
            break;
        }
        if(nums[i] + nums[nums_size-3] + nums[nums_size-2] + nums[nums_size-3] < target)
        {
            continue;
        }
        for(int j = i+1; j < nums_size-2; j++)
        {
            if(j > i+1 && nums[j] == nums[j-1])
            {
                continue;
            }
            if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target)
            {
                break;
            }
            if(nums[i] + nums[j] + nums[nums_size-2] + nums[nums_size-1] < target)
            {
                continue;
            }
            int left = j+1, right = nums_size-1;
            while(left < right)
            {
                int sum = nums[left] + nums[right] + nums[i] + nums[j];
                if(sum < target)
                {
                    left += 1;
                }
                else if(sum > target)
                {
                    right -= 1;
                }
                else
                {
                    vector<int> item_vec = {nums[i], nums[j], nums[left], nums[right]};
                    result_vec.push_back(item_vec);
                    do{
                        left++;
                    }while(nums[left] == nums[left-1] && left < right);
                    do{
                        right--;
                    } while(nums[right] == nums[right+1] && left < right);
                }
            }
        }
    }
    return result_vec;
}

int main()
{
    vector<int> vec = {1,0,-1,0,-2,2};
    fourSum(vec, 0);
    return 0;
}