#include <vector>
#include <iostream>
using namespace std;

/**
 * description:Given a set of distinct integers, nums, return all possible subsets(the power set).
 * thinking:bit manipulation.Each element of the array can be considered as a bit that represents
 * whether the element is exist in the subset or not.The number of all subsets is 2^n and every integer
 * of [0 2^n] can be considered as a special bit sequence.
 */

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res_vec;
    int sz = (int)nums.size();
    int count = pow(2, sz);
    for(int i = 0; i < count; i++){
        vector<int> vec;
        for(int j = 0; j < sz; j++){
            if(i & 1 << j){
                vec.push_back(nums[j]);
            }
        }
        res_vec.push_back(vec);
    }
    return move(res_vec);
}

int main(){
    vector<int> test_vec = {1,2,3};
    subsets(test_vec);
    return 0;
}