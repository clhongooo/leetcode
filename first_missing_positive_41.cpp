#include <vector>
#include <iostream>
using namespace std;

/**
 * The commented solution has a O(nlog(n)) time complexity, then the next's time complexity is O(n).
 * In fact, for the worst time complexity with a O(C) space complexity, the best time complexity is
 * just O(nlog(n)).So we can not sort all vector in this problem with a O(n) time complexity.Then 
 * there is a important point that is 'v[i] == i' in the positive integer sort.
 */ 

int firstMissingPositive(vector<int>& nums) { 
#if 0
    sort(nums.begin(), nums.end());
    int positive_count = 1;
    int res = 0;
    for(auto i : nums){
        if(i < 1){
            continue;
        }
        
        if(i > positive_count){
            res = positive_count;   
            break;
        }else if(i == positive_count){
            positive_count++;
        }
    }
    if(res == 0){
        res = positive_count;
    }
    return res;
#endif
    int i = 0;
    int sz = nums.size();
    while(i < sz){
        if(nums[i] > 0 && nums[i] < sz && nums[nums[i]-1] != nums[i]){
            swap(nums[nums[i]-1], nums[i]);
        }else{
            i++;
        }
    }
    int res = 1;
    for(auto i : nums){
        if(res != i){
            break;
        }
        res++;
    }
    
    return res;
}

#define TEST_RES(x, y) \
    if(x == y) { \
        cout << "test success!" << endl; \
    }else{ \
        cout << "test failed!" << endl; \
    }

int main(){
    vector<int> test_vec = {1};
    TEST_RES(firstMissingPositive(test_vec), 2);
    return 0;
}