#include <vector>
#include <iostream>
using namespace std;

/**
 * description: suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * You are given a target value to search. If found in the array return true,otherwise return false.
 * thinking:It's an array sorted in ascending order and rotated at a unknown pivot, we can consider the array 
 * as a sorted array to use the special binary search.When using the binary search, There are 3 points in the
 * array, array[left],array[mid],array[right].According to the array[mid],we can find 2 situations will happen.
 * 1: array[left] array[pivot] array[mid] array[right], (array[mid] array[right]] is an array sorted in ascending order.
 *    If target is found in (array[mid] array[right]], left = mid + 1, otherwise right = mid - 1.
 * 2: array[left] array[mid] array[pivot] array[right], [array[left] array[mid]) is an array sorted in ascending order.
 *    If target is found in [array[left] array[mid]), right = mid - 1, otherwise left = mid + 1.
 */ 

bool search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if(nums[mid] == target){
            return true;
        }else if(nums[mid] < nums[l]){
            if(nums[mid] < target && nums[r] >= target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }else if(nums[mid] > nums[l]){
            if(nums[l] <= target && nums[mid] > target){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }else{
            l++;//filtering the repeated element.
        }
    } 
    return false;
}

#define TEST_RES(x, y) \
    if(x == y) { \
        cout << "test succeed!" << endl; \
    }else{ \
        cout << "test failed!" << endl; \
    }

int main(){
    vector<int> test_vec = {2,5,6,0,0,1,2};
    TEST_RES(search(test_vec, 0), true);
    return 0;
}