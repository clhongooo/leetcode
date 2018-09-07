#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * \brief   there is a more efficient way by using binary search.
 * \        But I try to use c++11.
 */
int searchInsert(vector<int>& nums, int target) {
    int ele_idx = 0;
    auto seek_element = [&](int ele)->bool{
        if(ele >= target){
            return true;
        }
        ele_idx++;
        return false;
    };
    
    auto iter = find_if(nums.begin(), nums.end(), seek_element);
    if(iter == nums.end()){
        nums.push_back(target);
        return nums.size() - 1;
    }
    
    if(*iter != target){
        nums.insert(iter, target);   
    }
    return ele_idx;
}

#define TEST_RES(x,y) \
    if(x == y){ \
        cout << "test success!" << endl; \
    }else{ \
        cout << "test failed!" << endl; \
    }

int main(){
    vector<int> test_vec = {1,2,5,6};
    TEST_RES(searchInsert(test_vec, 5), 2);
    return 0;
}