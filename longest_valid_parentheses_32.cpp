#include<iostream>
#include<string>
#include<stack>

using namespace std;

int longestValidParentheses(string s)
{
    int size = s.size();
        
    stack<int> stk;
    stk.push(-1);
        
    int result = 0;
        
    for(int i = 0; i < size; i++)
    {
        if(s[i] == '(')
        {
            stk.push(i);
        }
        else
        {
            stk.pop();
            if(!stk.empty())
            {
                result = max(result, i - stk.top());
            }
            else
            {
                stk.push(i);
            }
        }
    } 
    return result;
}

int main()
{
    cout << longestValidParentheses("((())()(");
    return 0;
}