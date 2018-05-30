/*************************************************************************
	> File Name: divide_two_integers_29.cpp
	> Author: clhongooo
	> Mail: clhongooo@163.com 
	> Created Time: Wed 30 May 2018 10:55:48 AM CST
 ************************************************************************/

#include<iostream>
#include<limits.h>
using namespace std;

/**
 * 1:boundary conditions.
 * 2:deal with sign.
 * 3:decrease the complex of the problem.
 */

int divide(int dividend, int divisor)
{
	if(!divisor || (dividend == INT_MIN && divisor == -1))
	{
		return INT_MAX;
	}

	int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
	long long dvd = labs(dividend);
	long long dvs = labs(divisor);
	int res = 0;
	while(dvd >= dvs)
	{
		long long temp = dvs, multiple = 1;
		while(dvd >= (temp << 1))
		{
			temp <<= 1;
			multiple <<= 1;
		}
		dvd -= temp;
		res += multiple;
	}
	return sign == 1 ? res : -res;
}

int main()
{
	cout << divide(10,3);
	return 0;
}
