#include <vector>
#include <iostream>
using namespace std;

/**
 * description: Given n non-negative integers representing the histogram's bar height where the width of 
 * each bar is 1, find the area of largest rectangle in the histogram.
 * thinking:maintain a increasing stack that contains the index of the bar.traversing the histogram's bar,
 * when the current bar's height is higher than the top of the stack,we can insert the bar's index into stack.
 * Otherwise we should remove the bar's index from stack cyclically until that is lower than current bar's height.
 * Of course, When we remove the index from stack, we can calculate area where the width is from i to that index. 
 */

int largestRectangleArea(vector<int>& heights) {
    int ret = 0;
    heights.push_back(0);
    int sz = heights.size();
    vector<int> stack;
    for(int i = 0; i < sz; i++){
        while(stack.size() > 0 && heights[stack.back()] >= heights[i]){
            int h = heights[stack.back()];
            stack.pop_back();
            int sidx = stack.size() ? stack.back() : -1;
            if(ret < h*(i-sidx-1)){
                ret = h*(i-sidx-1);
            }
        }
        stack.push_back(i);
    }
    return ret;
}

#define TEST_RES(x, y) \
    if(x == y){ \
        cout << "test succeed!"; \
    }else{ \
        cout << "test failed!"; \
    }

int main(){
    vector<int> test_vec = {2,1,2,3,1,2,3,1,2,3,1,2,3};
    TEST_RES(largestRectangleArea(test_vec), 13);
    return 0;
}