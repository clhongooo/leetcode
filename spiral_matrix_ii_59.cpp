#include<vector>
#include<iostream>
using namespace std;

/**
 * we can use std::move to generate rvalue of res_vec.It can be more efficient.
 */
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res_vec;
    res_vec.resize(n);
    for (int i = 0; i < n; i++) {
        res_vec[i].resize(n);
    }

    if(n == 1){
        res_vec[0][0] = 1;
    }
        
    int count = 1;
    for (int i = 0; i < n - 1; i++) {
        //top sort
        for (int s = i; s < n - i; s++) {
            res_vec[i][s] = count++;
            if (count > n * n) {
                return move(res_vec);
            }
        }
        //right sort
        for (int t = i + 1; t < n - i; t++) {
            res_vec[t][n - i - 1] = count++;
            if (count > n * n) {
                return move(res_vec);
            }
        }
        //bottom sort
        for (int p = n - i - 2; p >= i; p--) {
            res_vec[n - i - 1][p] = count++;
            if (count > n * n) {
                return move(res_vec);
            }
        }
        //left sort
        for (int q = n - i - 2; q >= i + 1; q--) {
            res_vec[q][i] = count++;
            if (count > n * n) {
                return move(res_vec);
            }
        }
    }

    return move(res_vec);
}

int main(){
    generateMatrix(5);
    return 0;
}
