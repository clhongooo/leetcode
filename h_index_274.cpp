#include<iostream>
#include<vector>

using namespace std;

int hIndex(vector<int>& citations) 
{
    sort(citations.begin(), citations.end(), std::greater<>());
    int ci_size = citations.size();
    int result = 0;
    for(int i = 0; i < ci_size; i++)
    {
        int val = min(citations[i], i+1);
        if(result < val)
        {
            result = val;
        }
    }
    return result;
}

int main()
{
    vector<int> vec = {3,0,6,1,5};
    cout << hIndex(vec);
    return 0;
}