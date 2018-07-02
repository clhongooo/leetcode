#include<iostream>
using namespace std;

int mySqrt(int x) 
{
    int low = 1, top = x, mid = 0;
    while(low < top)
    {
        mid = low + (top - low)/2;
        if(mid > x/mid)
        {
            top = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    
    return low > x/low ? low-1 : low;
}

int main()
{
    cout << mySqrt(4);
    return 0;
}