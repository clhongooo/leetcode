#include <vector>
#include <iostream>
using namespace std;

int firstMissingPositive(vector<int>& nums) { 
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