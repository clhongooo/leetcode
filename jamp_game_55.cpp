#include <vector>
#include <iostream>
using namespace std;

bool CanJamp(vector<int>& nums){
    int sz = (int)nums.size();
    if(sz <= 1){
        return true;
    }
    
    int max_val = 0;        
    bool result = false;
    for(int i = 0; i < sz - 1; i++){
        if(i + nums[i] > max_val){
            max_val = i + nums[i];              
        }
        if(max_val >= sz - 1){
            result = true;
            break;
        }else if(max_val < i + 1){
            break;
        }  
    }
    
    return result;    
}

#define TEST_RES(x,y) \
    if(x == y) { \
        cout << "test succeed!" << endl; \
    }else{ \
        cout << "test failed!" << endl; \
    }

int main(){
    vector<int> test_vec = {2,3,1,0,4};
    TEST_RES(CanJamp(test_vec), false);
    return 0;
}