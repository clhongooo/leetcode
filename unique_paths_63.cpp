#include<iostream>
#include<vector>

using namespace std;

/**
 * boundary conditions!!!
 */

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    int row = obstacleGrid.size();
    int column = obstacleGrid[0].size();
    
    if(obstacleGrid[0][0] == 1)
    {
        return 0;
    }
    
    vector<vector<int>> result_vec;
    for(int i = 0; i < row; i++)
    {
        result_vec.push_back(vector<int>(column, 0));
    }
    
    result_vec[0][0] = 1;
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            if(i == 0 && j == 0)
            {
                continue;
            }
            if(obstacleGrid[i][j] == 1)
            {
                result_vec[i][j] = 0;
            }
            else if(i == 0)
            {
                result_vec[i][j] = result_vec[i][j-1];
            }
            else if(j == 0)
            {
                result_vec[i][j] = result_vec[i-1][j];
            }
            else
            {
                result_vec[i][j] = (1 - obstacleGrid[i][j-1])*result_vec[i][j-1];
                result_vec[i][j] += (1 - obstacleGrid[i-1][j])*result_vec[i-1][j];   
            }
        }
    }
    return result_vec[row - 1][column - 1];   
}

int main()
{
    vector<vector<int>> vec = {{1}};
    cout << uniquePathsWithObstacles(vec);
    return 0;
}