/*************************************************************************
	> File Name: add_binary_67.cpp
	> Author: clhongooo
	> Mail: clhongooo@163.com 
	> Created Time: 三  6/13 22:45:55 2018
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

/**
 * \notification:
 * \1:range of value.
 * \2:boundary condition.
 */

string addBinary(string a, string b)
{
	int i = a.size(), j = b.size();
	char c_sum = '0';
	string str_res;
	while(i && j)
	{
		int sum = c_sum - '0' + a[--i] - '0' + b[--j] + '0';
		c_sum = sum/2 + '0';
		str_res.push_back(sum%2 + '0');
	}
	while(i)
	{
		int sum = c_sum - '0' + a[--i] - '0';
		c_sum = sum/2 + '0';
		str_res.push_back(sum%2 + '0');
	}
	while(j)
	{
		int sum = c_sum - '0' + b[--j] - '0';
		c_sum = sum/2 + '0';
		str_res.push_back(sum%2 + '0');
	}
	if(c_sum != '0')
	{
		str_res.push_back(c_sum);
	}

	reverse(str_res.begin(), str_res.end());
	
	return str_res;
}

int main()
{
	cout << addBinary("1101","1111100101");
	return 0;
}

