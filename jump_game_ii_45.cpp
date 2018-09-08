#include <vector>
#include <iostream>
using namespace std;

/**
 * The commented method is an inefficient way by analyzing array,then the next is optimilization.
 * To solve the problem, we must analyze the regular pattern of a simple instance about this problem,
 * next to code.
 */

int jump(vector<int>& nums) {
    int sz = (int)nums.size();
    if(sz <= 1){
        return 0;
    } 
    
    int trace = 1, max_val = 0, max_idx = 0, stop_idx = nums[0];
    for(int i = 0; i < sz-1; i++){
        //promise local traverse
        if(i+nums[i] > max_val){
            max_val = i + nums[i];
            max_idx = i;
        }            
        if(i == stop_idx){
            trace++;
            if(max_val >= sz-1){
                break;
            }else{
                i = stop_idx;
                stop_idx = max_val;
                max_idx = 0;
                max_val = 0;
            }
        }
    }
    return trace;

#if 0
    int sz = (int)nums.size();
    if(sz <= 1){
        return 0;
    } 
    
    int res_edge = 0;
    for(int i = 0; i < sz-1;){
        int next_idx = i;
        int next_val = nums[i] + i;
        if(next_val >= sz-1){
            res_edge++;
            break;
        }
        
        res_edge++;

        int cmp_val = next_val;
        for(int j = i; j <= cmp_val; j++){
            if(nums[j] + j > next_val){
                next_idx = j;
                next_val = nums[j] + j;
            }
        }
        
        i = next_idx;
    }
    return res_edge;
#endif
}

#define TEST_RES(x,y) \
    if(x == y) { \
        cout << "test succeed!" << endl; \
    }else{ \
        cout << "test failed!" << endl; \
    }

int main(){
    vector<int> test_vec = {1,1,1,1};
    TEST_RES(jump(test_vec), 3);
    return 0;
}