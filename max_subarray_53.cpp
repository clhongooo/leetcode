#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums) 
{
    int nums_size = nums.size();
    if(nums_size == 0)
    {
        return 0;
    }
    int max_sum = nums[0], sum = nums[0];
    for(int i = 1; i < nums_size; i++)
    {
        if(sum < 0)
        {
            sum = nums[i];
        }
        else
        {
            sum += nums[i];                
        }
        if(sum > max_sum)
        {
            max_sum = sum;
        }
        else
        {
            if(sum < 0)
            {
                sum = 0;
            }
        }
    }
    return max_sum;
}

int main()
{
    vector<int> vec = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(vec);
    return 0;
}