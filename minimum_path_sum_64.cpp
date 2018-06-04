#include<iostream>
#include<vector>

using namespace std;

int minPathSum(vector<vector<int>>& grid) 
{
    int row = grid.size();
    int column = grid[0].size();
    
    vector<vector<int>> dp;
    for(int i = 0; i < row; i++)
    {
        dp.push_back(vector<int>(column, 0));
    }
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            if(i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
            }
            else if(i == 0)
            {
                dp[i][j] = dp[i][j-1] + grid[i][j];
            }
            else if(j == 0)
            {
                dp[i][j] = dp[i-1][j] + grid[i][j];
            }
            else
            {
                dp[i][j] = min(dp[i-1][j] + grid[i][j], dp[i][j-1] + grid[i][j]);
            }
        }
    }
    
    return dp[row-1][column-1];
}

int main()
{
    vector<vector<int>> vec = {{1,3,1},{1,5,1},{4,2,1};
    cout << minPathSum(vec);
    return 0;
}