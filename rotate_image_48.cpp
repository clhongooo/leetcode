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
	vector<vector<int>> matrix;
	
	vector<int> mem_vec;
	mem_vec.push_back(1);
	mem_vec.push_back(2);
	mem_vec.push_back(3);
	matrix.push_back(mem_vec);
	mem_vec.clear();
	mem_vec.push_back(4);
	mem_vec.push_back(5);
	mem_vec.push_back(6);
	matrix.push_back(mem_vec);
	mem_vec.clear();
	mem_vec.push_back(7);
	mem_vec.push_back(8);
	mem_vec.push_back(9);
	matrix.push_back(mem_vec);

	rotate(matrix);

	return 0;
}
