/*************************************************************************
	> File Name: rotate_image_48.cpp
	> Author: clhongooo
	> Mail: clhongooo@163.com 
	> Created Time: Fri 18 May 2018 09:28:02 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

/**
 * rotate the image by 90 degrees,it looks like i,j -> j, n-i.
 */
void rotate(vector<vector<int>>& matrix)
{
	vector<vector<int>> matrix_backup;
	for(auto iter : matrix)
	{
		matrix_backup.push_back(iter);
	}

	int matrix_size = matrix[0].size();
	for(int i = 0; i < matrix_size; i++)
	{
		for(int j = 0; j < matrix_size; j++)
		{
			matrix[j][matrix_size - 1 - i] = matrix_backup[i][j];
		}
	}
}

int main()
{
	vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
	rotate(matrix);

	return 0;
}
