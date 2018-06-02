#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) 
{
    set<vector<int>> result_set;
    
    set<int> sets;
    int size = nums.size();
    unordered_map<int, int> map;
    
    sort(nums.begin(), nums.end());
    
    for(int i = 0; i < size; i++)
    {
        if(sets.find(nums[i]) != sets.end())
        {
            continue;
        }
        sets.insert(nums[i]);
        int sum = -nums[i];
        
        map.clear();
        for(int j = i + 1; j < size; j++)
        {
            auto p = map.find(sum - nums[j]);
            if (p!=map.end()) 
            {
                vector<int> item_vec = {nums[i], nums[p->second], nums[j]};
                sort(item_vec.begin(), item_vec.end());
                result_set.insert(item_vec);
            }
            else
            {
                map[nums[j]] = j;   
            }
        }
    }
    
    vector<vector<int>> result_vec;
    for(set<vector<int>>::iterator iter = result_set.begin(); iter != result_set.end(); ++iter)
    {
        result_vec.push_back(*iter);
    }
    
    return result_vec;
}

int main()
{
    threeSum({-1,0,1,2,-1,-4});
    return 0;
}